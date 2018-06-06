/*
    File Name:        :  main.c
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/
#include "mcu_config_files/mcc.h"
#include "delay.h"
#include "spi2.h"
#include "dma.h"
#include "dogm162.h"

int main(void)
{
    /*initialize the device*/
    SYSTEM_Initialize();
    SPI2_Initialize();
    DMA0_Initialize();
    PORTBbits.RB6 = 0 ; /*set LED OFF*/
    // When using interrupts, you need to set the Global Interrupt Enable bits
    // Use the following macros to:
    delayMs(2000);
    // Enable the Global Interrupts
    INTERRUPT_GlobalEnable();

    //Disable the Global Interrupts
    //INTERRUPT_GlobalDisable();
   
    DCH0ECONbits.CFORCE=1; /*transfer DMA0 lets go*/
           
    while (1)
    {
    
                  
    }
}
