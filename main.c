/*
? [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/dma/dma.h"

volatile  uint16_t sins[128] = {
    
    0x800,0x864,0x8c8,0x92c,0x98f,0x9f1,0xa52,0xab1,
    0xb0f,0xb6b,0xbc5,0xc1c,0xc71,0xcc3,0xd12,0xd5f,
    0xda7,0xded,0xe2e,0xe6c,0xea6,0xedc,0xf0d,0xf3a,
    0xf63,0xf87,0xfa7,0xfc2,0xfd8,0xfe9,0xff5,0xffd,
    0xfff,0xffd,0xff5,0xfe9,0xfd8,0xfc2,0xfa7,0xf87,
    0xf63,0xf3a,0xf0d,0xedc,0xea6,0xe6c,0xe2e,0xded,
    0xda7,0xd5f,0xd12,0xcc3,0xc71,0xc1c,0xbc5,0xb6b,
    0xb0f,0xab1,0xa52,0x9f1,0x98f,0x92c,0x8c8,0x864,
    0x800,0x79b,0x737,0x6d3,0x670,0x60e,0x5ad,0x54e,
    0x4f0,0x494,0x43a,0x3e3,0x38e,0x33c,0x2ed,0x2a0,
    0x258,0x212,0x1d1,0x193,0x159,0x123,0xf2,0xc5,
    0x9c,0x78,0x58,0x3d,0x27,0x16,0xa,0x2,
    0x0,0x2,0xa,0x16,0x27,0x3d,0x58,0x78,
    0x9c,0xc5,0xf2,0x123,0x159,0x193,0x1d1,0x212,
    0x258,0x2a0,0x2ed,0x33c,0x38e,0x3e3,0x43a,0x494,
    0x4f0,0x54e,0x5ad,0x60e,0x670,0x6d3,0x737,0x79b,
    
};

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();
    
    DMA.ChannelDisable(DMA_CHANNEL_0);
    
    DMA.SourceAddressSet(DMA_CHANNEL_0, &sins[0]);
    
    DMA.DestinationAddressSet(DMA_CHANNEL_0, (uint16_t)&DAC1DATH);
    
    DMA.ChannelEnable(DMA_CHANNEL_0);

    while(1)
    {
        
    }    
}