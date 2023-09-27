#include "Mesa.h"
#include <stdlib.h>
#include <stdio.h>

void Inicializar_Mesa(Mesa* mesa){
    Inicializar_Lista_Vazia(&(mesa -> Baralho));
    Inicializar_Lista_Vazia(&(mesa -> Descarte));
    
    for(int i=0; i<4; i++){
        Inicializar_Lista_Vazia(&(mesa -> Base[i]));
    }

    for(int j=0; j<7; j++){
        Inicializar_Lista_Vazia(&(mesa -> Tableau[j]));
    }

    mesa -> pontuacao = 0;
    

}

void Carregar_Baralho_Aleatorio(Mesa* mesa){
    for (int i = 0; i < 53; i++){
        Carta* carta_aux = (Carta*)malloc(sizeof(Carta)); //Aloca memória para minha carta
        Adicionar_Carta_ao_Topo(&(mesa -> Baralho), carta_aux); //Adiciona cada carta ao topo do meu baralho
    }

    Embaralhar_Baralho(&(mesa -> Baralho)); //Embaralha meu baralho
}

void Comprar_Carta(Mesa* mesa, Lista_de_Cartas Descarte){
    //Transferir_Carta
}