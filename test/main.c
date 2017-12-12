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
    jcs_println("libc-jcs test start..");

    /*jcs_safe_create_dir_recursive("alright/cool/mem/script", 700);*/

    jcs_safe_remove_dir_recursive("./alright/cool");

    jcs_set_conio_terminal_mode();

    while (true) {
        /* do some work */
        if (jcs_kbhit()) {
            jcs_log("Break");
            break;
        }
    }
    jcs_getch(); /* consume the character */

    /* --------------- */
    return 0;
}
