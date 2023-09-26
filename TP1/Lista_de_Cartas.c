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


Carta Retorna_Carta_Posicao(Lista_de_Cartas* lista_de_cartas, int posicaoCarta){
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
    novotam--;

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
    if (Verifica_Lista_Vazia(lista_de_cartas)){  //Não é possível retirar carta de uma lista vazia
        return 0;
    } 
    
    Celula* celula_aux = lista_de_cartas -> primeiro; //celula auxiliar começa com o minha primeira carta (contando com a celula cabeça)
    
    while(celula_aux -> prox -> prox != NULL ){ //verifica se o campo prox da minha proxima célula é NULL, se a próxima carta é a ultima
        celula_aux = celula_aux -> prox; 
    } 
    free(celula_aux -> prox); //libera o espaço da memória do meu antigo ultimo item 
    celula_aux -> prox = NULL; //o campo prox da minha nova ultima celula é NULL
    lista_de_cartas -> ultimo  = celula_aux; //passa minha nova ultima celula para o meu ponteiro
    return 1;
}

void Transferir_Carta(Lista_de_Cartas* lista_de_cartas, int quantidadeCarta, Lista_de_Cartas* lista_de_cartas_receptora){
    
    if (Verifica_Lista_Vazia(lista_de_cartas)){ // Verifica se a lista doadora está vazia
        printf("Operacao invalida");
    }

    if (Retornar_Tamanho_Lista(lista_de_cartas) <= quantidadeCarta){ // Verifica se a lista doadora possui cartas suficientes a serem retiradas
        printf("Operacao invalida 1");
    }
    
    int tamanho = Retornar_Tamanho_Lista(lista_de_cartas);
    int novo_tamanho = tamanho - quantidadeCarta;    // Analisa a quantidade de celulas que serao percorridas

    Celula* auxiliar = lista_de_cartas -> primeiro -> prox; // Comeca na primeira celula com conteudo
    Celula* auxiliar2 = lista_de_cartas -> primeiro; //Comeca da celula cabeça

    for( int i=0;i<novo_tamanho; i++){
        auxiliar2 = auxiliar2 -> prox; // Recebe o endereco de memoria da celula que se tornará a ultima
        auxiliar = auxiliar -> prox; // Recebe o endereco de memoria da celula que ira se tornar a primeira quando houver o rompimento
    }

    lista_de_cartas -> ultimo = auxiliar2; // A ultima celula é redefinida para a ultima celula que ficou apos a retirada
    lista_de_cartas -> ultimo -> prox = NULL; // Definindo que a lista de cartas tenha um final ( já que o seu ultimo foi retirado)
    lista_de_cartas_receptora -> ultimo -> prox = auxiliar; // A antiga ultima posiçao da lista receptora passa a apontar para as celula transplantada
}

void Embaralhar_Carta(Lista_de_Cartas* lista_de_cartas, Carta* carta){
    int tamanho = Retornar_Tamanho_Lista(lista_de_cartas)-2;
    char* vetor = (int *)malloc(tamanho * sizeof(int));
    for(int i=0; i < tamanho; i++){
        lista_de_cartas -> primeiro -> prox;
        vetor[i] = lista_de_cartas -> primeiro -> carta ; // Preenchendo o meu vetor com os enderecos de memoria TA DANDO ERROOOOOOOOOOOOOOOOOO
        // tenho que retirar essa celula aq 
    }

	for (int i = 0; i < tamanho; i++){ // Embaralhar o vetor
		int r = rand() % tamanho;
		int temp = vetor[i];
		vetor[i] = vetor[r];
		vetor[r] = temp;
	}

    for (int i = 0; i < tamanho; i++){
		printf("Vetor posicao: %d %d",i, vetor[i]);
	}

}

void Exibir_Lista_Cartas(Lista_de_Cartas *lista_de_cartas, char tipo_exibicao){ // RODAR FUNCAO DPS
    if (Verifica_Lista_Vazia(lista_de_cartas) == 1){
        printf("LISTA VAZIA\n");
    }
    else if(tipo_exibicao == 't'){
            Carta carta_aux = lista_de_cartas -> ultimo -> carta;
            printf("%d %c %d\n", carta_aux.valor, carta_aux.naipe, carta_aux.posicao);
    }
    else if (tipo_exibicao == 'l'){
        Celula *aux = lista_de_cartas -> primeiro -> prox;
        while(aux != NULL){
            Carta carta_aux = aux -> carta;
            printf("%d %c %d\n", carta_aux.valor, carta_aux.naipe, carta_aux.posicao);
            aux = aux -> prox;
        }
    }
}