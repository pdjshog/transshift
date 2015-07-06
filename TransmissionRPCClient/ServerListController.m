//
//  ServerListController.m
//  TransmissionRPCClient
//
//  Created by Alexey Chechetkin on 24.06.15.
//  Copyright (c) 2015 Alexey Chechetkin. All rights reserved.
//

#import "ServerListController.h"
#import "ServerListItemCell.h"
#import "RPCServerConfigController.h"
#import "TorrentListController.h"
#import "StatusListController.h"
#import "RPCServerConfigDB.h"
#import "GlobalConsts.h"

@interface ServerListController () <ServerListItemCellDelegate>

@property (strong, nonatomic) RPCServerConfigController *rpcConfigController;

@end

@implementation ServerListController

{
    UIBarButtonItem *_buttonDone;
    UIBarButtonItem *_buttonEdit;
    UIBarButtonItem *_buttonAdd;
    
    StatusListController *_statusListController;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = SERVERLIST_CONTROLLER_TITLE;
       
     // predefine buttons
    _buttonDone = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(toggleEditMode)];
    _buttonEdit = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemEdit target:self action:@selector(toggleEditMode)];
    _buttonAdd = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemAdd target:self action:@selector(showAddNewRPCConfigController)];
    
    self.navigationItem.leftBarButtonItem = _buttonEdit;
    self.navigationItem.rightBarButtonItem = _buttonAdd;
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    [_statusListController stopUpdating];
    _statusListController = nil;

    // fixing left button title for popOver navigation bar
    if( self.splitViewController )
    {
        UINavigationController *nc = self.splitViewController.viewControllers[1];
        TorrentListController *tlc = nc.viewControllers[0];
        tlc.torrents = nil;

        tlc.popoverButtonTitle = SERVERLIST_CONTROLLER_TITLE;
        
        [nc popToRootViewControllerAnimated:YES];
    }
}

- (RPCServerConfigController *)rpcConfigController
{
    if( !_rpcConfigController )
    {
        _rpcConfigController = instantiateController(CONTROLLER_ID_RPCSERVERCONFIG);
    
        // add buttons
        _rpcConfigController.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Cancel"
                                                                                                 style:UIBarButtonItemStyleDone
                                                                                                target:self
                                                                                                action:@selector(hideRPCConfigController)];
    }
    
    return _rpcConfigController;
}

- (void)toggleEditMode
{
    BOOL editing = !self.tableView.editing;
    [self.tableView setEditing:editing animated:YES];
    self.navigationItem.leftBarButtonItem = editing ? _buttonDone : _buttonEdit;
}

- (void)showAddNewRPCConfigController
{  
    // show view controller with two buttons "Cancel and Save"
    self.rpcConfigController.title = @"Add new server";
    self.rpcConfigController.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Add"
                                                                                              style:UIBarButtonItemStyleDone
                                                                                             target:self
                                                                                              action:@selector(addNewRPCConfig)];
    
    [self.navigationController pushViewController:self.rpcConfigController animated:YES];
}

- (void)hideRPCConfigController
{
    [self.navigationController popViewControllerAnimated:YES];
    _rpcConfigController = nil;
}

- (void)addNewRPCConfig
{
    if( [self.rpcConfigController saveConfig] )
    {
        // add new item to the db, reload data, hide controller
        [[RPCServerConfigDB sharedDB].db addObject:self.rpcConfigController.config];
        [[RPCServerConfigDB sharedDB] saveDB];
        
        [self.tableView reloadData];
        [self hideRPCConfigController];
    }
}

- (void)commitEditingRPCConfig
{
    if( [self.rpcConfigController saveConfig] )
    {
        [[RPCServerConfigDB sharedDB] saveDB];
        [self.tableView reloadData];
        [self hideRPCConfigController];
    }
}


// handler for editing
- (void)editButtonTouched:(UISegmentedControl *)button atPath:(NSIndexPath *)indexPath
{
     RPCServerConfig *configToEdit = [RPCServerConfigDB sharedDB].db[indexPath.row];
    
    self.rpcConfigController.title = @"Edit server";
    self.rpcConfigController.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Save"
                                                                                              style:UIBarButtonItemStyleDone
                                                                                             target:self
                                                                                             action:@selector(commitEditingRPCConfig)];
    
    self.rpcConfigController.config = configToEdit;
    
    [self toggleEditMode];
    
    [self.navigationController pushViewController:self.rpcConfigController animated:YES];
}

#pragma mark - TableView delegate methods

// handler for selecting server with config
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    _statusListController = instantiateController(CONTROLLER_ID_TORRENTSSTATUSLIST);
    
    RPCServerConfig *selectedConfig = [RPCServerConfigDB sharedDB].db[indexPath.row];
    
    _statusListController.config = selectedConfig ;
    _statusListController.title = selectedConfig.name;
    
    [self.navigationController pushViewController:_statusListController animated:YES];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    ServerListItemCell *cell = [tableView dequeueReusableCellWithIdentifier:CELL_ID_SERVERITEM forIndexPath:indexPath];
    RPCServerConfig *config = [RPCServerConfigDB sharedDB].db[indexPath.row];
    
    cell.nameLabel.text = config.name;
    cell.addressLabel.text = config.urlString;
    cell.indexPath = indexPath;
    cell.delegate = self;
    
    return cell;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    NSUInteger itemsCount = [RPCServerConfigDB sharedDB].db.count;

    self.navigationItem.leftBarButtonItem.enabled = itemsCount > 0;
    self.infoMessage = itemsCount > 0 ? nil : @"There are no servers available.\nAdd server to the list.";
    
    return itemsCount > 0 ? 1 : 0;
 }

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return @"List of configured servers";
}

- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if( editingStyle == UITableViewCellEditingStyleDelete )
    {
        // perform delete of the item
        [[RPCServerConfigDB sharedDB].db removeObjectAtIndex:indexPath.row ];
            
        [tableView reloadData];
    }
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [RPCServerConfigDB sharedDB].db.count;
}


@end

