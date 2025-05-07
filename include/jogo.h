#ifndef JOGO_H
#define JOGO_H

typedef struct {
    int fase;
    int numeroSecreto;
    int tentativas;
} Jogo;

int gerarNumero(int limite);
void mostrarEnigma(int numero);
void jogarFase(Jogo *jogo);
void executarJogo();

#endif
