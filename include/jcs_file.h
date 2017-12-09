#ifndef __JCS_FILE_H__
/**
 * $File: jcs_file.h $
 * $Date: 2017-12-05 16:39:09 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */
#define __JCS_FILE_H__

#include <stdio.h>


/**
 * @func jcs_write_to_file
 * @brief Simply write text to file.
 * @param { char } filePath : file path.
 * @param { char } str : string to write.
 */
void jcs_write_to_file(const char *filePath, const char *str);

/**
 * @func jcs_append_to_file
 * @brief Simply append text to file.
 * @param { char } filePath : file path.
 * @param { char } str : string to write.
 */
void jcs_append_to_file(const char *filePath, const char *str);

/**
 * @func jcs_print_file
 * @brief Read the file and print it on the screen.
 * @param { char } filePath : file path.
 */
void jcs_print_file(const char *filePath);

/**
 * @func jcs_read_file
 * @brief Read the file and store it as a buffer.
 * @param { char } filePath : file path.
 * @param { char } buffer : buffer to store content.
 * @return { char } : buffer, this need to be free.
 */
char* jcs_read_file(const char *filePath);

/**
 * @func jcs_get_file_size
 * @brief Get the file size.
 * @param { char } filePath : file path.
 * @return { size_t } : size of the file.
 */
size_t jcs_get_file_size(const char *filePath);

/**
 * @func jcs_file_exists
 * @brief Check if the file exists.
 * @param { char } filePath : file path.
 * @return { bool } : true, file exists. false, file does not exists.
 */
bool jcs_file_exists(const char *filePath);

#endif /* __JCS_FILE_H__ */
