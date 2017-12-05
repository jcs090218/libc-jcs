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
 * @struct stat
 * @brief State to check if the directory exists.
 */
struct stat jcs_st = {0};


/**
 * @func jcs_get_current_dir
 * @brief Get the current directory's file path.
 * @param { char } cwd : Char pointer to store..
 */
void jcs_get_current_dir(char* str_ptr, size_t size) {
    if (getcwd(str_ptr, size) != NULL)
        return;

    jcs_log("Failed to get current directory for some reason...");
}

/**
 * @func jcs_safe_create_dir
 * @brief Safe way to create directory.
 * @param { char } filePath : file path.
 */
void jcs_safe_create_dir(char* filePath, int mod) {
    if (stat(filePath, &jcs_st) == -1) {
        mkdir(filePath, mod);
    }
}

/**
 * @func jcs_dir_exists
 * @brief Check if directory exists.
 * @param { char } filePath : file path to check.
 * @return { bool } : ture, exists. false, not exists.
 */
bool jcs_dir_exists(char *filePath) {
    if (stat(filePath, &jcs_st) == -1)
        return false;
    return true;
}

/**
 * @func jcs_is_safe_command
 * @brief Check if the command is safe to use.
 * @param { int } commandc : command count.
 * @param { char } command_id : command index.
 * @return { bool } : true, is safe. false, not safe.
 */
bool jcs_is_safe_command(int commandc, int command_id) {
    if (commandc > command_id)
        return true;
    return false;
}
