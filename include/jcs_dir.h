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


/**
 * @func jcs_safe_create_dir
 * @brief Safe way to create directory.
 * @param { char } filePath : file path.
 * @param { int } mod : directory mode.
 */
void jcs_safe_create_dir(const char* filePath, const int mod);

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
 * @func jcs_dir_exists
 * @brief Check if directory exists.
 * @param { char } filePath : file path to check.
 * @return { bool } : true, exists. false, not exists.
 */
bool jcs_dir_exists(const char *filePath);

#endif /* __JCS_DIR_H__ */
