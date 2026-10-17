#include "common.h"

extern s32 D_00135A58[];

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", CallRpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", MemcpyD);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", MemcpyS);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", StrcpyD);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", StrcpyS);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetPoll);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetName2Address);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetAddress2String);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetAddress2Name);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCreate);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetOpen);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetClose);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetRecv);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetRecvFrom);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetSend);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetSendTo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetAbort);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetControl);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetInterfaceList);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetInterfaceControl);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetRoutingTable);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetNameServers);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetChangeThreadPriority);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetGetLog);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetAbortLog);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlUpInterface);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlDownInterface);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlSetAutoMode);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceInetCtlGetState);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetInitialize);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetTerminate);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetRegisterHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetUnregisterHandler);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetSetConfiguration);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119598);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119628);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119648);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119668);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119748);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119770);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119808);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetWaitGetInterfaceID);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetWaitGetAddress);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceLibnetWaitGetInterfaceEvent);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceSifMInitRpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119AA0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceSifMExitRpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119AF8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119BA0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00119BC0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceSifMBindRpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceSifMBindRpcParam);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceSifMUnBindRpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceSifMCallRpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Init);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2End);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2CreateSocket);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2DeleteSocket);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2SearchSocket);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2ChangeThreadPriority);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2iChangeThreadPriority);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2FormatAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2UnformatAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetInfoAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2SearchFileAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetDirAllAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2ReadFileAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2WriteFileAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2CreateFileAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2DeleteAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetDirAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2MkdirAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2ChdirAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2ChmodAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2RenameAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetEntSpaceAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011B558);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011B770);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2CheckAsync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Sync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetInfo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Format);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Unformat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2ReadFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2WriteFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2CreateFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Delete);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Rename);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Mkdir);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Chdir);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetDir);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2Chmod);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2SearchFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceMc2GetEntSpace);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BBE8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BC48);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BCB8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BD10);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BDC8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011BF48);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C068);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C0B0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatInit);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatInit2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C300);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C420);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C4B0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C5C8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C610);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C678);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C7A8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C8D8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011C9B0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011CB30);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011CBC0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatGetInfo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatFormat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatUnFormat);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011D9E0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011DA88);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011DAE8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011DD60);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011E1B0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011E358);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011E488);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_0011E958);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatSearchFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatCreateFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatReadFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatWriteFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatDeleteFile);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatChDir);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatGetDir);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatSetAttr);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatRename);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcFatGetEntSpace);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpInit);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpGetCardSpec);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpCheckNewCard);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpAuthentication);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpReadSysInfo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpWriteSysInfo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpReadClust);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpWriteClust);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpFlushCache);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpWriteUserClustOnCache);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpReadUserClustOnCache);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpReadUserClust);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpWriteUserClust);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpIsSpeckOutBlock);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpIsSpeckOutClust);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcpMakeSpecoutBlock);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _SceMcComGetSysInfo);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00121030);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00121100);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00121158);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreInit);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreEnd);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreSetWriteBackHole);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreSetCardSpec);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreGetCardSpec);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreCheckNewCard);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreClearNewCardFlag);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreAuthentication);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreWriteBack);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreReadClock);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreReadPage2);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreReadPage);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreWritePage);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreWriteSameData);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreBlockErase);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreGetConnection);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00121FC0);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreCreateSocket);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreCheckSocket);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreDeleteSocket);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreChangeSocketTypeDbc2Mc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", _sceMcCoreChangeSocketTypeMc2Dbc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetup);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifInit);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCreateCallbackThread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifDeleteCallbackThread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSync);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCheck);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifGetResult);

//INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetFNoDecode);
s32 sceNetcnfifSetFNoDecode(s32 arg0)
{
    D_00135A58[0] = arg0;
    return 0;
}

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifGetCount);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifGetList);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifLoadEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifLoadEntryAuto);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifAddEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifEditEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifDeleteEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetLatestEntry);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifDeleteAll);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCheckCapacity);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCheckAdditionalAT);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifCheckSpecialProvider);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifGetAddr);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifAllocWorkarea);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifFreeWorkarea);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSetEnv);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifTerm);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00122FA8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00123090);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_create_callback_thread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_delete_callback_thread);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifSendIOP);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sceNetcnfifDmaCheck);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00123280);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_001232A8);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", func_00123308);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_call_rpc);

INCLUDE_ASM("asm/SCPS_150.97/nonmatchings/sdk/libnet", sce_sync);
