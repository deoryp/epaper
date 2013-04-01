#ifndef __AsciiImageConverter_H_
#define __AsciiImageConverter_H_

#include <stdint.h>

void asciiImage_readImage(char * file, uint8_t * image, int h, int w);
void asciiImage_printImage(uint8_t * image, int h, int w);

#endif
