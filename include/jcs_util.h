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
 * @func jcs_get_current_dir
 * @brief Get the current directory's file path.
 * @param { char } cwd : Char pointer to store..
 * @param { size_t } size : size of the buffer.
 */
void jcs_get_current_dir(char* str_ptr, const size_t size);

/**
 * @func jcs_is_safe_command
 * @brief Check if the command is safe to use.
 * @param { int } commandc : command count.
 * @param { char } command_id : command index.
 * @return { bool } : true, is safe. false, not safe.
 */
bool jcs_is_safe_command(const int commandc, const int command_id);

#endif /* __JCS_UTIL_H__ */
