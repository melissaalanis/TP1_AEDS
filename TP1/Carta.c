#include <stdio.h>
#include "Carta.h"


void Inicializa_Carta(Carta* carta, int valor, char naipe){
    carta -> valor = valor;
    carta -> naipe = naipe;
    carta -> posicao = False; //Todas as cartas são inicializadas com False (virado para baixo), a sua posição é alterada no decorrer do programa
}

