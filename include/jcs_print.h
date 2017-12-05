#ifndef __JCS_PRINT_H__
/**
 * $File: jcs_print.h $
 * $Date: 2017-12-05 16:12:17 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */
#define __JCS_PRINT_H__


#include <stdio.h>
#include <stdarg.h>


/**
 * @func jcs_printf
 * @brief JCS version of printf.
 * @param { char } fmt : Arguments.
 */
void jcs_printf(const char *fmt, ...);

#endif /* __JCS_PRINT_H__ */
