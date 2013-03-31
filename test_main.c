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

  while(1)
  {
    printf("EA Image\n");
	
	asciiImage_printImage((uint8_t*)&ImageDataEA[0][0], 176, 33);
	
	sleep(5);

    printf("PD Image\n");

	asciiImage_printImage((uint8_t*)&ImageDataPD[0][0], 176, 33);

	sleep(5);

  }


  return 1;
}


