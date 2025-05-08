#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 

#include "jogo.h"
#include "screen.h"
#include "keyboard.h"

int gerarNumero(int limite) {
    limite=100;
    return rand() % limite + 1;
}

void mostrarEnigma(int numero) {
    printf("\n\n");
    
    if ((numero > 20 && numero % 2 == 0))
        printf("- Não é verdade que o número seja par e maior que 20.\n");

    if ((numero % 2 == 0) || (numero % 3 == 0 && numero % 5 != 0))
        printf("- O número é par ou (é múltiplo de 3 e não múltiplo de 5).\n");

    if ((numero < 50 && numero % 4 == 0) || (numero > 75 && numero % 3 == 0))
        printf("- Se o número é menor que 50 e múltiplo de 4, ou maior que 75 e múltiplo de 3, então esta proposição é verdadeira.\n");

    if (((numero % 2 != 0) && (numero)))
        printf("- Não é verdade que o número seja ímpar e primo ao mesmo tempo.\n");

    if (((numero) && numero > 36) || numero == 0)
        printf("- O número é um quadrado perfeito maior que 36, ou é zero.\n");

    if ((numero % 10 == 1 && numero > 50) || (numero < 30 && numero % 6 == 0))
        printf("- O número termina com 1 e é maior que 50, ou é menor que 30 e múltiplo de 6.\n");

    if (((numero % 3 == 0 || numero % 5 == 0) && numero > 90))
        printf("- Não é verdade que o número seja maior que 90 e múltiplo de 3 ou 5.\n");

    if (!((numero) && numero % 2 == 0))
        printf("- Se o número é primo, então ele não é par.\n");

    if ((numero >= 20 && numero <= 40) || (numero >= 60 && numero <= 80))
        printf("- O número está entre 20 e 40 ou entre 60 e 80.\n");

    if ((numero % 7 == 0 && numero < 70) || (numero % 11 == 0 && numero > 50))
        printf("- O número é múltiplo de 7 e menor que 70, ou múltiplo de 11 e maior que 50.\n");

}


int lerNumero() {
    int numero = 0;
    char ch;

    while (1) {
        ch = readch(); // Lê um caractere do teclado

        if (ch == '\n') break; // Verifica se é uma nova linha
        if (isdigit(ch)) {
            numero = numero * 10 + (ch - '0'); // Converte o caractere para número
            printf("%c", ch); // Exibe o caractere digitado
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
        screenGotoxy(20, 5 + (i - 1) * 4);
        printf("Tentativa %d de %d: ", i, jogo->tentativas);
        
        chute = lerNumero();

        if (chute == jogo->numeroSecreto) {
            screenGotoxy(20, 10 + i * 4);
            printf("!!Parabéns! Você passou na Fase %d do RIDDLER!!\n", jogo->fase);
            return;
        } 
            
        screenGotoxy(20, 11 + (i - 1) * 4);
        printf("RIDDLER: Tente outra vez! HAHAHAHAHAHAHA\n");

        screenGotoxy(20, 12 + (i - 1) * 4);
        if (chute < jogo->numeroSecreto) {
            printf("RIDDLER: Ainda está cedo... pense maior!\n");
        } else {
            printf("RIDDLER: Foi longe demais... USE SEU CÉREBRO!\n");
        }
    }

    screenGotoxy(20, 10 + jogo->tentativas * 4);
    printf("\nRIDDLER: !!FIM DE JOGO!! O número era: %d\n", jogo->numeroSecreto);
}

void executarJogo() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    Jogo *fase1 = (Jogo *) malloc(sizeof(Jogo));
    if (fase1 == NULL) {
        printf("Erro ao alocar memória para o jogo.\n");
        return;
    }

    fase1->fase = 1;
    fase1->numeroSecreto = gerarNumero(10);
    fase1->tentativas = 10;

    

    jogarFase(fase1);

    free(fase1); // Libera a memória alocada
}