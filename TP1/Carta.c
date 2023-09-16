#include <stdio.h>
#include <string.h>
#include "Carta.h"


void Inicializa_Carta(Carta* carta, int valor, char naipe){
    carta -> valor = valor;
    carta -> naipe = naipe;
    carta -> posicao = False; //Todas as cartas são inicializadas com False (virado para baixo), a sua posição é alterada no decorrer do programa
}

int Retorna_Valor_Carta(Carta* carta){ // Função q retona o valor da carta 
    return carta -> valor;
}

char Retorna_Naipe_Carta(Carta* carta){  // Função q retona o naipe da carta 
    return carta -> naipe; 
}

int Retorna_Posicao_Carta(Carta* carta){ // Função q retona a posição da carta 
    return carta -> posicao;
}

void Altera_Posicao_Carta(Carta* carta){ // Função q altera a posição da carta
    if(carta->posicao == False){
        carta -> posicao = True;
    }
    else{
        carta -> posicao = False;
    }
}