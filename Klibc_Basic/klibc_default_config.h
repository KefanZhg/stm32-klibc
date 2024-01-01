/**
  ******************************************************************************
  * @date    Jan 1, 2024
  * @file    klibc_config.h
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
#ifndef KLIBC_DEFAULT_CONFIG_H_
#define KLIBC_DEFAULT_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "klibc_config.h"


/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
#ifndef KLIBC_DEFAULT_TIMEOUT
#define KLIBC_DEFAULT_TIMEOUT 0xFF
#endif /* KLIBC_DEFAULT_TIMEOUT */


#ifndef KDR_LOG_PORT
#define KDR_LOG_PORT huart1
#endif /* KDR_LOG_PORT */

#ifndef KDR_LOG_LEVEL
#define KDR_LOG_LEVEL KDR_LOG_LEVEL_INFO
#endif /* KDR_LOG_LEVEL */

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

#endif  /* KLIBC_DEFAULT_CONFIG_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE klibc_default_config.h ***/
