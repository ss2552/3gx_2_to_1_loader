#pragma once

#include <3ds/types.h>
#include "plgldr.h"

typedef struct
{
    bool    isReady;
    bool    isAppRegion;
    u8 *    memblock;
}   MemoryBlock;

typedef struct
{
    Result          code;
    const char *    message;
}   Error;

typedef struct 
{
    bool            isEnabled;
    bool            pluginIsSwapped;
    bool            pluginIsHome;
    const char *    pluginPath;
    MemoryBlock     memblock;
    Error           error;
    PluginHeader    header;
    Handle          target;
    Handle          arbiter;
    Handle          kernelEvent;

    bool            useUserLoadParameters;
    PluginLoadParameters    userLoadParameters;

    s32          plgEvent;
    s32          plgReply;
    s32 *        plgEventPA;
    s32 *        plgReplyPA;
    
    bool            isExeLoadFunctionset;
    bool            isSwapFunctionset;
    u8              pluginMemoryStrategy;
    u32             exeLoadChecksum;
    u32             swapLoadChecksum;    
}   PluginLoaderContext;

extern PluginLoaderContext PluginLoaderCtx;