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

int Verifica_Sequencia_Naipe(Carta* carta1, Carta* carta2){  
    /* Verifica se as cartas possuem o mesmo naipe e se formam uma sequencia crescente 
    Carta2 = carta_saida carta1 = carta_chegada*/
    if(carta1 -> naipe == carta2 -> naipe ||carta1 -> naipe == 'V' ){ 
        /*Verifica se os naipes são iguais ou se estou tentando colocar meu As em uma posicao vazia */
        if(carta2 -> valor == carta1 -> valor + 1){ //
            return True;
        }
    }

    return False;
}


int Verifica_Sequencia_Alternada(Carta* carta1, Carta* carta2){ 
    //TABLEAU Carta1 = Carta_chegada carta2 = carta_saida
    if((carta1 -> valor == 0) && (carta2 -> valor == 13)){ 
        //Verifica se a primeira carta é 0, se for, o Rei pode ser colocado naquele espaço do tableau
        return True;
    }

    if((carta1 -> valor) == (carta2 -> valor + 1)){ 
        //Verifica se a carta 1 é exatamente uma unidade maior que a segunda
        // Verifica se o naipe pode ser sobreposto pelo outro naipe (Cores)
        if((carta1 -> naipe == 'C'|| carta1 -> naipe == 'O') && (carta2 -> naipe == 'E'|| carta2 -> naipe == 'P')){
            return True;
        }
        if((carta2 -> naipe == 'C'|| carta2 -> naipe == 'O') && (carta1 -> naipe == 'E'|| carta1 -> naipe == 'P')){
            return True;
        }
    }
    return False;
}

void Exibir_Carta(Carta* carta){
    if (carta -> valor == 0){
        printf("[     ]"); //Lista vazia
    }else if (carta -> posicao == True){
        if(carta->valor == 13){
            printf("[K ");
        } else if(carta->valor == 12){
            printf("[Q ");
        } else if(carta->valor == 11){
            printf("[J ");
        } else if(carta->valor == 1){
            printf("[A ");
        } else {
            printf("[%d ", carta->valor);
        }
        if(carta->naipe == 'C'){
            printf(" ♥️] ");
        } else if(carta->naipe == 'O'){
            printf(" ♦] ");
        } else if(carta->naipe == 'P'){
            printf(" ♣️] ");
        } else if(carta->naipe == 'E'){
            printf(" ♠️] ");
        } 
    } else {
        printf("[ -- ]");
    }
}


//♣️  ♥️ ♦
