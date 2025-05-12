#ifndef __TIMER_H__
#define __TIMER_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#include <windows.h> // Necessário para Windows
#else
#include <sys/time.h> // Necessário para Unix-like
#endif

/**
 * Initializes the timer with a given duration in milliseconds.
 * @param valueMilliSec Duration of the timer in milliseconds.
 */
void timerInit(int valueMilliSec);

/**
 * Destroys or disables the timer.
 */
void timerDestroy();

/**
 * Updates the timer value.
 * @param valueMilliSec New duration in milliseconds.
 */
void timerUpdateTimer(int valueMilliSec);

/**
 * Checks whether the timer has expired.
 * @return Non-zero if the timer has finished, zero otherwise.
 */
int timerTimeOver();

/**
 * Prints the remaining time (for debugging or display purposes).
 */
void timerPrint();

#ifdef __cplusplus
}
#endif

#endif /* __TIMER_H__ */
