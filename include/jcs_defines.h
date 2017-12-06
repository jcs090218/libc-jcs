#ifndef __JCS_DEFINES_H__
/**
 * $File: jcs_defines.h $
 * $Date: 2017-12-04 08:22:55 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */
#define __JCS_DEFINES_H__


#include <stdint.h>


#define PUBLIC
#define PRIVATE static

/**
 * @def JCS_HAS_ERROR
 * @brief Use to check if has an error flag.
 */
#define JCS_HAS_ERROR -1
/**
 * @def JCS_NO_ERROR
 * @brief No error flag, meaning is safe.
 */
#define JCS_NO_ERROR 0

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef float float32;

#endif /* __JCS_DEFINES_H__ */
