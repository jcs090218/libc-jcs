/**
 * $File: jcs_file.c $
 * $Date: 2017-12-05 16:41:28 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"


/**
 * @func jcs_write_data
 * @brief Write data to file.
 * @param { void } ptr : This is the pointer to the array of elements to be written.
 * @param { size_t } size : This is the size in bytes of each element to be written.
 * @param { size_t } nmemb : This is the number of elements, each one with a size of size bytes.
 * @param { FILE } stream : This is the pointer to a FILE object that specifies an output stream.
 * @return { size_t } : This function returns the total number of
 *  elements successfully returned as a size_t object, which is
 *  an integral data type. If this number differs from the nmemb
 *  parameter, it will show an error.
 */
size_t jcs_write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

/**
 * @func jcs_write_to_file
 * @brief Simply write something to file.
 * @param { char } filePath : file path.
 * @param { char } str : string to write.
 */
void jcs_write_to_file(const char *filePath, const char* str) {
    FILE *fp;
    fp = fopen(filePath, "w");
    fprintf(fp, str);
    fclose(fp);
}

/**
 * @func jcs_append_to_file
 * @brief Simply append text to file.
 * @param { char } filePath : file path.
 * @param { char } str : string to write.
 */
void jcs_append_to_file(const char *filePath, const char *str) {
    FILE *fp;
    fp = fopen(filePath, "a");
    fprintf(fp, str);
    fclose(fp);
}

/**
 * @func jcs_print_file
 * @brief Read the file and print it on the screen.
 * @param { char } filePath : file path.
 * @return { bool } : true, print file success. false, vice versa.
 */
bool jcs_print_file(const char *filePath) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    ssize_t read;

    fp = fopen(filePath, "r");
    if (fp == NULL) {
        jcs_log("Cannot print without the file...");
        return false;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        jcs_printf("%s", line);
    }

    fclose(fp);

    if (line)
        free(line);

    return true;
}

/**
 * @func jcs_get_file_size
 * @brief Get the file size.
 * @param { char } filePath : file path.
 * @return { size_t } : size of the file.
 */
size_t jcs_get_file_size(const char *filename) {
    struct stat st;

    if (stat(filename, &st) == 0)
        return st.st_size;
    return -1;
}

/**
 * @func jcs_read_file
 * @brief Read the file and store it as a buffer.
 * @param { char } filePath : file path.
 * @param { char } buffer : buffer to store content.
 * @return { char } : buffer, this need to be free.
 *
 * @attention buffer, this need to be free.
 * @example
 * char* buffer;
 * buffer = jcs_read_file(filePath);
 * free(buffer);
 */
char* jcs_read_file(const char *filePath) {
    FILE *fp;
    size_t len;
    char *buffer;

    fp = fopen(filePath, "rb");
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    rewind(fp);

    buffer = (char*)malloc((len * sizeof(char)) + 1);
    fread(buffer, 1, len, fp);

    /* Add null terminator. */
    /* buffer[len] = '\0'; */
    /* OR */
    *(buffer + len) = '\0';

    fclose(fp);
    return buffer;
}

/**
 * @func jcs_file_exists
 * @brief Check if the file exists.
 * @param { char } filePath : file path.
 * @return { bool } : true, file exists. false, file does not exists.
 */
bool jcs_file_exists(const char *filePath) {
    return (access(filePath, F_OK) != -1);
}

/**
 * @func jcs_safe_remove_file
 * @brief Safe way to delete file.
 * @param { char } file : file path.
 * @return { bool } : true, delete successfully. false, vice versa.
 */
bool jcs_safe_remove_file(const char *file) {
    int result = remove(file);
    return !jcs_has_error(result);
}

/**
 * @func jcs_is_a_file
 * @brief Check if the path a file or directory.
 * @param { char } filePath : file path to check.
 * @return { bool } : true, is a file. false, is a directory.
 */
bool jcs_is_a_file(const char* filePath) {
    struct stat path_stat;
    stat(filePath, &path_stat);
    return (S_ISREG(path_stat.st_mode) != 0);
}
