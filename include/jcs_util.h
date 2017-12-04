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


/**
 * @func jcs_safe_create_dir
 * @brief Safe way to create directory.
 * @param { char } filePath : file path.
 * @param { int } mod : directory mode.
 */
void jcs_safe_create_dir(char* filePath, int mod);

/**
 * @func jcs_dir_exists
 * @brief Check if directory exists.
 * @param { char } filePath : file path to check.
 * @return { bool } : ture, exists. false, not exists.
 */
bool jcs_dir_exists(char *filePath);

/**
 * @func jcs_strcmp
 * @brief Compare two string.
 * @param { char } str1 : string 1.
 * @param { char } str2 : string 2.
 * @return { bool } : true, if the equal. false, vice versa.
 */
bool jcs_strcmp(char *str1, char *str2);

/**
 * @func jcs_is_safe_command
 * @brief Check if the command is safe to use.
 * @param { int } commandc : command count.
 * @param { char } command_id : command index.
 * @return { bool } : true, is safe. false, not safe.
 */
bool jcs_is_safe_command(int commandc, int command_id);

#endif /* __JCS_UTIL_H__ */
