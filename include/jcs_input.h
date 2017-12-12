#ifndef __JCS_INPUT_H__
/**
 * $File: jcs_input.h $
 * $Date: 2017-12-12 16:14:41 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */
#define __JCS_INPUT_H__



/**
 * @func jcs_reset_terminal_mode
 * @brief Reset terminal mode.
 */
void jcs_reset_terminal_mode(void);

/**
 * @func jcs_set_conio_terminal_mode
 * @brief Set conio terminal mode.
 */
void jcs_set_conio_terminal_mode(void);

/**
 * @func jcs_kbhit
 * @brief Check if keyboard is hit.
 * @return { int } : keycode.
 */
int jcs_kbhit(void);

/**
 * @func jcs_getch
 * @brief Get a character.
 * @return { int } : character code.
 */
int jcs_getch(void);

#endif /* __JCS_INPUT_H__ */
