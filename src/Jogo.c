#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int fase;
    int numeroSecreto;
    int tentativas;
} Jogo;

int gerarNumero(int limite) {
    return rand() % limite + 1;
}

void mostrarEnigma(int numero) {
    printf("\n \n");

    if (numero % 2 == 0) {
        printf(" RIDDLE: Divide o mundo em dois, sem resto, sem razao...\n");
    } else {
        printf(" RIDDLE: Nunca caminha aos pares, sempre sozinho vai.\n");
    }

    if (numero % 5 == 0) {
        printf(" RIDDLE: Dança no ritmo das mãos... conte nos dedos e vai adivinhar...\n");
    }

    if (numero > 50) {
        printf(" RIDDLE: Mais do que metade, mas menos do que tudo...\n");
    } else {
        printf(" RIDDLE: A sombra da metade ainda o cobre.\n");
    }
}

void jogarFase(Jogo *jogo) {
    int chute;

    system("cls");
    printf("=== CodeBreaker: Fase 1 ===\n");

    mostrarEnigma(jogo->numeroSecreto);

    for (int i = 1; i <= jogo->tentativas; i++) {
        printf("\n Tentativa %d de %d: ", i, jogo->tentativas);
        scanf("%d", &chute);

        if (chute == jogo->numeroSecreto) {
            printf("!!Parabens passou na Fase 1 do RIDDLER!!\n");
            return;
        } else {
            printf(" RIDDLER: Tente outra vez! HAHAHAHAHAHAHA \n");

            if (chute < jogo->numeroSecreto) {
                printf(" RIDDLER: Ainda esta cedo... pense maior! \n");
            } else {
                printf(" RIDDLER: Foi longe demais... USE SEU CEREBRO! \n");
            }
        }
    }

    printf("\n RIDDLER: !!FIM DE JOGO!! A mente vacilou, mas o número nunca mentiu: %d\n", jogo->numeroSecreto);
}

int main() {
    srand(time(NULL));

    Jogo *fase1 = (Jogo *) malloc(sizeof(Jogo));
    fase1->fase = 1;
    fase1->numeroSecreto = gerarNumero(100);
    fase1->tentativas = 7;

    jogarFase(fase1);

    free(fase1); 
    return 0;
}