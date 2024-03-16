/**
  ******************************************************************************
  * @date    Mar 19, 2023
  * @file    kdr_math.c
  * @author  Kefan Zheng
  * @brief   
  * @version V0.0.0
  * @email   kirk_z@yeah.net
  */

/* Includes ------------------------------------------------------------------*/
#include "kdr_math.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/**
 * @brief  A triagular-like array
*/
const uint32_t KDR_MATH_BIT_TRIANGLE[33]=
{
  0x00000000,	//0
  0x00000001,	//1
  0x00000003,	//2
  0x00000007,	//3
  0x0000000F,	//4
  0x0000001F,	//5
  0x0000003F,	//6
  0x0000007F,	//7
  0x000000FF,	//8
  0x000001FF,	//9
  0x000003FF,	//10
  0x000007FF,	//11
  0x00000FFF,	//12
  0x00001FFF,	//13
  0x00003FFF,	//14
  0x00007FFF,	//15
  0x0000FFFF,	//16
  0x0001FFFF,	//17
  0x0003FFFF,	//18
  0x0007FFFF,	//19
  0x000FFFFF,	//20
  0x001FFFFF,	//21
  0x003FFFFF,	//22
  0x007FFFFF,	//23
  0x00FFFFFF,	//24
  0x01FFFFFF,	//25
  0x03FFFFFF,	//26
  0x07FFFFFF,	//27
  0x0FFFFFFF,	//28
  0x1FFFFFFF,	//29
  0x3FFFFFFF,	//30
  0x7FFFFFFF,	//31
  0xFFFFFFFF	//32
};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
uint8_t KDR_MATH_LSB_Index(uint32_t num)
{
  uint8_t rst = 0;

  if(!num)
    return 0xFF;

  while(!(num & 0x3F))
  {
    rst += 6;
    num >>= 6;
  }

  while(!(num & 1))
  {
    rst ++;
    num >>= 1;
  }

  return rst;
}
/* Initialization and de-initialization functions *****************************/
/* Configuration functions ****************************************************/
/* IO operation functions *****************************************************/
/* Peripheral State and Error functions ***************************************/

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdr_math.c ***/
