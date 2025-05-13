#include <stdlib.h>
#include <time.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "jogo.h"

int main() {
    static int ch = 0;

    // Inicialização dos componentes
    srand(time(NULL));
    screenInit(1);
    keyboardInit();
    timerInit(50);
    screenUpdate();

    // Menu principal
    while (1) {
        screenClear();
        screenGotoxy(25, 5);
        printf("=== JOGO DE ADIVINHAÇÃO ===");
        screenGotoxy(25, 7);
        printf("1. Iniciar Jogo");
        screenGotoxy(25, 8);
        printf("2. Ver Ranking");
        screenGotoxy(25, 9);
        printf("3. Sair");
        screenGotoxy(25, 11);
        printf("Escolha uma opção: ");

        ch = readch();
        
        if (ch == '1') {
            executarJogo();
        } else if (ch == '2') {
            mostrarRanking();
        } else if (ch == '3') {
            break;
        }
    }

    // Destrói os componentes ao final
    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}