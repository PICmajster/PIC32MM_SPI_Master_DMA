/*
    File Name:        :  dma.h
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/


#ifndef _DMA_H
#define _DMA_H
#include <stdint.h> /*uint8_t etc.*/

char myWriteBuffer[] = "Witaj DMA"; /*bufor nadawczy*/
char myReadBuffer[10] ; /*bufor odbiorczy*/
void DMA0_Initialize (void);


#endif

