#pragma once

#include <3ds/types.h>

typedef struct
{
    bool    noFlash;
    u8      pluginMemoryStrategy;
    u32     lowTitleId;
    char    path[256];
    u32     config[32];
}   PluginLoadParameters;


typedef struct
{
    u32             magic;
    u32             version;
    u32             heapVA;
    u32             heapSize;
    u32             exeSize; // Include sizeof(PluginHeader) + .text + .rodata + .data + .bss (0x1000 aligned too)
    u32             isDefaultPlugin;
    s32*            plgldrEvent; ///< Used for synchronization
    s32*            plgldrReply; ///< Used for synchronization
    u8              notifyHomeEvent;
    u8              padding[3];
    u32             reserved[23];
    u32             config[32];
}   PluginHeader;
