#include <3ds.h>

#include <stdio.h>
#include <stdint.h>
#include <string>

namespace CTRPluginFramework{
    void main(void){
        
        uint16_t *const fb = (uint16_t *)((void *)0x1F48F000);
        uint32_t posX = 170, posY = 200;
        for(uint32_t i = 0; i < 0xFFFFFFFF; i++){
            for(int32_t y = 0; y < 100; y++)
            {
                for(int32_t x = 0; x < 100; x++){
                    uint32_t screenPos = ((posX * 240 * 2 + (240 - y - posY - 1) * 2) + (5 - x) * 2 * 240);
                    fb[screenPos / 2] = 0x00FF00;
                }
            }
        }
    }
}