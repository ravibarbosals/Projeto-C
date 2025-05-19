#ifndef JOGO_H
#define JOGO_H

typedef struct {
    char nome[50];
    int tentativasTotais;
} Jogador;

typedef struct {
    int fase;
    int numeroSecreto;
    int tentativas;
    int tentativasUsadas;
    int acertou;
} Jogo;

void executarJogo();

#endif
