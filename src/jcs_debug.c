/**
 * $File: jcs_debug.c $
 * $Date: 2017-12-04 15:48:46 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"

/**
 * @func jcs_vlog
 * @brief Log out using JCS lib format.
 * @param { char } fmt : format string.
 * @param { va_list } argp : Arguments.
 */
PRIVATE void jcs_vlog(const char *fmt, va_list argp) {
    fprintf(stdout, JCS_ANSI_COLOR_GREEN "** \n");
    fprintf(stdout, "* Log - ");
    vfprintf(stdout, fmt, argp);
    fprintf(stdout, "** \n" JCS_ANSI_COLOR_RESET);
}

/**
 * @func jcs_verror
 * @brief Error output using JCS lib format.
 * @param { char } fmt : format string.
 * @param { va_list } argp : Arguments list.
 */
PRIVATE void jcs_verror(const char *fmt, va_list argp) {
    fprintf(stdout, JCS_ANSI_COLOR_RED "** \n");
    fprintf(stdout, "* Error - ");
    vfprintf(stdout, fmt, argp);
    fprintf(stdout, "** \n" JCS_ANSI_COLOR_RESET);
}

/**
 * @func jcs_vwarning
 * @brief Warning output using JCS lib format.
 * @param { char } fmt : format string.
 * @param { va_list } argp : Arguments list.
 */
PRIVATE void jcs_vwarning(const char *fmt, va_list argp) {
    fprintf(stdout, JCS_ANSI_COLOR_YELLOW "** \n");
    fprintf(stdout, "* Warning - ");
    vfprintf(stdout, fmt, argp);
    fprintf(stdout, "**\n" JCS_ANSI_COLOR_RESET);
}


/**
 * @func jcs_log
 * @brief Log out using JCS lib format.
 * @param { char } fmt : format string.
 * @param { va_list } argp : Arguments.
 */
void jcs_log(const char *fmt, ...) {
    va_list argp;
    va_start(argp, fmt);
    jcs_vlog(fmt, argp);
    va_end(argp);
}

/**
 * @func jcs_error
 * @brief Error output using JCS lib format.
 * @param { char } fmt : format string.
 */
void jcs_error(const char *fmt, ...) {
    va_list argp;
    va_start(argp, fmt);
    jcs_verror(fmt, argp);
    va_end(argp);
}

/**
 * @func jcs_warning
 * @brief Warning output using JCS lib format.
 * @param { char } fmt : format string.
 */
void jcs_warning(const char *fmt, ...) {
    va_list argp;
    va_start(argp, fmt);
    jcs_vwarning(fmt, argp);
    va_end(argp);
}
