/**
 * $File: jcs_print.c $
 * $Date: 2017-12-05 16:12:58 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"


/**
 * @func jcs_vprintf
 * @brief JCS version of printf.
 * @param { char } fmt : format string.
 * @param { va_list } argp : Arguments.
 */
PRIVATE void jcs_vprintf(const char *fmt, va_list argp) {
    vfprintf(stdout, fmt, argp);
}

/**
 * @func jcs_printf
 * @brief JCS version of printf.
 * @param { char } fmt : Arguments.
 */
void jcs_printf(const char *fmt, ...) {
    va_list argp;
    va_start(argp, fmt);
    jcs_vprintf(fmt, argp);
    va_end(argp);
}
