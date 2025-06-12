#include <3ds.h>

#include <stdio.h>
#include <stdint.h>
#include <string>

namespace CTRPluginFramework{
    void main(void){
        
        uint16_t *const fb = (uint16_t *)((void *)0x1F48F000);

        int32_t y;
        for(y = 0; y < 30; y++)
        {
            fb[((50 * 400 * 2 + (400 - y - 50 - 1) * 2) + (5 - 3) * 2 * 400) / 2] = 0xFFFFFF;
        }
    }
}