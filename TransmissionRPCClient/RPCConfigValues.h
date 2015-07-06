//
//  RPCConfigValues.h
//  TransmissionRPCClient
//
//  RPC config values using in JSON requests/answers
//

#ifndef TransmissionRPCClient_RPCConfigValues_h
#define TransmissionRPCClient_RPCConfigValues_h

// -- common rpc json values
#define TR_METHOD                                   @"method"
#define TR_METHOD_ARGS                              @"arguments"
#define TR_RETURNED_ARGS                            @"arguments"
#define TR_RESULT                                   @"result"
#define TR_RESULT_SUCCEED                           @"success"

#define TR_METHODNAME_TORRENTRESUME                 @"torrent-start"
#define TR_METHODNAME_TORRENTSTOP                   @"torrent-stop"
#define TR_METHODNAME_TORRENTREANNOUNCE             @"torrent-reannounce"
#define TR_METHODNAME_TORRENTVERIFY                 @"torrent-verify"
#define TR_METHODNAME_TORRENTREMOVE                 @"torrent-remove"
#define TR_METHODNAME_TORRENTADD                    @"torrent-add"
#define TR_METHODNAME_TORRENTGET                    @"torrent-get"
#define TR_METHODNAME_TORRENTSET                    @"torrent-set"
#define TR_METHODNAME_SESSIONGET                    @"session-get"
#define TR_METHODNAME_SESSIONSET                    @"session-set"

#define TR_RETURNED_ARG_TORRENTS                    @"torrents"
#define TR_ARG_DELETELOCALDATA                      @"delete-local-data"
#define TR_ARG_METAINFO                             @"metainfo"                 /* Base64 encoded info */
#define TR_ARG_BANDWIDTHPRIORITY                    @"bandwidthPriority"
#define TR_ARG_PAUSEONADD                           @"paused"

// ---- TORRENT GET --- arguments

#define TR_ARG_FIELDS                               @"fields"
#define TR_ARG_IDS                                  @"ids"
#define TR_ARG_FIELDS_ID                            @"id"
#define TR_ARG_FIELDS_NAME                          @"name"
#define TR_ARG_FIELDS_STATUS                        @"status"
#define TR_ARG_FIELDS_ETA                           @"eta"

// torrent statuses
#define TR_STATUS_STOPPED                           0 /* Torrent is stopped */
#define TR_STATUS_CHECK_WAIT                        1 /* Queued to check files */
#define TR_STATUS_CHECK                             2 /* Checking files */
#define TR_STATUS_DOWNLOAD_WAIT                     3 /* Queued to download */
#define TR_STATUS_DOWNLOAD                          4 /* Downloading */
#define TR_STATUS_SEED_WAIT                         5 /* Queued to seed */
#define TR_STATUS_SEED                              6 /* Seeding */
// -----
#define TR_ARG_FIELDS_PERCENTDONE                   @"percentDone"
#define TR_ARG_FIELDS_RATEDOWNLOAD                  @"rateDownload"
#define TR_ARG_FIELDS_RATEUPLOAD                    @"rateUpload"
#define TR_ARG_FIELDS_TOTALSIZE                     @"totalSize"
// peers
#define TR_ARG_FIELDS_PEERSCONNECTED                @"peersConnected"
#define TR_ARG_FIELDS_PEERSGETTINGFROMUS            @"peersGettingFromUs"
#define TR_ARG_FIELDS_PEERSSENDINGTOUS              @"peersSendingToUs"

// peers object fields
#define TR_ARG_FIELDS_PEERS                         @"peers"
#define TR_ARG_FIELDS_PEER_ADDRESS                  @"address"
#define TR_ARG_FIELDS_PEER_PORT                     @"port"
#define TR_ARG_FIELDS_PEER_CLIENTNAME               @"clientName"
#define TR_ARG_FIELDS_PEER_FLAGSTR                  @"flagStr"
#define TR_ARG_FIELDS_PEER_RATETOCLIENT             @"rateToClient" /* download rate */
#define TR_ARG_FIELDS_PEER_RATETOPEER               @"rateToPeer"   /* upload rate */
#define TR_ARG_FIELDS_PEER_PROGRESS                 @"progress"
#define TR_ARG_FIELDS_PEER_ISENCRYPTED              @"isEncrypted"

#define TR_ARG_FIELDS_UPLOADEDEVER                  @"uploadedEver"
#define TR_ARG_FIELDS_UPLOADRATIO                   @"uploadRatio"

#define TR_ARG_FIELDS_COMMENT                       @"comment"
#define TR_ARG_FIELDS_CREATOR                       @"creator"
#define TR_ARG_FIELDS_DATECREATED                   @"dateCreated"
#define TR_ARG_FIELDS_ERRORNUM                      @"error"
#define TR_ARG_FIELDS_ERRORSTRING                   @"errorString"
#define TR_ARG_FIELDS_HASHSTRING                    @"hashString"
#define TR_ARG_FIELDS_DONEDATE                      @"doneDate"
#define TR_ARG_FIELDS_PIECECOUNT                    @"pieceCount"
#define TR_ARG_FIELDS_PIECESIZE                     @"pieceSize"
#define TR_ARG_FIELDS_SECONDSDOWNLOADING            @"secondsDownloading"
#define TR_ARG_FIELDS_SECONDSSEEDING                @"secondsSeeding"
#define TR_ARG_FIELDS_STARTDATE                     @"startDate"
#define TR_ARG_FIELDS_ACTIVITYDATE                  @"activityDate"
#define TR_ARG_FIELDS_HAVEVALID                     @"haveValid"
#define TR_ARG_FIELDS_HAVEUNCHECKED                 @"haveUnchecked"
#define TR_ARG_FIELDS_RECHECKPROGRESS               @"recheckProgress"
#define TR_ARG_FIELDS_DOWNLOADEDEVER                @"downloadedEver"

// FileInfo values
#define TR_ARG_FIELDS_FILES                         @"files"
#define TR_ARG_FIELDS_FILESTATS                     @"fileStats"
#define TR_ARG_FILEINFO_NAME                        @"name"
#define TR_ARG_FILEINFO_WANTED                      @"wanted"
#define TR_ARG_FILEINFO_PRIORITY                    @"priority"
#define TR_ARG_FILEINFO_LENGTH                      @"length"
#define TR_ARG_FILEINFO_BYTESCOMPLETED              @"bytesCompleted"

// set torrent
#define TR_ARG_FIELDS_FILES_WANTED                  @"files-wanted"
#define TR_ARG_FIELDS_FILES_UNWANTED                @"files-unwanted"

// priorities
#define TR_ARG_FIELDS_FILES_PRIORITY_HIGH            @"priority-high"       /* 1  */
#define TR_ARG_FIELDS_FILES_PRIORITY_LOW             @"priority-low"        /* -1 */
#define TR_ARG_FIELDS_FILES_PRIORITY_NORMAL          @"priority-normal"     /* 0  */

// session params
#define TR_ARG_SESSION_ALTLIMIDOWNRATE          @"alt-speed-down"                 // number     | max global download speed (KBps)
#define TR_ARG_SESSION_ALTLIMITRATEENABLED      @"alt-speed-enabled"              // boolean    | true means use the alt speeds
//#define TR_ARG_SESSION_@"alt-speed-time-begin"           // number     | when to turn on alt speeds (units: minutes after midnight)
//#define TR_ARG_SESSION_@"alt-speed-time-enabled"         // boolean    | true means the scheduled on/off times are used
//#define TR_ARG_SESSION_@"alt-speed-time-end"             // number     | when to turn off alt speeds (units: same)
//#define TR_ARG_SESSION_@"alt-speed-time-day"             // number     | what day(s) to turn on alt speeds (look at tr_sched_day)
#define TR_ARG_SESSION_ALTLIMITUPRATE           @"alt-speed-up"                   // number     | max global upload speed (KBps)
#define TR_ARG_SESSION_DOWNLOADDIR              @"download-dir"                   // string     | default path to download torrents
#define TR_ARG_SESSION_DHTENABLED               @"dht-enabled"                    // boolean    | true means allow dht in public torrents
#define TR_ARG_SESSION_ENRYPTION                @"encryption"                     // string     | "required", "preferred", "tolerated"
#define TR_ARG_SESSION_IDLESEEDLIMIT            @"idle-seeding-limit"             // number     | torrents we're seeding will be stopped if they're idle for this long
#define TR_ARG_SESSION_IDLELIMITENABLED         @"idle-seeding-limit-enabled"     // boolean    | true if the seeding inactivity limit is honored by default
#define TR_ARG_SESSION_LPDENABLED               @"lpd-enabled"                    // boolean    | true means allow Local Peer Discovery in public torrents
#define TR_ARG_SESSION_PEERLIMITTOTAL           @"peer-limit-global"              // number     | maximum global number of peers
#define TR_ARG_SESSION_PEERLIMITPERTORRENT      @"peer-limit-per-torrent"         // number     | maximum global number of peers
#define TR_ARG_SESSION_PEXENABLED               @"pex-enabled"                    // boolean    | true means allow pex in public torrents
#define TR_ARG_SESSION_PORT                     @"peer-port"                      // number     | port number
#define TR_ARG_SESSION_PORTRANDOMONSTART        @"peer-port-random-on-start"      // boolean    | true means pick a random peer port on launch
#define TR_ARG_SESSION_PORTFORWARDENABLED       @"port-forwarding-enabled"        // boolean    | true means enabled
#define TR_ARG_SESSION_RENAMEPARTIAL            @"rename-partial-files"           // boolean    | true means append ".part" to incomplete files
#define TR_ARG_SESSION_RPCVER                   @"rpc-version"                    // number     | the current RPC API version
#define TR_ARG_SESSION_RPCVERMIN                @"rpc-version-minimum"            // number     | the minimum RPC API version supported
#define TR_ARG_SESSION_SEEDRATIOLIMIT           @"seedRatioLimit"                 // double     | the default seed ratio for torrents to use
#define TR_ARG_SESSION_SEEDRATIOLIMITENABLED    @"seedRatioLimited"               // boolean    | true if seedRatioLimit is honored by default
#define TR_ARG_SESSION_LIMITDOWNRATE            @"speed-limit-down"               // number     | max global download speed (KBps)
#define TR_ARG_SESSION_LIMITDOWNRATEENABLED     @"speed-limit-down-enabled"       // boolean    | true means enabled
#define TR_ARG_SESSION_LIMITUPRATE              @"speed-limit-up"                 // number     | max global upload speed (KBps)
#define TR_ARG_SESSION_LIMITUPRATEENABLED       @"speed-limit-up-enabled"         // boolean    | true means enabled
#define TR_ARG_SESSION_STARTONADD               @"start-added-torrents"           // boolean    | true means added torrents will be started right away
#define TR_ARG_SESSION_TRASHFILES               @"trash-original-torrent-files"   // boolean    | true means the .torrent file of added torrents will be deleted
#define TR_ARG_SESSION_UTPENABLED               @"utp-enabled"                    // boolean    | true means allow utp
#define TR_ARG_SESSION_VERSION                  @"version"                        // string     | long v

#endif
