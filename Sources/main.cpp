#include <3ds.h>
#include "csvc.h"
#include <CTRPluginFramework.hpp>
#include <plgloader.h>

#include <vector>

/*
typedef struct PACKED{
    u64             magic;
    u32             version;
    u32             reserved;
}_simple_3gx_Header

// タイトルIDの取得
// sdカードの3gxの数

// 3gxの選択
*/

namespace CTRPluginFramework
{

    static void    ToggleTouchscreenForceOn(void)
    {
        static u32 original = 0;
        static u32 *patchAddress = nullptr;

        if (patchAddress && original)
        {
            *patchAddress = original;
            return;
        }

        static const std::vector<u32> pattern =
        {
            0xE59F10C0, 0xE5840004, 0xE5841000, 0xE5DD0000,
            0xE5C40008, 0xE28DD03C, 0xE8BD80F0, 0xE5D51001,
            0xE1D400D4, 0xE3510003, 0x159F0034, 0x1A000003
        };

        Result  res;
        Handle  processHandle;
        s64     textTotalSize = 0;
        s64     startAddress = 0;
        u32 *   found;

        if (R_FAILED(svcOpenProcess(&processHandle, 16)))
            return;

        svcGetProcessInfo(&textTotalSize, processHandle, 0x10002);
        svcGetProcessInfo(&startAddress, processHandle, 0x10005);
        if(R_FAILED(svcMapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, processHandle, (u32)startAddress, textTotalSize)))
            goto exit;

        found = (u32 *)Utils::Search<u32>(0x14000000, (u32)textTotalSize, pattern);

        if (found != nullptr)
        {
            original = found[13];
            patchAddress = (u32 *)PA_FROM_VA((found + 13));
            found[13] = 0xE1A00000;
        }

        svcUnmapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, textTotalSize);
exit:
        svcCloseHandle(processHandle);
    }

    void    PatchProcess(FwkSettings &settings)
    {
        ToggleTouchscreenForceOn();
    }

    void    OnProcessExit(void)
    {
        ToggleTouchscreenForceOn();
    }

    void    INFO_Menu(PluginMenu &menu)
    {
        
        std::string path[32];
        u64 title_id[16];
        PluginLoaderContext PluginLoaderCtx;
        PluginLoaderContext *ctx = &PluginLoaderCtx;
        u32 *cmdbuf = getThreadCommandBuffer();
        svcOpenProcess(&ctx->target, cmdbuf[1]);

        svcGetProcessInfo((s64 *)&title_id, (Handle)ctx->target, 0x10001);

        sprintf(path, "luma/plugins/%016llX/", title_id);
        
        OSD::Notify(Color(234, 145, 152) << path);
    }

    int     main(void){
        PluginMenu *menu = new PluginMenu("TEST", 0, 8, 0, "よう");

        menu->SynchronizeWithFrame(true);
        menu->ShowWelcomeMessage(false);
        
        // OSD::Notify(Color(234, 145, 152) << "0x07000100");
        
        INFO_Menu(*menu);       

        // START SHOW MENU
        menu->Run();

        // END
        delete menu;
        return (0);
    }
}
