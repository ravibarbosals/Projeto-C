#include <stdlib.h>
#include <time.h>
#include "../include/screen.h"
#include "../include/keyboard.h"
#include "../include/timer.h"
#include "../include/jogo.h"

int main() {
    static int ch = 0;

    srand(time(NULL));

    screenInit(1);
    keyboardInit();
    timerInit(50);
    screenUpdate();

    executarJogo();

    while (ch != 10) {
        if (keyhit()) {
            ch = readch();
            screenUpdate();
        }

        if (timerTimeOver() == 1) {
            screenUpdate();
        }
    }

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}