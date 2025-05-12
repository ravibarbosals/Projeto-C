#include <stdlib.h>
#include <time.h>
#include "../include/screen.h"
#include "../include/keyboard.h"
#include "../include/timer.h"
#include "../include/jogo.h"

int main() {
    static int ch = 0;

    // Inicialização dos componentes
    srand(time(NULL));
    screenInit(1);
    keyboardInit();
    timerInit(50);
    screenUpdate();  // Atualiza a tela após a inicialização

    // Função que provavelmente contém a lógica do jogo
    executarJogo();

    // Continua até pressionar 'Enter' (código 10)
    while (ch != 10) {
        // Verifica se uma tecla foi pressionada
        if (keyhit()) {
            ch = readch();
            screenUpdate();  // Atualiza a tela após a tecla ser pressionada
        }

        // Verifica se o tempo foi esgotado
        if (timerTimeOver() == 1) {
            screenUpdate();
        }
    }

    // Destrói os componentes ao final
    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}
