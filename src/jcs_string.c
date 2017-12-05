/**
 * $File: jcs_string.c $
 * $Date: 2017-12-05 16:28:02 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"


/**
 * @func jcs_strcmp
 * @brief Function description here..
 * @param { char } str1 : Param desc here..
 * @param { char } str2 : Param desc here..
 * @return { bool } : Returns description here..
 */
bool jcs_strcmp(char *str1, char *str2) {
    if (strcmp(str1, str2) == 0)
        return true;
    return false;
}
