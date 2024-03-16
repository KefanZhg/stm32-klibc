/**
  ******************************************************************************
  * @date    Mar 19, 2023
  * @file    kdr_math.h
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
#ifndef KDR_MATH_H_
#define KDR_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kdr.h"
#include "math.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
extern const uint32_t KDR_MATH_BIT_TRIANGLE[];

/* Exported macros -----------------------------------------------------------*/

#define KD_Math_Max(a,b) ((a)>(b)?(a):(b))
#define KD_Math_Min(a,b) ((a)<(b)?(a):(b))

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
uint8_t KDR_MATH_LSB_Index(uint32_t num);
/* Initialization and de-initialization functions *****************************/

/* Configuration functions ****************************************************/

/* IO operation functions *****************************************************/
/* State and Error functions **************************************************/

/* Private functions ---------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  /* KDR_MATH_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdr_math.h ***/
