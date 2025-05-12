#ifndef JOGO_H
#define JOGO_H

typedef struct {
    int fase;
    int numeroSecreto;
    int tentativas;
} Jogo;

void executarJogo();

int gerarNumero(int limite);
void mostrarEnigma(int numeroSecreto);
void jogarFase(Jogo *jogo);
void jogarFaseComTroca(Jogo *jogo);

#endif
