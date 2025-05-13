#ifndef JOGO_H
#define JOGO_H

typedef struct {
    int fase;
    int numeroSecreto;
    int tentativas;
    int tentativasUsadas;
    int acertou;
} Jogo;

typedef struct {
    char nome[50];
    int tentativasTotais;
} Jogador;

void executarJogo();
void mostrarRanking();

int gerarNumero(int limite);
void mostrarDicas(int fase, int numeroSecreto);
void jogarFase(Jogo *jogo);
void jogarFaseComPergunta(Jogo *jogo);
int fazerPerguntaLogica();

#endif