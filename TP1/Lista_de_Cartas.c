#include "Lista_de_Cartas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int tamanho=0; 
    if (Verifica_Lista_Vazia(lista_de_cartas)){ // Verifica se a lista é vazia, se for, a variavel tamanho recebe 0;
        return 0;
    }
    Celula* auxiliar = lista_de_cartas -> primeiro -> prox;
    while ( auxiliar != NULL) {
        tamanho += 1;   // Somamos um ao tamanho
        auxiliar = auxiliar -> prox; // Avançamos para a próxima celula da lista;
    }
    return tamanho;
}


Carta* Retorna_Carta_do_Topo(Lista_de_Cartas* lista_de_cartas){
    // se a lista estiver estiver vazia a função não tem retorno
    if (!Verifica_Lista_Vazia(lista_de_cartas)){
        return &(lista_de_cartas -> ultimo -> carta);
    }
}


Carta* Retorna_Carta_Posicao(Lista_de_Cartas* lista_de_cartas, int posicaoCarta){
    // Posição 0 (Carta do Topo): Ultima carta
    // Posição n (Carta do fundo): Primeira carta (Não é n-1 porque nao contamos a celula cabeça no tamanho da lista).
    if (posicaoCarta==Retornar_Tamanho_Lista(lista_de_cartas)) {
        return &(lista_de_cartas -> primeiro -> prox -> carta);
    }

    else if(posicaoCarta == 0){
        Retorna_Carta_do_Topo(lista_de_cartas);
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

    return &(aux -> carta);       
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
    lista_de_cartas -> ultimo  = celula_aux; // o campo ultimo aponta para a nova ultima celula (anterior à celula retirada);
    return 1;
}

void Transferir_Carta(Lista_de_Cartas* lista_de_cartas, int quantidadeCarta, Lista_de_Cartas* lista_de_cartas_receptora){
    if (Retornar_Tamanho_Lista(lista_de_cartas) < quantidadeCarta || quantidadeCarta <= 0){ 
        // Verifica se a lista doadora possui cartas suficientes a serem retiradas
        printf("Operacao invalida! Verifique a quantidade de cartas e o tamanho da lista, depois tente novamente");
    }
    
    int tamanho = Retornar_Tamanho_Lista(lista_de_cartas);
    int novo_tamanho = tamanho - quantidadeCarta;    // Analisa a quantidade de celulas que serao percorridas

    Celula* auxiliar = lista_de_cartas -> primeiro -> prox; // Comeca na primeira celula com conteudo
    Celula* auxiliar2 = lista_de_cartas -> primeiro; //Comeca da celula cabeça

    for( int i=0;i<novo_tamanho; i++){
        auxiliar2 = auxiliar2 -> prox; // Recebe o endereco de memoria da celula que se tornará a ultima
        auxiliar = auxiliar -> prox; // Recebe o endereco de memoria da celula que ira se tornar a primeira do bloco rompido}
    }
    
    lista_de_cartas_receptora -> ultimo -> prox = auxiliar; 
    //A antiga ultima posiçao da lista receptora vai apontar para as celula transplantada
    lista_de_cartas_receptora -> ultimo = lista_de_cartas -> ultimo;
    lista_de_cartas -> ultimo = auxiliar2; // A ultima celula é redefinida para a ultima celula que ficou apos a retirada
    lista_de_cartas -> ultimo -> prox = NULL; // Definindo que a lista de cartas tenha um final ( já que o seu ultimo foi retirado)
}

void Embaralhar_Baralho(Lista_de_Cartas* lista_de_cartas){
    
    //Preenchendo meu vetor com os itens da lista encadeada
    Celula* celula_aux = lista_de_cartas -> primeiro -> prox;
    int tamanho = Retornar_Tamanho_Lista(lista_de_cartas);
    Carta Baralho[tamanho];
    for(int i=0; i < tamanho; i++){
        Baralho[i] = celula_aux -> carta; // Preenchendo o meu vetor com as cartas da lista
        celula_aux = celula_aux -> prox;
    }
    
    // Embaralhando meu vetor usando Fisher-Yates
    int nova_posicao;
    Carta carta_aux;
    srand(time(NULL));
    for (int i = tamanho-1 ; i > 0; i--){
        nova_posicao = (rand() % (i)); // gerando uma posicao aleatoria que vai de 1 ate i
        carta_aux = Baralho[i];
        Baralho[i] = Baralho[nova_posicao];
        Baralho[nova_posicao] = carta_aux;

    }
    
    //Passando o vetor embaralhado para a minha lista encadeada
    celula_aux = lista_de_cartas -> primeiro -> prox;
    for(int i=0; i < tamanho; i++){
        celula_aux -> carta = Baralho[i]; 
        celula_aux = celula_aux -> prox;
    }

}

void Exibir_Lista_Cartas(Lista_de_Cartas *lista_de_cartas, char tipo_exibicao){ // RODAR FUNCAO DPS
    if (Verifica_Lista_Vazia(lista_de_cartas)){
        printf("[     ]");
    }
    else if(tipo_exibicao == 't'){
            Carta carta_aux = lista_de_cartas -> ultimo -> carta;
            Exibir_Carta(&carta_aux);
    } 
    else if (tipo_exibicao == 'l'){
        Celula *aux = lista_de_cartas -> primeiro -> prox;
        while(aux != NULL){
            Carta carta_aux = aux -> carta;
            Exibir_Carta(&(carta_aux));
            aux = aux -> prox;
        }
    }
}
