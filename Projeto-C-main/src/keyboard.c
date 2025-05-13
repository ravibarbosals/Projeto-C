/**
 * keyboard.c - Versão corrigida para Linux/WSL
 */
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include "keyboard.h"

static struct termios oldt, newt;

void keyboardInit() {
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void keyboardDestroy() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int keyhit() {
    struct timeval tv = {0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO+1, &fds, NULL, NULL, &tv) > 0;
}

int readch() {
    int ch;
    ch = getchar();
    return ch;
}