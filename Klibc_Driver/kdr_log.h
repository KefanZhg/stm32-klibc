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
#define KDR_LOG_LEVEL_CRITICAL 0
#define KDR_LOG_LEVEL_ERROR    1
#define KDR_LOG_LEVEL_WARNING  2
#define KDR_LOG_LEVEL_INFO     3
#define KDR_LOG_LEVEL_DEBUG    4

/* Exported macros -----------------------------------------------------------*/
#define KDR_LOG_BASE printf

#define KDR_LOG_CRITICAL(fmt,...) \
  {if(KDR_LOG_LEVEL>=KDR_LOG_LEVEL_CRITICAL){KDR_LOG_BASE("[CRITICAL] %s,%d: " fmt "\r\n",  __FUNCTION__, __LINE__, ## __VA_ARGS__);}}

#define KDR_LOG_ERROR(fmt,...) \
  {if(KDR_LOG_LEVEL>=KDR_LOG_LEVEL_ERROR){KDR_LOG_BASE("[ERROR] %s,%d: " fmt "\r\n",  __FUNCTION__, __LINE__, ## __VA_ARGS__);}}

#define KDR_LOG_WARNING(fmt,...) \
  {if(KDR_LOG_LEVEL>=KDR_LOG_LEVEL_WARNING){KDR_LOG_BASE("[WARNING] %s,%d: " fmt "\r\n",  __FUNCTION__, __LINE__, ## __VA_ARGS__);}}
  
#define KDR_LOG_INFO(fmt,...) \
  {if(KDR_LOG_LEVEL>=KDR_LOG_LEVEL_INFO){KDR_LOG_BASE("[INFO] %s,%d: " fmt "\r\n",  __FUNCTION__, __LINE__, ## __VA_ARGS__);}}
  
#define KDR_LOG_DEBUG(fmt,...) \
  {if(KDR_LOG_LEVEL>=KDR_LOG_LEVEL_DEBUG){KDR_LOG_BASE("[DEBUG] %s,%d: " fmt "\r\n",  __FUNCTION__, __LINE__, ## __VA_ARGS__);}}

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
