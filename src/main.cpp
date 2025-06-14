// don`t use synchronization.h
#include <3ds.h>

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <types.h>

#define LCD_REGS_BASE           0x10202000
#define LCD_TOP_FILL_REG        *(vu32 *)(LCD_REGS_BASE + 0x200 + 4)
#define LCD_BOTTOM_FILL_REG     *(vu32 *)(LCD_REGS_BASE + 0xA00 + 4)
#define LCD_FILL_ENABLE         (1u << 24)
#define GREEN_COLOR             0x00FF00
#define RED_COLOR               0xFF

struct fb {
     u8 *top_left;
     u8 *top_right;
     u8 *bottom;
};

struct fb fbs[2] =
{
    {
        .top_left  = (u8 *)0x18300000,
        .top_right = (u8 *)0x18300000,
        .bottom    = (u8 *)0x18346500,
    },
    {
        .top_left  = (u8 *)0x18400000,
        .top_right = (u8 *)0x18400000,
        .bottom    = (u8 *)0x18446500,
    },
};

namespace CTRPluginFramework{
    void main(void){
        
        // fill both green screen
        while(1)
            LCD_TOP_FILL_REG = LCD_FILL_ENABLE | GREEN_COLOR;
            LCD_BOTTOM_FILL_REG = LCD_FILL_ENABLE | RED_COLOR;
            for(u8 i = 0; i < 0xFF; i++);
    }
}