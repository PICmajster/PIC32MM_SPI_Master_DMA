/*
    File Name:        :  spi2.h
    Device            :  PIC32MM0256GPM048
    Compiler          :  XC32 2.05
    MPLAB             :  MPLAB X 4.15
    Created by        :  http://strefapic.blogspot.com
*/
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef _SPI2_H
#define _SPI2_H

#define SPI2_DUMMY_DATA 0x0
#define SPI2_FIFO_FILL_LIMIT 0x4

void SPI2_Initialize (void);

static void SPI2_Exchange( uint8_t *pTransmitData, uint8_t *pReceiveData );
static uint16_t SPI2_ExchangeBuffer(uint8_t *pTransmitData, uint16_t byteCount, uint8_t *pReceiveData);
uint8_t SPI2_Exchange8bit( uint8_t data );
uint16_t SPI2_Exchange8bitBuffer(uint8_t *dataTransmitted, uint16_t byteCount, uint8_t *dataReceived);



#endif