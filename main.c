/*****************************************************************************
 *
 *   Copyright(C) 2012, Embedded Artists AB
 *   All rights reserved.
 *
 ******************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * Embedded Artists AB assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. Embedded Artists AB
 * reserves the right to make changes in the software without
 * notification. Embedded Artists AB also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdio.h>
#include "bsp.h"
#include "Display_Controller.h"

#include "Image_EAlogo.h"
#include "Image_PDlogo.h"
#include <string.h>

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
int main(void)
{

  uint8_t* pOldImg;

  printf("Starting E-paper demo\n");
  
  bsp_init();
  

  memset((uint8_t*)&PreloadImage[0][0], 0xff, 176*33);
  pOldImg = (uint8_t*)&PreloadImage[0][0];

  while(1)
  {
    printf("EA Image\n");
    epd_DisplayImg(DISPLAY_IN_USE, (uint8_t*)&ImageDataEA[0][0], pOldImg);
    pOldImg = (uint8_t*)&ImageDataEA[0][0];

    bsp_delayMs(10000);

    printf("PD Image\n");
    epd_DisplayImg(DISPLAY_IN_USE, (uint8_t*)&ImageDataPD[0][0], pOldImg);
    pOldImg = (uint8_t*)&ImageDataPD[0][0];


    bsp_delayMs(10000);
  }


  return 1;
}


