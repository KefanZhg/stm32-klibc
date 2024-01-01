/**
  ******************************************************************************
  * @date    Mar 18, 2023
  * @file    kdc.h
  * @author  Kefan Zheng
  * @brief   Basic file for Klibc Device library
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
#ifndef KDC_H_
#define KDC_H_

#ifdef __cplusplus
  extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "klibc.h"

/* Exported types ------------------------------------------------------------*/
typedef enum {
  KDC_PortNone = 0,
  KDC_PortRegular = 1,
  KDC_PortComplement = 2,
  KDC_PortBoth = 3
} KDC_TIM_Port_t;

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/

/* Configuration functions ****************************************************/

/* IO operation functions *****************************************************/
/* State and Error functions **************************************************/

/* Private functions ---------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  /* KDC_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc.h ***/
