/**
 * keyboard.h
 * Created on Aug 23rd, 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
 * 
 * This header provides basic keyboard input functionality
 * for Windows using <conio.h> and for Unix-like systems using <termios>.
 */

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initializes keyboard input system.
 * For Windows, this may be left empty or use <conio.h> functions.
 * For Unix-like systems, this may involve configuring terminal settings.
 */
void keyboardInit();

/**
 * Restores keyboard input system.
 * For Windows, this may be left empty.
 * For Unix-like systems, restores terminal settings.
 */
void keyboardDestroy();

/**
 * Checks if a key has been pressed.
 * For Windows, uses kbhit() from <conio.h>.
 * For Unix-like systems, uses termios to check input.
 * @return non-zero if a key is available to read, 0 otherwise.
 */
int keyhit();

/**
 * Reads a character from keyboard input (non-blocking).
 * For Windows, uses getch() from <conio.h>.
 * For Unix-like systems, uses read() with termios for non-blocking input.
 * @return the character read from input.
 */
int readch();

#ifdef __cplusplus
}
#endif

#endif /* __KEYBOARD_H__ */
