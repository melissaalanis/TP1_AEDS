#include "Lista_de_Cartas.h"
#include <stdio.h>
#include <stdlib.h>

void Inicializar_Lista_Vazia(Lista_de_Cartas* lista_de_cartas){ //Estamos utilizando célula cabeça
    lista_de_cartas -> primeiro = (Celula*)malloc(sizeof(lista_de_cartas)); 
    lista_de_cartas -> ultimo = lista_de_cartas -> primeiro; 
    lista_de_cartas -> primeiro -> prox = NULL; 
    // Para a lista estar vazia ultimo e proximo terão que apontar
    //para o mesmo elemento, a minha célula cabeça e o proximo tem que ser NULL
}

int Verifica_Lista_Vazia(Lista_de_Cartas* lista_de_cartas){ // A função Lista Vazia retorna se a nossa lista encadeada possui elementos ou não. 
    return(lista_de_cartas-> primeiro == lista_de_cartas-> ultimo); // Retorna 1 se está vazia, e 0 se não.
} 


int Retornar_Tamanho_Lista(Lista_de_Cartas* lista_de_cartas){
    int tamanho = 1; // Comeca com 1 porque ele nao vai somar a ultima celula;
    if (Verifica_Lista_Vazia){
        tamanho=0;
    }
    Celula* auxiliar = lista_de_cartas -> primeiro -> prox; //
    while ( auxiliar != NULL) {
        auxiliar = auxiliar -> prox;
        tamanho += 1;
    }
    return tamanho;
}


Carta Retorna_Carta_do_Topo(Lista_de_Cartas* lista_de_cartas){
    // se a lista estiver estiver vazia a função não tem retorno
    if (!Verifica_Lista_Vazia){
        return lista_de_cartas -> ultimo -> carta;
    }
}

// Carta Retorna_Posicao_Carta(Lista_de_Cartas* lista_de_cartas, int posicaoCarta){} TERMINAR MELISSA

void Adicionar_Carta_ao_Topo(Lista_de_Cartas* lista_de_cartas, Carta* carta){ //Testar função
    lista_de_cartas -> ultimo -> prox = (Celula*)malloc(sizeof(Celula)); //Ligando minha nova celula a anterior a ela (antiga ultima)
    lista_de_cartas -> ultimo = lista_de_cartas -> ultimo -> prox; //Atualizando o meu ultimo para a nova celula alocada
    lista_de_cartas -> ultimo -> carta = *carta; //Passando o conteudo (carta) da minha nova celula
    lista_de_cartas -> ultimo -> prox = NULL; //Como o prox do ultimo não aponta para nada, passamos NULL
}

int Retirar_Carta_do_Topo(Lista_de_Cartas* lista_de_cartas){
    if (Verifica_Lista_Vazia){
        return 0;
    }
    Celula* celula_aux;
    celula_aux = lista_de_cartas -> ultimo;
    // lista_de_cartas -> ultimo = TERMINAR LETICIA
}

void Transferir_Carta(Lista_de_Cartas* lista_de_cartas, int quantidadeCarta){
    int tamanho = Retornar_Tamanho_Lista;
    int novo_tamanho = tamanho - quantidadeCarta;
    while(tamanho != novo_tamanho){
        
    }
    // lista_de_cartas -> primeiro ; TERMINAR CAIO
}
