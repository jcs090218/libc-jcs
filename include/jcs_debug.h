#ifndef __JCS_DEBUG_H__
/**
 * $File: jcs_debug.h $
 * $Date: 2017-12-04 15:48:01 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */
#define __JCS_DEBUG_H__

/*
 * varag handoff
 * URL(jenchieh): http://c-faq.com/varargs/handoff.html
 */


#include "../libc_jcs.h"


/**
 * @func jcs_vlog
 * @brief Log out using JCS lib format.
 * @param { char } fmt : format string.
 * @param { va_list } argp : Arguments list.
 */
PRIVATE void jcs_vlog(const char *fmt, va_list argp);

/**
 * @func jcs_verror
 * @brief Error output using JCS lib format.
 * @param { char } fmt : format string.
 * @param { va_list } argp : Arguments list.
 */
PRIVATE void jcs_verror(const char *fmt, va_list argp);

/**
 * @func jcs_vwarning
 * @brief Warning output using JCS lib format.
 * @param { char } fmt : format string.
 * @param { va_list } argp : Arguments list.
 */
PRIVATE void jcs_vwarning(const char *fmt, va_list argp);


/**
 * @func jcs_log
 * @brief Log out using JCS lib format.
 * @param { char } fmt : format string.
 * @param { va_list } argp : Arguments.
 */
void jcs_log(const char *fmt, ...);

/**
 * @func jcs_error
 * @brief Error output using JCS lib format.
 * @param { char } fmt : format string.
 */
void jcs_error(const char *fmt, ...);

/**
 * @func jcs_warning
 * @brief Warning output using JCS lib format.
 * @param { char } fmt : format string.
 */
void jcs_warning(const char *fmt, ...);


#endif /* __JCS_DEBUG_H__ */
