/*
    File Name:        :  spi2.c
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/

#include <xc.h>
#include "spi2.h"




void SPI2_Initialize (void)
{
       
    SPI2BRG = 0x9; /*Baud Rate Generator, Manual SPI page 29*/
    SPI2CONbits.MSTEN = 1 ; /*Master mode ON*/
    SPI2CONbits.SMP = 1;    /*Input Sample Phase bit */
    SPI2CONbits.ON = 1;     /*SPI Peripheral ON*/
    SPI2CONbits.ENHBUF = 1; /*Enhanced Buffer mode ON*/
        
}


