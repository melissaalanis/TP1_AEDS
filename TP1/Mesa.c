#include "Mesa.h"
#include <stdlib.h>
#include <stdio.h>

void Inicializar_Mesa(Mesa* mesa){ // Inicializa a nossa mesa e as nossas listas vazias
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


void Comprar_Carta(Mesa* mesa){
    int tamanho_Descarte = 0;
    int tamanho_Baralho = Retornar_Tamanho_Lista(&(mesa -> Baralho));
    Celula *auxiliar = mesa -> Baralho.primeiro -> prox; //Auxiliar carta
    Transferir_Carta(&(mesa -> Baralho), 1 , &(mesa -> Descarte));
    Altera_Posicao_Carta(&(mesa -> Descarte.ultimo -> carta));
    
    if (tamanho_Baralho == 0){
        tamanho_Descarte = Retornar_Tamanho_Lista(&(mesa -> Descarte));
        Transferir_Carta(&(mesa -> Descarte), tamanho_Descarte , &(mesa -> Baralho));
        
        for (int i=0; i<tamanho_Descarte; i++){
              Altera_Posicao_Carta(&(auxiliar->carta));
              auxiliar = auxiliar -> prox; 
        }
    }
}


void Preparar_Tableau(Mesa* mesa){
    for (int i = 0; i < 7; i++){ //O for repete 7 vezes, uma para cada lista do tablau
        Transferir_Carta(&(mesa -> Baralho), i+1, &(mesa -> Tableau[i])); //Transferindo minhas cartas do baralho para as listas do tablau, 
        //de acordo com as especificações de tamannho
        Altera_Posicao_Carta(&(mesa -> Tableau[i].ultimo -> carta)); //deixando apenas o topo da minha lista para cima
    }
}


int VerificarVitoria(Mesa * mesa){
    int carta_aux=0, contador=0;
    for(int i=0; i< 4; i++){ // Para cada base, verificaremos se o item do ultimo é igual a 13. Se for, acrescentar ao cont.
        carta_aux = mesa -> Base[i].ultimo -> carta.valor;
        if (carta_aux == 13){
            contador++;
        }
    }
    if(contador == 4){ // Quando o contador for igual a 4, então todas as bases estão preenchidas e a pessoa venceu.

        return True;
    }

    return False;
}


void Mover_Descarte_Base(Mesa* mesa, int base){
    if (Verifica_Sequencia_Naipe(&(mesa->Descarte.ultimo -> carta), &(mesa->Base[base-1].ultimo -> carta))){
        Transferir_Carta(&(mesa -> Descarte), 1, &(mesa -> Base[base-1]));
    } else {
        printf("Movimento Inválido");
    }
}