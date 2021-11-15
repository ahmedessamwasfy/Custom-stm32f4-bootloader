/*******************************************************************************
 * @file    memcpy.h
  * @author  Ahmed Wasfy
 * @email   ahmedessam0128@gmail.com
 * @date    10.04.2020
 *
 * @brief   Copy data between two memory buffers
 * @note
 *
*******************************************************************************/

/* Define to prevent recursive inclusion */
#ifndef __INC_MEMCPY_H_
#define __INC_MEMCPY_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"

/**
 * @addtogroup stm32_examples
 * @{
 */

/**
 * @addtogroup memcpy
 * @{
 */

/**
 * @defgroup memcpy_exported_typedefs
 * @{
 */

/**
 * @brief   Return type
 */
typedef enum
{
  RETURN_STATUS_OK = 0u,
  RETURN_STATUS_NOT_OK = 1u
} ReturnStatus_Type;

/**
 * @}
 */

/**
 * @defgroup memcpy_exported_defines
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup memcpy_exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup memcpy_exported_constants
 * @{
 */

/**
 * @}
 */

/**
 * @defgroup memcpy_exported_functions
 * @{
 */

/**
 * @brief   Copy data between two memory buffers
 * @note
 * @param   src, dst, size
 * @retval  RETURN_STATUS_OK, RETURN_STATUS_NOT_OK
 */
ReturnStatus_Type memcpy32(const uint32_t * src,
    uint32_t * dst, const uint32_t size);

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /*__INC_MEMCPY_H_ */
