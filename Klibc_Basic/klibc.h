/**
  ******************************************************************************
  * @date    Jan 1, 2024
  * @file    klibc.h
  * @author  Kefan Zheng
  * @brief   
  * @version V0.0.0
  * @contact kirk_z@yeah.net
  * @verbatim
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
#ifndef KLIBC_H_
#define KLIBC_H_

#ifdef __cplusplus
  extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "klibc_default_config.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
#define KLIBC_ERROR_BASE (0x0000)

#define KLIBC_SUCCESS                       (KLIBC_ERROR_BASE + 0)
#define KLIBC_ERROR_UNSPECIFIED             (KLIBC_ERROR_BASE + 1)
#define KLIBC_ERROR_BUSY                    (KLIBC_ERROR_BASE + 2)
#define KLIBC_ERROR_TIMEOUT                 (KLIBC_ERROR_BASE + 3)



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

#endif  /* KLIBC_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE klibc.h ***/
