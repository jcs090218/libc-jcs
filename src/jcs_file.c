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
 */
void jcs_print_file(const char *filePath) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    ssize_t read;

    fp = fopen(filePath, "r");
    if (fp == NULL) {
        jcs_log("Cannot print the with no such a file...");
        return;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        jcs_printf("%s", line);
    }

    fclose(fp);

    if (line)
        free(line);
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
