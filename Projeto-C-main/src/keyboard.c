/**
 * keyboard.c
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
 */

#include <conio.h>    // Para _kbhit() e _getch()
#include <windows.h>  // Para a API de console do Windows
#include "keyboard.h"

// Variáveis globais
static int peekCharacter = -1;  // Inicializa com -1

/**
 * Função para inicializar o modo de leitura do teclado no Windows.
 * Não é necessário modificar o terminal como no Unix.
 */
void keyboardInit() {
    // No Windows, não há necessidade de alterar as configurações do terminal
    // A leitura de teclado já é feita sem bloqueio por padrão com _kbhit() e _getch()
}

/**
 * Função para restaurar o estado inicial.
 * No Windows, como não alteramos o terminal, esta função não é necessária.
 */
void keyboardDestroy() {
    // No Windows, não é necessário restaurar nada
}

/**
 * Função para verificar se uma tecla foi pressionada.
 * Retorna 1 se houver uma tecla pressionada, 0 caso contrário.
 */
int keyhit() {
    // Verifica se há uma tecla pressionada usando _kbhit()
    if (_kbhit()) {
        // Se houver, retorna 1 (indicando que uma tecla foi pressionada)
        peekCharacter = _getch();  // Armazena a tecla pressionada
        return 1;
    }
    return 0;  // Não há tecla pressionada
}

/**
 * Função para ler um caractere pressionado.
 * Retorna o caractere pressionado.
 */
int readch() {
    // Se houver um caractere "peeking", retorna ele
    if (peekCharacter != -1) {
        int ch = peekCharacter;
        peekCharacter = -1;  // Limpa a variável peekCharacter
        return ch;
    }

    // Caso contrário, lê diretamente do teclado usando _getch()
    return _getch();
}
