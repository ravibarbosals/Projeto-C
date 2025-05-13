#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "jogo.h"
#include "screen.h"
#include "keyboard.h"

#define MAX_JOGADORES 10
Jogador ranking[MAX_JOGADORES];
int numJogadores = 0;

int ehPrimo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int gerarNumero(int limite) {
    return rand() % (limite + 1);
}

void mostrarDicas(int fase, int numero) {
    printf("\n\n=== DICAS ===\n");
    
    // Dicas comuns a todas as fases
    if (numero % 2 == 0) {
        printf("- O número é par\n");
    } else {
        printf("- O número é ímpar\n");
    }
    
    // Dicas específicas por fase
    switch(fase) {
        case 1:
            if (numero > 5) {
                printf("- O número é maior que 5\n");
            } else {
                printf("- O número é 5 ou menor\n");
            }
            if (numero % 3 == 0) {
                printf("- O número é múltiplo de 3\n");
            }
            break;
            
        case 2:
            if (numero > 25) {
                printf("- O número é maior que 25\n");
            } else {
                printf("- O número é 25 ou menor\n");
            }
            if (ehPrimo(numero)) {
                printf("- O número é primo\n");
            }
            break;
            
        case 3:
            if (numero > 50) {
                printf("- O número é maior que 50\n");
            } else {
                printf("- O número é 50 ou menor\n");
            }
            if (numero % 5 == 0) {
                printf("- O número é múltiplo de 5\n");
            }
            break;
            
        case 4:
            if (numero > 75) {
                printf("- O número é maior que 75\n");
            } else {
                printf("- O número é 75 ou menor\n");
            }
            if (numero % 10 == 0) {
                printf("- O número é múltiplo de 10\n");
            }
            break;
            
        case 5:
            if (numero > 250) {
                printf("- O número é maior que 250\n");
            } else {
                printf("- O número é 250 ou menor\n");
            }
            if (numero % 25 == 0) {
                printf("- O número é múltiplo de 25\n");
            }
            break;
    }
}

int lerNumero() {
    int numero = 0;
    char ch;

    while (1) {
        ch = readch();

        if (ch == '\n') break;
        if (isdigit(ch)) {
            numero = numero * 10 + (ch - '0');
            printf("%c", ch);
        }
    }
    return numero;
}

int fazerPerguntaLogica() {
    int resposta;
    char ch;  // Variável declarada aqui para resolver o erro
    
    screenClear();
    screenGotoxy(20, 5);
    printf("=== PERGUNTA DE LÓGICA ===");
    
    screenGotoxy(10, 7);
    printf("Considere a proposição:");
    screenGotoxy(10, 8);
    printf("Se hoje é quinta-feira, então amanhã será sexta-feira.");
    screenGotoxy(10, 9);
    printf("Qual é o valor lógico desta proposição?");
    screenGotoxy(10, 11);
    printf("1. Verdadeiro");
    screenGotoxy(10, 12);
    printf("2. Falso");
    screenGotoxy(10, 13);
    printf("3. Indeterminado");
    
    screenGotoxy(10, 15);
    printf("Sua resposta (1-3): ");
    
    while (1) {
        ch = readch();
        if (ch >= '1' && ch <= '3') {
            resposta = ch - '0';
            printf("%c", ch);
            break;
        }
    }
    
    return (resposta == 1); // Resposta correta é 1 (Verdadeiro)
}

void jogarFase(Jogo *jogo) {
    int chute;
    jogo->tentativasUsadas = 0;
    jogo->acertou = 0;

    screenClear();
    screenInit(1);
    screenGotoxy(28, 2);
    printf("=== ADIVINHE O NÚMERO: Fase %d ===", jogo->fase);

    screenGotoxy(10, 4);
    mostrarDicas(jogo->fase, jogo->numeroSecreto);

    for (int i = 1; i <= jogo->tentativas; i++) {
        screenGotoxy(20, 5 + (i - 1) * 4);
        printf("Tentativa %d de %d: ", i, jogo->tentativas);

        chute = lerNumero();
        jogo->tentativasUsadas++;

        if (chute == jogo->numeroSecreto) {
            screenGotoxy(20, 10 + i * 4);
            printf("!! Parabéns! Você acertou o número %d !!", jogo->numeroSecreto);
            jogo->acertou = 1;
            return;
        }

        screenGotoxy(20, 11 + (i - 1) * 4);
        printf("Tente outra vez!");
        screenGotoxy(20, 12 + (i - 1) * 4);
        if (chute < jogo->numeroSecreto) {
            printf("O número secreto é maior!");
        } else {
            printf("O número secreto é menor!");
        }
    }
}

void jogarFaseComPergunta(Jogo *jogo) {
    jogarFase(jogo);
    
    if (!jogo->acertou) {
        screenGotoxy(20, 15 + jogo->tentativas * 4);
        printf("Suas tentativas acabaram! Mas há uma chance...");
        
        if (fazerPerguntaLogica()) {
            screenGotoxy(20, 17 + jogo->tentativas * 4);
            printf("Resposta correta! Você ganhou mais 3 tentativas!");
            
            jogo->tentativas += 3;
            jogarFase(jogo);
        } else {
            screenGotoxy(20, 17 + jogo->tentativas * 4);
            printf("Resposta errada! Fim de jogo.");
        }
    }
}

void adicionarAoRanking(char *nome, int tentativas) {
    if (numJogadores < MAX_JOGADORES) {
        strcpy(ranking[numJogadores].nome, nome);
        ranking[numJogadores].tentativasTotais = tentativas;
        numJogadores++;
        
        // Ordenar ranking (bubble sort simples)
        for (int i = 0; i < numJogadores - 1; i++) {
            for (int j = 0; j < numJogadores - i - 1; j++) {
                if (ranking[j].tentativasTotais > ranking[j+1].tentativasTotais) {
                    Jogador temp = ranking[j];
                    ranking[j] = ranking[j+1];
                    ranking[j+1] = temp;
                }
            }
        }
    }
}

void mostrarRanking() {
    screenClear();
    screenInit(1);
    screenGotoxy(28, 2);
    printf("=== RANKING DOS JOGADORES ===");
    
    for (int i = 0; i < numJogadores; i++) {
        screenGotoxy(20, 5 + i);
        printf("%d. %s - %d tentativas", i+1, ranking[i].nome, ranking[i].tentativasTotais);
    }
    
    screenGotoxy(20, 7 + numJogadores);
    printf("Pressione ENTER para continuar...");
    while (readch() != '\n');
}

void executarJogo() {
    srand(time(NULL));
    char nome[50];
    int tentativasTotais = 0;
    
    screenClear();
    screenInit(1);
    screenGotoxy(25, 5);
    printf("Digite seu nome: ");
    
    // Ler nome do jogador
    int i = 0;
    char ch;
    while ((ch = readch()) != '\n' && i < 49) {
        nome[i++] = ch;
        printf("%c", ch);
    }
    nome[i] = '\0';
    
    // Fase 1 (0-10, 5 tentativas)
    Jogo fase1 = {1, gerarNumero(10), 5, 0, 0};
    jogarFase(&fase1);
    tentativasTotais += fase1.tentativasUsadas;
    
    if (!fase1.acertou) {
        screenGotoxy(20, 20);
        printf("Fim de jogo! Você não completou a fase 1.");
        return;
    }
    
    // Fase 2 (0-50, 5 tentativas)
    Jogo fase2 = {2, gerarNumero(50), 5, 0, 0};
    jogarFase(&fase2);
    tentativasTotais += fase2.tentativasUsadas;
    
    if (!fase2.acertou) {
        screenGotoxy(20, 20);
        printf("Fim de jogo! Você não completou a fase 2.");
        return;
    }
    
    // Fase 3 (0-100, 5 tentativas + pergunta)
    Jogo fase3 = {3, gerarNumero(100), 5, 0, 0};
    jogarFaseComPergunta(&fase3);
    tentativasTotais += fase3.tentativasUsadas;
    
    if (!fase3.acertou) {
        screenGotoxy(20, 20);
        printf("Fim de jogo! Você não completou a fase 3.");
        return;
    }
    
    // Fase 4 (0-150, 5 tentativas + pergunta)
    Jogo fase4 = {4, gerarNumero(150), 5, 0, 0};
    jogarFaseComPergunta(&fase4);
    tentativasTotais += fase4.tentativasUsadas;
    
    if (!fase4.acertou) {
        screenGotoxy(20, 20);
        printf("Fim de jogo! Você não completou a fase 4.");
        return;
    }
    
    // Fase 5 (0-500, 5 tentativas + pergunta)
    Jogo fase5 = {5, gerarNumero(500), 5, 0, 0};
    jogarFaseComPergunta(&fase5);
    tentativasTotais += fase5.tentativasUsadas;
    
    if (fase5.acertou) {
        screenGotoxy(20, 20);
        printf("PARABÉNS! Você completou todas as 5 fases em %d tentativas!", tentativasTotais);
        adicionarAoRanking(nome, tentativasTotais);
        mostrarRanking();
    } else {
        screenGotoxy(20, 20);
        printf("Fim de jogo! Você não completou a fase 5.");
    }
}