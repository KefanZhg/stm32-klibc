/**
  ******************************************************************************
  * @date    Mar 18, 2023
  * @file    kdr.h
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
#ifndef KDR_H_
#define KDR_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/
/**
 * @brief  enum of KDR status
*/
typedef enum {
	KDR_OK       = 0x00,
	KDR_ERROR    = 0x01,
	KDR_BUSY     = 0x02,
	KDR_TIMEOUT  = 0x03,
} KDR_State_t;

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

#endif  /* KDR_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdr.h ***/
