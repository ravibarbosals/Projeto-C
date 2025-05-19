#include <stdio.h>
#include <locale.h>
#include "screen.h"
#include "keyboard.h"
#include <string.h>

// Adicione o protótipo da função antes de qualquer uso
void preencherFundoEntreBordasComTitle(void);

/* Limpa toda a tela e leva cursor a 1,1 */
void screenClear() {
    printf("%s%s", ESC, CLEARSCREEN);
    fflush(stdout);
}



/* Desenha as bordas da janela */
void screenDrawBorders(void) {
    setlocale(LC_ALL, "");
    screenClear();
    screenBoxEnable();           // ativa modo box-drawing

    // canto superior esquerdo
    screenGotoxy(MINX, MINY);
    putchar(BOX_UPLEFT);

    // borda superior
    for (int x = MINX + 1; x < MAXX; x++) {
        screenGotoxy(x, MINY);
        putchar(BOX_HLINE);
    }
    // canto superior direito
    screenGotoxy(MAXX, MINY);
    putchar(BOX_UPRIGHT);

    // laterais
    for (int y = MINY + 1; y < MAXY; y++) {
        screenGotoxy(MINX, y);
        putchar(BOX_VLINE);
        screenGotoxy(MAXX, y);
        putchar(BOX_VLINE);
    }

    // canto inferior esquerdo
    screenGotoxy(MINX, MAXY);
    putchar(BOX_DWNLEFT);
    // borda inferior
    for (int x = MINX + 1; x < MAXX; x++) {
        screenGotoxy(x, MAXY);
        putchar(BOX_HLINE);
    }
    // canto inferior direito
    screenGotoxy(MAXX, MAXY);
    putchar(BOX_DWNRIGHT);

    screenBoxDisable();    
    // Mostra o fundo entre as bordas
    preencherFundoEntreBordasComTitle();
}

/* Inicializa a tela: limpa, desenha bordas (se solicitado), move cursor e esconde */
void screenInit(int drawBorders) {
    screenClear();
    if (drawBorders) screenDrawBorders();
    screenHomeCursor();
    screenHideCursor();
}

/* Restaura cores, limpa e mostra cursor */
void screenDestroy(void) {
    printf(ESC NORMALTEXT);      // reseta atributos
    screenClear();
    screenHomeCursor();
    screenShowCursor();
}

/* Move cursor ANSI para linha=y coluna=x */
void screenGotoxy(int x, int y) {
    printf("%s[%d;%dH", ESC, y, x);
    fflush(stdout);
}
/* Define cores de primeiro-plano e fundo */
void screenSetColor(screenColor fg, screenColor bg) {
    char seq[20];
    int bright = 0;
    if (fg > LIGHTGRAY) { bright = 1; fg -= 8; }
    // formata: ESC [<bright>;<fg+30>;<bg+40>m
    snprintf(seq, sizeof(seq), ESC "[%d;%d;%dm", bright, fg + 30, bg + 40);
    printf("%s", seq);
}

void desenharCharadaAscii() {
    // Não define cor aqui!
    screenClear();

    screenGotoxy(15, 2);
    printf("⠀               ⢀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 3);
    printf("⠀⠀⠀⠀  ⠀   ⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣤⣀⠀⠀⠀⠀  ⠀ \n");
    screenGotoxy(15, 4);
    printf("⠀⠀⠀⠀⠀⠀  ⠀⢀⠙⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 5);
    printf("⠀⠀⠀⠀⠀⠀⠀  ⠀⣷⣶⣤⣄⣈⣉⣉⣉⣉⣉⣉⣉⣁⣤⡄⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 6);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀  ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 7);
    printf("⠀⠀⠀⠀⠀⠀  ⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 8);
    printf("⠀⠀⠀⠀  ⠀⠀⢀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 9);
    printf("⠀⠀   ⢀⣠⣶⣾⡏⢀⡈⠛⠻⠿⢿⣿⣿⣿⣿⣿⠿⠿⠟⠛⢀⠀⢶⣤⣀⠀⠀⠀\n");
    screenGotoxy(15, 10);
    printf("   ⠀⢠⣿⣿⣿⣿⡇⠸⣿⣿⣶⣶⣤⣤⣤⣤⣤⣤⣤⣶⣶⣿⡿⠂⣸⣿⣿⣷⡄⠀\n");
    screenGotoxy(15, 11);
    printf("  ⠀ ⢸⣿⣿⣿⣿⣿⣦⣄⡉⠛⠛⠛⠿⠿⠿⠿⠛⠛⠛⢉⣁⣤⣾⣿⣿⣿⣿⡷⠀\n");
    screenGotoxy(15, 12);
    printf("⠀⠀  ⠙⢿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣶⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀\n");
    screenGotoxy(15, 13);
    printf("⠀⠀⠀  ⠀⠈⠙⠛⠿⠿⢿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠛⠛⠉⠁⠀⠀⠀⠀\n");
    screenGotoxy(15, 14);
    printf("⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣷⡍⠻⢷⠿⢿⠿⢧⣶⣿⣿⣿⣿⣿⣿⣿⣿⣶⣆⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 15);
    printf("⠀⠀⠀⣀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣆⣰⣶⣆⣀⣾⣿⣿⣿⣿⣿⣿⣿⡿⠿⣥⣾⣿⡀⠀⠀⠀⠀\n");
    screenGotoxy(15, 16);
    printf("⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠘⠻⣿⣿⣿⣦⡀⠀⠀\n");
    screenGotoxy(15, 17);
    printf("⠀⠿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠛⠻⣿⣿⣿⣿⣿⣿⣿⣏⣡⣼⣿⣦⣄⠘⢿⣿⣿⣿⣿⡄⠀\n");
    screenGotoxy(15, 18);
    printf("⠀⣬⣿⣃⢨⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣼⣿⣿⣿⣿⡷⠀\n");
    screenGotoxy(15, 19);
    printf("⠀⠹⣿⣽⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⣿⣿⣿⡿⠛⠉⠉⠙⢿⣿⣿⣿⠁⠀\n");
    screenGotoxy(15, 20);
    printf("⠀⠀⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣽⣿⣿⣿⣇⠀⠀⠀⠀⢸⣿⣿⣿⠂⠀\n");
    screenGotoxy(15, 21);
    printf("⠀⠀⢹⣿⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢲⣿⣿⣿⣿⣿⣿⣿⣶⠦⠀⣼⣿⣿⣿⣀⡀\n");
    screenGotoxy(15, 22);
    printf("⠀⢰⣧⣼⣿⣿⣿⠃⠀⢀⣠⡀⠀⠀⠀⠀⠀⠀⣆⢸⣿⣿⣿⣿⣿⠿⣷⣶⣶⡄⠈⣿⣿⣿⣸⣿\n");
    screenGotoxy(15, 23);
    printf("⠀⠘⣿⣿⡞⣿⡏⠀⠚⠛⠉⠙⣧⡀⠀⠀⠈⣦⣻⣾⣿⣿⣻⣿⢏⡴⠋⠁⠀⠀⠀⣿⣿⣿⣿⡿\n");
    screenGotoxy(15, 24);
    printf("⠀⠀⠙⢠⣷⢿⣧⠀⠀⢲⣿⣶⣿⣿⣦⡀⢀⣾⣿⣿⣿⣯⣟⣷⣯⣷⣶⣶⣾⣿⣦⣿⡏⣿⡔⠁\n");
    screenGotoxy(15, 25);
    printf("⠀⠀⢠⡼⣧⠘⡏⠀⠀⠀⠁⢹⣂⣤⣼⡿⢻⡟⠻⣿⣿⣿⣿⣹⠯⠖⣁⣿⣿⣿⠛⢻⢃⣿⠷⠀\n");
    screenGotoxy(15, 26);
    printf("⠀⠀⠀⢣⡨⠿⠉⠀⠀⠀⠀⣀⣈⠉⠁⠀⠀⠀⠀⢿⡃⢸⣿⣿⣿⣿⣿⣿⠋⠉⠀⠈⠾⠁⠀⠀\n");
    screenGotoxy(15, 27);
    printf("⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⡿⠷⠖⠀⠀⠀⠀⢻⣿⣿⣿⣭⣿⣻⣿⣿⣶⡤⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 28);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣯⣇⠀⠀⠀⠀⣀⠀⠀⢸⣿⠇⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 29);
    printf("⠀⠀⠀⠀⠀⠀⠀⢀⠀⠈⠘⣿⣿⣶⣦⣄⣉⠳⠤⣿⣾⣿⣿⣿⠿⣿⡿⢫⡆⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 30);
    printf("⠀⠀⠀⠀⠀⠀⠀⠘⣆⠀⠀⠸⣿⡄⠈⠙⠛⠟⢿⠿⠏⠛⠉⠀⢠⣿⠁⡾⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 31);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠸⣄⠀⠀⠹⣿⡓⠲⠤⠀⠀⢀⡤⠴⠞⣻⣿⠃⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 32);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠢⠀⠀⠹⣷⣄⡀⡀⣀⢠⢠⣶⣷⡿⠃⠀⢀⢰⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 33);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆⠈⢆⠀⠈⢿⣿⣶⣾⣿⣿⣿⡿⠀⠀⢀⡏⢸⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 34);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣧⠀⠘⣆⠀⢀⡈⣻⣿⣿⣿⣷⣦⡀⠀⣾⠇⣼⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 35);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣆⠀⠘⣆⠀⠙⠛⠛⣻⠿⣿⣿⠇⣼⡟⣲⠋⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 36);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣄⠘⢦⣀⣀⣴⣧⣴⣿⣟⣼⣿⡷⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 37);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⢦⣈⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    screenGotoxy(15, 38);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣟⡛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");

    // Mensagem logo abaixo do desenho, na linha 39
    screenGotoxy(15, 39);
    printf("HAHAHA! RESOLVA MEUS ENIGMAS!");
    screenGotoxy(15, 40);
    printf("Pressione ENTER para continuar...");
    
    while (readch() != '\n'); // Espera Enter
}

const char *title[] = {
    "      0      0      0      0      0      0      0      0      0      0      0      0      ",
    "      1      1      1      1      0      1      1      1      1      1      1      1      ",
    "      0      1      1      1      1      0      0      1      1      1      1      1      ",
    "      0      0      0      0      0      1      0      0      0      0      0      0      ",
    "      0      1      0      1      0      0      1      1      0      0      1      1      ",
    "      0      1      0      1      0      0      1      1      0      0      1      1      ",
    "      1      1      0      1      0      1      1      0      1      1      0      1      ",
    "      1      1      0      1      0      1      1      0      1      1      0      1      ",
    "      0      0      1      0      0      0      1      0      0      0      1      0      ",
    "      1      0      1      0      1      0      1      0      1      0      1      0      ",
    "      1      0      1      0      1      0      1      0      1      0      1      0      ",
    "      1      1      0      0      1      1      0      0      1      1      0      0      ",
    "      1      1      0      0      1      1      0      0      1      1      0      0      ",
    "      1      1      1      1      1      1      1      1      1      1      1      1      ",
    "      0      0      0      0      0      0      0      0      0      0      0      0      ",
};

void preencherFundoEntreBordasComTitle() {
    int num_lines = sizeof(title) / sizeof(title[0]);
    int y_idx = 0;
    for (int y = MINY + 1; y < MAXY; y++) {
        const char *linha = title[y_idx % num_lines];
        int len = strlen(linha);
        int x_idx = 0;
        for (int x = MINX + 1; x < MAXX; x++) {
            screenGotoxy(x, y);
            char ch = linha[x_idx % len];
            putchar(ch);
            x_idx++;
        }
        y_idx++;
    }
}



void screenUpdate(void)    { fflush(stdout); }
void screenSetNormal(void) { printf(ESC NORMALTEXT); }
void screenSetBold(void)   { printf(ESC BOLDTEXT); }
void screenSetBlink(void)  { printf(ESC BLINKTEXT); }
void screenSetReverse(void){ printf(ESC REVERSETEXT); }
void screenBoxEnable(void) { printf(ESC BOX_ENABLE); }
void screenBoxDisable(void){ printf(ESC BOX_DISABLE); }
void screenHomeCursor(void){ printf(ESC HOMECURSOR); }
void screenHideCursor(void){ printf(ESC HIDECURSOR); }
void screenShowCursor(void){ printf(ESC SHOWCURSOR); }

;

