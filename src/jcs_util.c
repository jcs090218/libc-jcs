/**
 * $File: jcs_util.c $
 * $Date: 2017-12-04 08:06:38 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"


/**
 * @func jcs_is_safe_command
 * @brief Check if the command is safe to use.
 * @param { int } commandc : command count.
 * @param { char } command_id : command index.
 * @return { bool } : true, is safe. false, not safe.
 */
bool jcs_is_safe_command(const int commandc, const int command_id) {
    if (commandc > command_id)
        return true;
    return false;
}

/**
 * @func jcs_has_error
 * @brief Check if current error code is an error error code.
 * @param { int } result : result from a function.
 * @return { bool } : true, has error. false, no error.
 */
bool jcs_has_error(const int result) {
    if (result == JCS_NO_ERROR)
        return false;
    return true;
}

/**
 * @func jcs_is_debug_mode
 * @brief Check if current build target a debug buffer.
 * @return { bool } : true, debug mode. false, release mode.
 */
bool jcs_is_debug_mode(void) {
    if (JCS_DEBUG == 0)
        return false;
    return true;
}
