/**
 * keyboard.h
 * Created on Aug 23rd, 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
 * 
 * This header provides basic keyboard input functionality
 * for Windows using <conio.h>
 */

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initializes keyboard input system.
 */
void keyboardInit();

/**
 * Restores keyboard input system.
 */
void keyboardDestroy();

/**
 * Checks if a key has been pressed.
 * @return non-zero if a key is available to read, 0 otherwise.
 */
int keyhit();

/**
 * Reads a character from keyboard input.
 * @return the character read from input.
 */
int readch();

#ifdef __cplusplus
}
#endif

#endif /* __KEYBOARD_H__ */
