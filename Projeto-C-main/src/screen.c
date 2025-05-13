/**
 * screen.c
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#include "screen.h"
#include <wchar.h>
#include <locale.h>

void screenDrawBorders() 
{
    setlocale(LC_ALL, "");  // Garantir suporte para caracteres Unicode

    const char *hbc = "═";  // Caracter para bordas horizontais
    const char *vbc = "║";  // Caracter para bordas verticais

    // Definições dos caracteres gráficos da tabela CP437 para bordas
    #define BOX_UPLEFT     0x6C  // Canto superior esquerdo
    #define BOX_UPRIGHT    0x6B  // Canto superior direito
    #define BOX_DWNLEFT    0x6D  // Canto inferior esquerdo
    #define BOX_DWNRIGHT   0x6A  // Canto inferior direito
    #define BOX_HORIZ      0xCD  // Linha horizontal
    #define BOX_VERT       0xBA  // Linha vertical

    // Limpa a tela antes de desenhar as bordas
    screenClear();
    screenBoxEnable();
    
    // Desenha o canto superior esquerdo
    screenGotoxy(MINX, MINY);
    printf("%c", BOX_UPLEFT);

    // Desenha a borda superior
    for (int i = MINX + 1; i < MAXX; i++) {
        screenGotoxy(i, MINY);
        printf("%s", hbc);
    }

    // Desenha o canto superior direito
    screenGotoxy(MAXX, MINY);
    printf("%c", BOX_UPRIGHT);

    // Desenha as bordas laterais
    for (int i = MINY + 1; i < MAXY; i++) {
        screenGotoxy(MINX, i);
        printf("%s", vbc);
        screenGotoxy(MAXX, i);
        printf("%s", vbc);
    }

    // Desenha o canto inferior esquerdo
    screenGotoxy(MINX, MAXY);
    printf("%c", BOX_DWNLEFT);

    // Desenha a borda inferior
    for (int i = MINX + 1; i < MAXX; i++) {
        screenGotoxy(i, MAXY);
        printf("%s", hbc);
    }

    // Desenha o canto inferior direito
    screenGotoxy(MAXX, MAXY);
    printf("%c", BOX_DWNRIGHT);

    screenBoxDisable();
}

void screenInit(int drawBorders)
{
    // Inicializa a tela, limpa e desenha bordas se necessário
    screenClear();
    if (drawBorders) {
        screenDrawBorders();
    }
    screenHomeCursor();  // Posiciona o cursor no topo esquerdo
    screenHideCursor();  // Esconde o cursor
}

void screenDestroy()
{
    // Restaura as cores padrão e limpa a tela ao destruir
    printf("%s[0;39;49m", ESC);  // Reset das cores
    screenSetNormal();  // Restaura o modo normal
    screenClear();  // Limpa a tela
    screenHomeCursor();  // Coloca o cursor na posição inicial
    screenShowCursor();  // Exibe o cursor novamente
}

void screenGotoxy(int x, int y)
{
    // Garante que as coordenadas estejam dentro dos limites definidos
    x = (x < 0 ? 0 : x >= MAXX ? MAXX - 1 : x);
    y = (y < 0 ? 0 : y > MAXY ? MAXY : y);
    
    // Move o cursor para as coordenadas (x, y) na tela
    printf("%s[f%s[%dB%s[%dC", ESC, ESC, y, ESC, x);
}

void screenSetColor(screenColor fg, screenColor bg)
{
    // Define as cores de primeiro plano (fg) e fundo (bg)
    char atr[] = "[1;";

    // Verifica se o valor de fg é maior que o limite de vermelho
    if (fg > RED) {
        atr[1] = '1';  // Ajusta para cores mais claras
        fg -= 8;  // Ajusta o valor de fg para o intervalo correto
    }

    // Aplica as cores usando a sequência ANSI de escape
    printf("%s%s%d;%dm", ESC, atr, fg + 30, bg + 40);
}

void screenUpdate() {
    fflush(stdout);
}

void screenSetNormal() {
    printf("%s%s", ESC, NORMALTEXT);
}

void screenSetBold() {
    printf("%s%s", ESC, BOLDTEXT);
}

void screenSetBlink() {
    printf("%s%s", ESC, BLINKTEXT);
}

void screenSetReverse() {
    printf("%s%s", ESC, REVERSETEXT);
}

void screenBoxEnable() {
    printf("%s%s", ESC, BOX_ENABLE);
}

void screenBoxDisable() {
    printf("%s%s", ESC, BOX_DISABLE);
}