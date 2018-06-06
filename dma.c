/*
    File Name:        :  dma.c
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/

#include "mcu_config_files/mcc.h"
#include "dma.h"

void DMA0_Initialize(void){

IEC3bits.DMA0IE = 0 ; /*disable DMA0 interrupt, datasheet page 66*/
IFS3bits.DMA0IF = 0 ; /*clear any existing DMA channel 0 interrupt flag, datasheet page 66*/

DMACONbits.ON = 1; /*enable the DMA controller*/
DCH0CONbits.CHEN = 0; /* channel off*/
DCH0CONbits.CHPRI = 3; /*channel priority 3*/

DCH0ECON=0; /*no start or stop IRQs, no pattern match*/

DCH0SSA = ((uint32_t)myWriteBuffer & 0x1FFFFFFF); // Convert virtual address to physical address
DCH0DSA = ((uint32_t)&SPI2BUF & 0x1FFFFFFF); // Convert virtual address to physical address

DCH0SSIZ = sizeof(myWriteBuffer); /*source size*/
DCH0DSIZ = 1; /*desination size, one byte per SPI transfer */
DCH0CSIZ = sizeof(myWriteBuffer); /*cell size*/

DCH0INTCLR = 0xFF;      /*clear existing all Interrupt flag*/
DCH0INTbits.CHCCIE = 1; /*Channel Cell Transfer Complete Interrupt Enable bit*/

IPC24bits.DMA0IP = 1 ; /*set interrupt priority*/
IPC24bits.DMA0IS = 0 ; /*set interrupt subpriority*/

 DCH0CONbits.CHEN = 1; /*channel on*/
 IEC3bits.DMA0IE = 1; /*enable DMA0 interrupt, datasheet page 66*/
 IFS3bits.DMA0IF = 0;

}

void __ISR(_DMA0_VECTOR) __DMA0Interrupt(void)
{
PORTBbits.RB6 = 1 ;     /*set LED ON*/
DCH0INTCLR = 0xFF;      /*clear existing all DMA0 Interrupt flag*/
IFS3bits.DMA0IF = 0 ;   /*clear existing DMA0 channel 0 interrupt flag, datasheet page 66*/
}



