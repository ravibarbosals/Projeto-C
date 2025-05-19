#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <stdio.h>  // Para printf, stdout

// Sequências de controle de terminal
#define ESC            "\033"
#define CLEARSCREEN    "[2J"

// Texto normal e atributos
#define NORMALTEXT     "[0m"
#define BOLDTEXT       "[1m"
#define ITALICTEXT     "[3m"
#define BLINKTEXT      "[5m"
#define REVERSETEXT    "[7m"

// Cursor
#define HOMECURSOR     "[H"
#define SHOWCURSOR     "[?25h"
#define HIDECURSOR     "[?25l"

// Box Drawing (lembre-se: BOX_ENABLE deve ser "\033(0" em uso, mas aqui só o sufixo)
#define BOX_ENABLE     "(0"
#define BOX_DISABLE    "(B"
#define BOX_VLINE      0x78
#define BOX_HLINE      0x71
#define BOX_UPLEFT     0x6C
#define BOX_UPRIGHT    0x6B
#define BOX_DWNLEFT    0x6D
#define BOX_DWNRIGHT   0x6A
#define BOX_CROSS      0x6E

// Dimensões da tela
#define MINX           1
#define MINY           1
#define MAXX           80
#define MAXY           24

// Enumerado de cores
typedef enum {
    BLACK, RED, GREEN, BROWN, BLUE, MAGENTA, CYAN, LIGHTGRAY,
    DARKGRAY, LIGHTRED, LIGHTGREEN, YELLOW, LIGHTBLUE,
    LIGHTMAGENTA, LIGHTCYAN, WHITE
} screenColor;

// === Protótipos das funções de tela ===
void screenInit(int drawBorders);
void screenDestroy(void);

/* Limpa toda a tela e posiciona cursor no (1,1) */
void screenClear(void);

/* Desenha bordas usando box-drawing */
void screenDrawBorders(void);

/* Exibe o ranking e aguarda tecla para voltar */
void mostrarRanking(void);

/* Move o cursor para (x,y) — col, linha */
void screenGotoxy(int x, int y);

/* Define cor de texto e fundo */
void screenSetColor(screenColor fg, screenColor bg);

void desenharCharadaAscii();

void screenUpdate(void);
void screenSetNormal(void);
void screenSetBold(void);
void screenSetBlink(void);
void screenSetReverse(void);
void screenBoxEnable(void);
void screenBoxDisable(void);
void screenHomeCursor(void);
void screenHideCursor(void);
void screenShowCursor(void);

#endif /* __SCREEN_H__ */
