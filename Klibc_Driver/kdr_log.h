/**
  ******************************************************************************
  * @date    May 28, 2023
  * @file    kdr_log.h
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
  * This library will be used for printing log and debugging. Currently, only
  * the function for printing is defined for complete examples. I will finish
  * the library later.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef KDR_LOG_H_
#define KDR_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kdr.h"
#include "stdio.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
#ifdef DEBUG
#define KDR_LOG_Printf(intf,fmt,...) \
	printf("[LOG] %s:%s,%d:\t" fmt, __FILE__, __FUNCTION__, __LINE__, ## __VA_ARGS__)
#else
#define KDR_LOG_Printf(intf,fmt,...) \
	printf("[LOG]" fmt, ## __VA_ARGS__)
#endif
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

#endif  /* KDR_LOG_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdr_log.h ***/
