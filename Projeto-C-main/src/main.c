#include <stdlib.h>
#include <stdio.h>    // Adicionado para printf
#include <time.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "jogo.h"

int main() {
    // Inicialização
    screenInit(1);
    keyboardInit();
    
    int ch;
    while(1) {
        printf("\033[32m"); // Código ANSI para texto verde
        screenClear();
        screenGotoxy(1, 1);
        printf("=== CODE RIDDLER ===");
        screenGotoxy(1, 3);
        printf("1. Iniciar Jogo");
        screenGotoxy(1, 4);
        printf("2. Ver Ranking");
        screenGotoxy(1, 5);
        printf("3. Sair");
        screenGotoxy(1, 7);
        printf("Escolha uma opção: ");
        fflush(stdout);

        while(!keyhit()); // Espera até que uma tecla seja pressionada
        ch = readch();
        
        // Processa a escolha
        switch(ch) {
            case '1':
                executarJogo();
                break;
            case '2':
                mostrarRanking();
                break;
            case '3':
                keyboardDestroy();
                screenDestroy();
                return 0;
        }
    }
}