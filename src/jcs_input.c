/**
 * $File: jcs_input.c $
 * $Date: 2017-12-12 16:16:17 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"

/**
 * TOPIC(jenchieh): C non-blocking keyboard input
 * SOURCE(jenchieh): https://stackoverflow.com/questions/448944/c-non-blocking-keyboard-input
 */


struct termios orig_termios;

/**
 * @func jcs_reset_terminal_mode
 * @brief Reset terminal mode.
 */
void jcs_reset_terminal_mode(void) {
    tcsetattr(0, TCSANOW, &orig_termios);
}

/**
 * @func jcs_set_conio_terminal_mode
 * @brief Set conio terminal mode.
 */
void jcs_set_conio_terminal_mode(void) {
    struct termios new_termios;

    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    /* register cleanup handler, and set the new terminal mode */
    atexit(jcs_reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}

/**
 * @func jcs_kbhit
 * @brief Check if keyboard is hit.
 * @return { int } : keycode.
 */
int jcs_kbhit(void) {
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

/**
 * @func jcs_getch
 * @brief Get a character.
 * @return { int } : character code.
 */
int jcs_getch(void) {
    int r;
    unsigned char c;
    if ((r = read(0, &c, sizeof(c))) < 0) {
        return r;
    } else {
        return c;
    }
}
