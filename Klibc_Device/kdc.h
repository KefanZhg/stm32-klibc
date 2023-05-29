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
#include "main.h"
/* Exported types ------------------------------------------------------------*/
/**
 * @brief  enum of KDC status
*/
typedef enum {
  KDC_OK       = 0x00,
  KDC_ERROR    = 0x01,
  KDC_BUSY     = 0x02,
  KDC_TIMEOUT  = 0x03,
} KDC_State_t;

/* Exported constants --------------------------------------------------------*/
#define KDC_DEFAULT_TIMEOUT 0xFF

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
