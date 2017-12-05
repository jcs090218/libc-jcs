/**
 * $File: main.c $
 * $Date: 2017-12-04 08:01:00 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"


/**
 * @func main
 * @brief Program Entry Point.
 * @param { int } argc : argument count.
 * @param { char } argv : argument vector.
 * @return { int } : 0, exit success. -1, exit failure.
 */
int main(int argc, char *argv[]) {

    printf("libc-jcs test start..\n");

    char current_dir[1024];
    jcs_get_current_dir(current_dir, sizeof(current_dir));

    printf("\n\nCurrent working dir: %s\n\n", current_dir);

    jcs_log("Hello World\n");
    jcs_error("Hello World\n");
    jcs_warning("Hello World\n");
    jcs_error("Hello World\n");

    /* --------------- */
    return 0;
}
