#include <3ds.h>

#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

// share memory

typedef struct PACKED{
    u64             magic;
    u32             version;
    u32             reserved;
}_simple_3gx_Header;

// タイトルIDの取得
// sdカードの3gxの数

// 3gxの選択

// luma/plugins/{title_id}/legacys/*.3gx
// legacy_3gx/*.3gx

extern "C"{

    void message(char msg){
        // u8 y = 5;
        OSD::Notify(Color(128, 128, 128) << msg);
        for(uint16_ti = 0; i < 30000; i++);
        /*
        y += 5;
        if(y < 240)
            y = 5;
        */
    }

    void error(char msg){
        message(msg);
        while(!hidScanInput());
    }
}

namespace CTRPluginFramework
{
    // 0x07000100 0x07FFFFFF
    // 0x04000000 0x06FFF000
    void main(void){
        

        // タイトルIDの取得
        s64 tid[33];
        Result result = svcGetProcessInfo(tid, CUR_PROCESS_HANDLE, 0x10001);
        if(!result){
            error("TID");
        }
        message("タイトルID取得した");
        (void)result;
        message("ok");


        /*
        // sd MOUNT
        archiveMountSdmc();
        message("sdをマウントした");

            

        // 3gxのファイルパス
        char path_c[32];
        int result = sprintf(path_c, "sdmc:/l3gx/%016llX", tid);
        std::string path = path_c;
        message("ファイルパス");

        
        
        // 3gxの検索
        std::string 3gx_path = path << "/" << tid << ".3gx" << std::end;
            


        IFile   plugin;
        OpenFile(&plugin, 3gx_path);



        simple_3gx_header 3gx_header = (simple_3gx_header *)(g_memBlock + MemBlockSize - (u32)fileSize);
        Read_3gx_Header(plugin, 3gx_header);
        


        if (plugin.magic == _3GX_MAGIC)
        // linker
        0x7000100~0x7FFFFDF main
        0x7000100~0x7XXXXDF 3GX0001
        ローダのサイズ分
        0x7XXXXXX~0x7FFFFDF 3gx0001_loader[asm] 3gx_rw jump
        */
        // ReadFile("3gx_selector.bin", (0x7000100 + 0x3FFFFF) - 3gx_selector_size)
    }

}

/*
タイトルidの取得
ファイルパス
3gxの検索
3gxのopen
ヘッダーの読み込み
マジックの確認
if 0001なら
    binをロード
3gxを
*/