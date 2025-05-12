#include "timer.h"
#include <sys/time.h>
#include <stdio.h>

static struct timeval timer, now;
static int delay = -1;  // Atraso em milissegundos

void timerInit(int valueMilliSec)
{
    // Inicializa o temporizador com o valor de atraso especificado
    delay = valueMilliSec;
    gettimeofday(&timer, NULL);
}

void timerDestroy()
{
    // Reseta o atraso para -1 ao destruir o temporizador
    delay = -1;
}

void timerUpdateTimer(int valueMilliSec)
{
    // Atualiza o valor do atraso do temporizador
    delay = valueMilliSec;
    gettimeofday(&timer, NULL);
}

int getTimeDiff()
{
    // Calcula a diferença de tempo em milissegundos
    gettimeofday(&now, NULL);
    long diff = (((now.tv_sec - timer.tv_sec) * 1000000) + now.tv_usec - timer.tv_usec) / 1000;
    return (int) diff;
}

int timerTimeOver()
{
    // Verifica se o tempo definido pelo atraso foi alcançado
    int ret = 0;

    if (getTimeDiff() > delay)  // Se o tempo decorrido for maior que o atraso
    {
        ret = 1;  // O tempo foi superado
        gettimeofday(&timer, NULL);  // Atualiza o tempo de referência
    }

    return ret;  // Retorna 1 se o tempo foi superado, 0 caso contrário
}

void timerPrint()
{
    // Exibe o tempo decorrido desde a inicialização do temporizador
    int elapsedTime = getTimeDiff();
    printf("Tempo decorrido: %d ms\n", elapsedTime);
}
