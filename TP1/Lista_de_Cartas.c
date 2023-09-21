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


Carta Retorna_Posicao_Carta(Lista_de_Cartas* lista_de_cartas, int posicaoCarta){ // CORRIGIR ERROS TERMINAL - MELISSA
    // Posição 0 (Carta do Topo): Ultima carta
    // Posição n (Carta do fundo): Primeira carta (Não é n-1 porque nao contamos a celula cabeça no tamanho da lista.)
    if (posicaoCarta==Retornar_Tamanho_Lista(lista_de_cartas)) {
        return lista_de_cartas -> primeiro -> prox -> carta;
    }

    else if(posicaoCarta == 0){
        return lista_de_cartas -> ultimo -> carta;
    }

    else{
        int tam = Retornar_Tamanho_Lista(lista_de_cartas);
        int novotam = tam - posicaoCarta;
        novotam++;

        Celula *aux = lista_de_cartas -> primeiro -> prox;
        int contador = 0;
        while(contador != novotam){
            contador++;
            aux = aux -> prox;
        }

        return aux -> carta;       
    }

}

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
    Celula* auxiliar = lista_de_cartas -> primeiro -> prox;
    Celula* auxiliar2 = lista_de_cartas -> primeiro;
    int tamanho = Retornar_Tamanho_Lista(lista_de_cartas);
    int novo_tamanho = tamanho - quantidadeCarta;
    printf("\n numero de cartas iniciais: %d ", tamanho);
    while(tamanho != novo_tamanho){
        auxiliar2 = auxiliar2 -> prox; // Recebe o endereco de memoria da celula que se tornará a ultima
        auxiliar = auxiliar -> prox; // Recebe o endereco de memoria da celula que ira se tornar a primeira quando houver o rompimento
        tamanho = tamanho - 1;
    }
    lista_de_cartas -> ultimo = auxiliar2;
    lista_de_cartas -> ultimo -> prox = NULL;
    
    printf("\n numero de cartas removidas: %d ", quantidadeCarta);
    printf("\n numero de cartas atuais: %d ", novo_tamanho);
}
