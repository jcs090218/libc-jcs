#ifndef __JCS_DIR_H__
/**
 * $File: jcs_dir.h $
 * $Date: 2017-12-09 13:22:06 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */
#define __JCS_DIR_H__

#include <stddef.h>


/**
 * @func jcs_get_current_dir
 * @brief Get the current directory's file path.
 * @param { char } cwd : Char pointer to store..
 * @param { size_t } size : size of the buffer.
 */
void jcs_get_current_dir(char* str_ptr, const size_t size);

/**
 * @func jcs_list_directory
 * @brief List the target directory.
 * @param { char } filePath : file path.
 */
void jcs_list_directory(const char *filePath);

/**
 * @func jcs_safe_create_dir
 * @brief Safe way to create directory.
 * @param { char } filePath : file path.
 * @param { int } mod : directory mode.
 */
void jcs_safe_create_dir(const char* filePath, const int mod);

/**
 * @func jcs_safe_remove_dir
 * @brief Safe way to remove directory.
 * @param { char } filePath : file path.
 * @return { bool } : true, remove success. false, operate failed, did nothing.
 */
bool jcs_safe_remove_dir(const char* filePath);

/**
 * @func jcs_safe_create_dir_recursive
 * @brief Safe way to create directory recursively.
 * @param { char } filePath : file path.
 * @param { int } mod : directory mode.
 *
 * @url https://stackoverflow.com/questions/2336242/recursive-mkdir-system-call-on-unix
 */
void jcs_safe_create_dir_recursive(const char* filePath, const int mod);

/**
 * @func jcs_safe_remove_dir_recursive
 * @brief Safe way to remove directory recursively.
 * @param { char } filePath : file path.
 * @return { bool } : true, delete success. false, something went wrong.
 */
bool jcs_safe_remove_dir_recursive(const char* filePath);

/**
 * @func jcs_dir_exists
 * @brief Check if directory exists.
 * @param { char } filePath : file path to check.
 * @return { bool } : true, exists. false, not exists.
 */
bool jcs_dir_exists(const char *filePath);

/**
 * @func jcs_is_a_dir
 * @brief Check if is a directory.
 * @param { char } filePath : file path to check.
 * @return { bool } :
 * true, is a directory.
 * false, is a file or path does not exists.
 */
bool jcs_is_a_dir(const char *filePath);

#endif /* __JCS_DIR_H__ */
