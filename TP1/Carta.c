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

int Verifica_Sequencia_Naipe(Carta* carta1, Carta* carta2){ // Verifica se as cartas possuem o mesmo naipe e se formam uma sequencia crescente
    if(carta1 -> naipe == carta2 -> naipe){
        if(carta2 -> valor == carta1 -> valor + 1){ //
            return True;
        }
    }

    return False;
}

int Verifica_Sequencia_Alternada(Carta* carta1, Carta* carta2){ //TABLEAU
    if((carta1 -> valor == 0) && (carta2 -> valor == 13)){ //Verifica se a primeira carta é 0, se for, o Rei pode ser colocado naquele espaço do tableau
        return True;
    }

    if((carta1 -> valor) == (carta2 -> valor + 1)){ //Verifica se a carta 1 é exatamente uma unidade maior que a segunda
         if (((carta1 -> naipe == 'C'||'O') && (carta2 -> naipe == 'E'||'P')) || ((carta1 -> naipe == 'E'||'P' ) && (carta2 -> naipe == 'C'||'O')) ) {// Verifica se o naipe pode ser sobreposto pelo outro naipe (Cores)
            return True;
         }
    }
    return False;
}

void Exibir_Carta(Carta* carta){
    if (carta -> posicao == True){
        printf("[%d %c]", carta->valor, carta->naipe);    
    } else {
        printf("[  ]");
    }
}

