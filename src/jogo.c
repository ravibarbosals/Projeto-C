#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 

#include "jogo.h"
#include "screen.h"
#include "keyboard.h"

int gerarNumero(int limite) {
    return rand() % limite + 1;
}

void mostrarEnigma(int numero) {
    printf("\n\n");

    if (numero % 2 == 0) {
        printf(" RIDDLE: Divide o mundo em dois, sem resto, sem razao...\n");
    } else {
        printf(" RIDDLE: Nunca caminha aos pares, sempre sozinho vai.\n");
    }

    if (numero % 5 == 0) {
        printf(" RIDDLE: Danca no ritmo das maos... conte nos dedos e vai adivinhar...\n");
    }

    if (numero > 50) {
        printf(" RIDDLE: Mais do que metade, mas menos do que tudo...\n");
    } else {
        printf(" RIDDLE: A sombra da metade ainda o cobre.\n");
    }
}

int lerNumero() {
    int numero = 0;
    char ch;

    while (1) {
        ch = readch();

        if (ch == 10) break; 
        if (isdigit(ch)) {
            numero = numero * 10 + (ch - '0');
            printf("%c", ch); 
        }
    }
    return numero;
}
void jogarFase(Jogo *jogo) {
    int chute;

    screenClear();
    screenInit(1);
    screenGotoxy(28, 2);
    printf("=== CODE RIDDLER: Fase %d ===", jogo->fase);
    
    screenGotoxy(10, 4);
    mostrarEnigma(jogo->numeroSecreto);

    for (int i = 1; i <= jogo->tentativas; i++) {
        screenGotoxy(20, 5 + (i - 1)* 4);
        printf("Tentativa %d de %d: ", i, jogo->tentativas);
        
        chute = lerNumero();

        if (chute == jogo->numeroSecreto) {
            screenGotoxy(20, 10 + i * 4);
            printf("!!Parabens! Voce passou na Fase %d do RIDDLER!!\n", jogo->fase);
            return;
        } 
            
        screenGotoxy(20, 11 + (i - 1) * 4);
        printf(" RIDDLER: Tente outra vez! HAHAHAHAHAHAHA\n");

        screenGotoxy(20, 12 + (i - 1)* 4);
        if (chute < jogo->numeroSecreto) {
            printf(" RIDDLER: Ainda está cedo... pense maior!\n");
        } else {
            printf(" RIDDLER: Foi longe demais... USE SEU CEREBRO!\n");
            
        }
    }

    screenGotoxy(20, 10 + jogo->tentativas * 4);
    printf("\n RIDDLER: !!FIM DE JOGO!! O numero era: %d\n", jogo->numeroSecreto);
}

void executarJogo() {
    Jogo *fase1 = (Jogo *) malloc(sizeof(Jogo));
    fase1->fase = 1;
    fase1->numeroSecreto = gerarNumero(100);
    fase1->tentativas = 7;

    jogarFase(fase1);

    free(fase1);
}