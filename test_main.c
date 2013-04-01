/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdio.h>
#include "bsp.h"
#include "Display_Controller.h"

#include "Image_EAlogo.h"
#include "Image_PDlogo.h"
#include <string.h>

#include "AsciiImageConverter.h"

/******************************************************************************
 * Typedefs and defines
 *****************************************************************************/

/******************************************************************************
 * Local Variables
 *****************************************************************************/

/******************************************************************************
 * Local Functions
 *****************************************************************************/

/******************************************************************************
 * Main method
 *****************************************************************************/
int main(int argc, char *argv[])
{

	uint8_t* pOldImg;

	printf("Starting E-paper demo\nGiven %d aguments\n", argc);
	
	memset((uint8_t*)&PreloadImage[0][0], 0xff, 176*33);
	pOldImg = (uint8_t*)&PreloadImage[0][0];

	if (argc > 1) {
		asciiImage_readImage(argv[1], pOldImg, 176, 33);
	}

	printf("File Image\n");
	asciiImage_printImage((uint8_t*)&ImageDataEA[0][0], 176, 33);
	asciiImage_printImage((uint8_t*)&PreloadImage[0][0], 176, 33);

	return 1;
}


