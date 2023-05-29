/**
  ******************************************************************************
  * @date    May 22, 2023
  * @file    kdr_delay.h
  * @author  Kefan Zheng
  * @brief   
  * @version V0.0.0
  * @contact kirk_z@yeah.net
  @verbatim
  ==============================================================================
                        ##### How to use this driver #####
  ==============================================================================


  @endverbatim
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef KLIBC_DRIVER_KDR_DELAY_H_
#define KLIBC_DRIVER_KDR_DELAY_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kdr.h"
/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
void KDR_Delay(uint32_t us);
/* Initialization and de-initialization functions *****************************/

/* Configuration functions ****************************************************/

/* IO operation functions *****************************************************/
/* State and Error functions **************************************************/

/* Private functions ---------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  /* KLIBC_DRIVER_KDR_DELAY_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdr_delay.h ***/
