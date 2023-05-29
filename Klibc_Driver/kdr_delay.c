/**
  ******************************************************************************
  * @date    May 22, 2023
  * @file    kdr_delay.c
  * @author  Kefan Zheng
  * @brief   
  * @version V0.0.0
  * @email   kirk_z@yeah.net
  */

/* Includes ------------------------------------------------------------------*/
#include "kdr_delay.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/**
 * @brief  Provide a delay in microseconds
 * @note   Currently can only work when SysTick is initialized as a millisecond
 *         ticker
*/
void KDR_Delay(uint32_t us)
{
  static uint64_t tmp;
  static uint32_t ticks;
  static uint32_t told, tnow, tcnt;
  static uint32_t reload;
  /* Init vars */
  tcnt = 0;
  reload = SysTick->LOAD;
  /* Count ticks */
  tmp = us;
  tmp *= reload + 1;
  tmp += 500;    /* For rounding */
  tmp /= 1000;
  ticks = tmp&0xFFFFFFFF00000000?0xFFFFFFFF:(uint32_t)tmp;
  told = SysTick->VAL; /* Record current time */
  for(;;)
  {
    tnow = SysTick->VAL; // Get new tick
    if(tnow != told)
    {
      tcnt += tnow<told?told-tnow:reload-tnow+told; // Count time
      if(tcnt >= ticks) break;
      told = tnow; // Reload tick
    }
  }
}

/* Initialization and de-initialization functions *****************************/
/* Configuration functions ****************************************************/
/* IO operation functions *****************************************************/
/* Peripheral State and Error functions ***************************************/

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdr_delay.c ***/
