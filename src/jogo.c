#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"
#include "screen.h"

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
        printf(" RIDDLE: Dança no ritmo das maos... conte nos dedos e vai adivinhar...\n");
    }

    if (numero > 50) {
        printf(" RIDDLE: Mais do que metade, mas menos do que tudo...\n");
    } else {
        printf(" RIDDLE: A sombra da metade ainda o cobre.\n");
    }
}

void jogarFase(Jogo *jogo) {
    int chute;

    screenClear();
    screenGotoxy(10, 3);
    printf("=== CODE RIDDLER: Fase %d ===\n", jogo->fase);

    mostrarEnigma(jogo->numeroSecreto);

    for (int i = 1; i <= jogo->tentativas; i++) {
        screenGotoxy(10, 9 + i);
        printf("\n Tentativa %d de %d: ", i, jogo->tentativas);
        scanf("%d", &chute);

        if (chute == jogo->numeroSecreto) {
            screenGotoxy(10, 18);
            printf("!!Parabens! Voce passou na Fase %d do RIDDLER!!\n", jogo->fase);
            return;
        } else {
            screenGotoxy(10, 10 + i);
            printf(" RIDDLER: Tente outra vez! HAHAHAHAHAHAHA \n");

            screenGotoxy(10, 11 + i);
            if (chute < jogo->numeroSecreto) {
                printf(" RIDDLER: Ainda está cedo... pense maior! \n");
            } else {
                printf(" RIDDLER: Foi longe demais... USE SEU CEREBRO! \n");
            }
        }
    }

    screenGotoxy(10, 18);
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