//
//  TRFileInfo.m
//  TransmissionRPCClient
//
//  Holds information about file
//

#import "TRFileInfo.h"

@interface TRFileInfo()

@property(nonatomic) NSString*  name;
@property(nonatomic) long long  bytesComplited;
@property(nonatomic) NSString*  bytesComplitedString;
@property(nonatomic) long long  length;
@property(nonatomic) NSString*  lengthString;
@property(nonatomic) BOOL       wanted;
@property(nonatomic) int        priority;               /* TR_FILEINFO_PRIORITY */
@property(nonatomic) NSString*  priorityString;
@property(nonatomic) float      downloadProgress;       /* 0 .. 1 */
@property(nonatomic) NSString*  downloadProgressString;

@end

@implementation TRFileInfo

+ (TRFileInfo *)fileInfoFromJSON:(NSDictionary *)dict
{
    return [[TRFileInfo alloc] initFromJSON:dict];
}

- (instancetype)initFromJSON:(NSDictionary*)dict
{
    self = [super init];
    if( !self )
        return self;
    
    NSByteCountFormatter *byteFormatter = [[NSByteCountFormatter alloc] init];
    byteFormatter.allowsNonnumericFormatting = NO;
    
    if( dict[TR_ARG_FILEINFO_NAME] )
        _name = dict[TR_ARG_FILEINFO_NAME];
    
    if ( dict[TR_ARG_FILEINFO_LENGTH] )
    {
        _length = [(NSNumber*)dict[TR_ARG_FILEINFO_LENGTH] longLongValue];
        _lengthString = [byteFormatter stringFromByteCount:_length];
    }
    
    if( dict[TR_ARG_FILEINFO_BYTESCOMPLITED] )
    {
        _bytesComplited = [(NSNumber*)dict[TR_ARG_FILEINFO_BYTESCOMPLITED] longLongValue];
        _bytesComplitedString = [byteFormatter stringFromByteCount:_bytesComplited];
    }
    
    if( _length > 0 )
    {
        _downloadProgress = (float)((double)_bytesComplited/(double)_length);
        _downloadProgressString = [NSString stringWithFormat:@"%02.2f%%", _downloadProgress * 100.0f];
    }
    
    if( dict[TR_ARG_FILEINFO_WANTED] )
        _wanted = [(NSNumber*)dict[TR_ARG_FILEINFO_WANTED] boolValue];
    
    if( dict[TR_ARG_FILEINFO_PRIORITY] )
    {
        _priority = [(NSNumber*)dict[TR_ARG_FILEINFO_PRIORITY] intValue];
        _priorityString = @"unknown";
        if( _priority == TR_FILEINFO_PRIORITY_NORMAL )
            _priorityString = @"normal";
        else if( _priority == TR_FILEINFO_PRIORITY_LOW )
            _priorityString = @"low";
        else if( _priority == TR_FILEINFO_PRIORITY_HIGH )
            _priorityString = @"high";
    }
    
    return self;
}

@end
