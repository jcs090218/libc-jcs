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
 * @func jcs_list_directory
 * @brief List the target directory.
 * @param { char } filePath : file path.
 */
void jcs_list_directory(const char *filePath) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(filePath)) == NULL) {
        jcs_error("Cannot open the target directory..");
        return;
    }

    while ((ent = readdir(dir)) != NULL) {
        jcs_println("%s", ent->d_name);
    }
}

/**
 * @func jcs_get_current_dir
 * @brief Get the current directory's file path.
 * @param { char } cwd : Char pointer to store..
 * @param { size_t } size : size of the buffer.
 */
void jcs_get_current_dir(char* str_ptr, const size_t size) {
    if (getcwd(str_ptr, size) != NULL)
        return;

    jcs_log("Failed to get current directory for some reason...");
}

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
 * @func jcs_safe_remove_dir
 * @brief Safe way to remove directory.
 * @param { char } filePath : file path.
 * @return { bool } : true, remove success. false, operate failed, did nothing.
 */
bool jcs_safe_remove_dir(const char* filePath) {
    int result = rmdir(filePath);
    return (result == 0);
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
        /* Check if reach another directory. */
        if (*p != '/')
            continue;

        *p = 0;
        jcs_safe_create_dir(tmp, mod);
        *p = '/';
    }
    jcs_safe_create_dir(tmp, mod);
}

/**
 * @func jcs_safe_remove_dir_recursive
 * @brief Safe way to remove directory recursively.
 * @param { char } filePath : file path.
 * @return { bool } : true, delete success. false, something went wrong.
 */
bool jcs_safe_remove_dir_recursive(const char* filePath) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(filePath)) == NULL) {
        return false;
    }

    /* Loop through all the files/directories and delete them all. */
    while ((ent = readdir(dir)) != NULL) {
        /* Ignore the current and up one directory symbols. */
        if (jcs_strcmp(ent->d_name, ".") ||
            jcs_strcmp(ent->d_name, ".."))
            continue;

        /*
         * Get the temprary file path for each file/directory in this
         * file path.
         */
        char tmpPath[PATH_MAX];
        snprintf(tmpPath,
                 sizeof(tmpPath),
                 "%s/%s",
                 filePath,
                 ent->d_name);

        /* Delete file if file. */
        if (jcs_is_a_file(tmpPath)) {
            if (jcs_safe_remove_file(tmpPath)) {
                continue;
            } else {
                jcs_error("Cannot remove a file inside the folder...");
                return false;
            }
        }

        /* Delete directory if directory. */
        if (jcs_is_a_dir(tmpPath)) {
            if (jcs_safe_remove_dir(tmpPath)) {
                continue;
            } else {
                jcs_safe_remove_dir_recursive(tmpPath);
            }
        }
    }

    jcs_safe_remove_dir(filePath);
    return true;
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

/**
 * @func jcs_is_a_dir
 * @brief Check if is a directory.
 * @param { char } filePath : file path to check.
 * @return { bool } :
 * true, is a directory.
 * false, is a file or path does not exists.
 */
bool jcs_is_a_dir(const char *filePath) {
    struct stat path_stat;
    stat(filePath, &path_stat);
    return (S_ISDIR(path_stat.st_mode) != 0);
}
