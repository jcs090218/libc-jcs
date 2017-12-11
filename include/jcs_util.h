#ifndef __JCS_UTIL_H__
/**
 * $File: jcs_util.h $
 * $Date: 2017-12-04 08:06:48 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */
#define __JCS_UTIL_H__

#include <stddef.h>


/**
 * @func jcs_is_safe_command
 * @brief Check if the command is safe to use.
 * @param { int } commandc : command count.
 * @param { char } command_id : command index.
 * @return { bool } : true, is safe. false, not safe.
 */
bool jcs_is_safe_command(const int commandc, const int command_id);

/**
 * @func jcs_has_error
 * @brief Check if current error code is an error error code.
 * @param { int } result : result from a function.
 * @return { bool } : true, has error. false, no error.
 */
bool jcs_has_error(const int result);

/**
 * @func jcs_is_debug_mode
 * @brief Check if current build target a debug buffer.
 * @return { bool } : true, debug mode. false, release mode.
 */
bool jcs_is_debug_mode(void);


#endif /* __JCS_UTIL_H__ */
