/**
 * $File: jcs_dir.c $
 * $Date: 2017-12-09 13:22:24 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"


/**
 * @func jcs_safe_create_dir
 * @brief Safe way to create directory.
 * @param { char } filePath : file path.
 */
void jcs_safe_create_dir(const char* filePath, const int mod) {
    if (jcs_dir_exists(filePath)) {
        jcs_log("Failed to create directory, file already exists...");
        return;
    }
    mkdir(filePath, mod);
}


/**
 * @func jcs_safe_create_dir_recursive
 * @brief Safe way to create directory recursively.
 * @param { char } filePath : file path.
 * @param { int } mod : directory mode.
 *
 * @url https://stackoverflow.com/questions/2336242/recursive-mkdir-system-call-on-unix
 */
void jcs_safe_create_dir_recursive(const char* filePath, const int mod) {
    char tmp[PATH_MAX];
    char *p = NULL;
    size_t len;

    snprintf(tmp, sizeof(tmp), "%s", filePath);
    len = strlen(tmp);

    if (tmp[len - 1] == '/')
        tmp[len - 1] = 0;

    for (p = tmp + 1;
         *p;
         p++) {
        if (*p != '/')
            continue;

        *p = 0;
        jcs_safe_create_dir(tmp, mod);
        *p = '/';
    }
    jcs_safe_create_dir(tmp, mod);
}

/**
 * @func jcs_dir_exists
 * @brief Check if directory exists.
 * @param { char } filePath : file path to check.
 * @return { bool } : true, exists. false, not exists.
 */
bool jcs_dir_exists(const char *filePath) {
    struct stat st = {0};

    if (stat(filePath, &st) == -1)
        return false;
    return true;
}
