#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "Carta.h"
//#include "Lista_de_Cartas.h"
#include "Mesa.h"

/*
    COPAS E OUROS - NAIPES VERMELHOS
    ESPADA E PAUS - NAIPES PRETOS
*/

void Preenher_Baralho_Iterativo(Carta Baralho[53]){ // Inicializa o baralho que será usado no modo iterativo
    int valor, naipe;
    char naipes[4] = {'C', 'O', 'P', 'E'}; // C = copas, E = espada, P = paus, O = ouro 
    Inicializa_Carta(&Baralho[0], 0, 'V'); // Tornando a carta vazia "NULL", padronizamos que terá uma carta com o valor 0, ela será carta nula, por isso o vetor tem 53 posições

    for (int i = 1; i < 53; i++){
        valor = (i % 13) + 1; // Como o i%13 vai  gerar numeros de 0 a 12, por isso utilizei o "+1"
        naipe = naipes[i % 4];
        Inicializa_Carta(&Baralho[i], valor, naipe);
    }
}

int main() {
    Carta Baralho[53];
    
    Preenher_Baralho_Iterativo(Baralho);
   
    /*for (int i = 0; i < 53; i++){
        printf("- %d - %d %c %d\n", i, Baralho[i].valor, Baralho[i].naipe, Baralho[i].posicao);
    } */
 
//Testando os returns e a alteração da posição da carta (APAGAR DEPOIS)
    Lista_de_Cartas lista;
    Inicializar_Lista_Vazia(&lista);
    printf("%d\n", Verifica_Lista_Vazia(&lista));
    Adicionar_Carta_ao_Topo(&lista, &Baralho[1]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[2]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[3]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[4]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[5]);
    
    Exibir_Lista_Cartas(&lista, 'l');
    printf("\n");
    /*
    Altera_Posicao_Carta(&Baralho[5]);
    printf("A posicao da carta eh %d\n", Retorna_Posicao_Carta(&Baralho[5]));
    Altera_Posicao_Carta(&Baralho[5]);
    printf("A posicao da carta eh %d\n", Retorna_Posicao_Carta(&Baralho[5]));
    printf("O naipe da carta eh %c\n", Retorna_Naipe_Carta(&Baralho[5]));
    printf("O valor da carta eh %d", Retorna_Valor_Carta(&Baralho[5]));

    printf("A sequencia de naipe eh %d\n", Verifica_Sequencia_Naipe(&Baralho[0], &Baralho[40]));
    printf("A sequencia de alternada eh %d\n", Verifica_Sequencia_Alternada(&Baralho[38], &Baralho[37]));
    
    Exibir_Carta(&Baralho[1]);
    Altera_Posicao_Carta(&Baralho[1]);
    Exibir_Carta(&Baralho[1]);
    return 0;


    Lista_de_Cartas lista;
    Inicializar_Lista_Vazia(&lista);
    printf("%d\n", Verifica_Lista_Vazia(&lista));
    Adicionar_Carta_ao_Topo(&lista, &Baralho[1]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[2]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[3]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[4]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[5]);
    

    //Carta cartinha = Retorna_Carta_Posicao(&lista, 5);

    */Lista_de_Cartas lista2;
    Inicializar_Lista_Vazia(&lista2);
    Adicionar_Carta_ao_Topo(&lista2, &Baralho[6]);
    Adicionar_Carta_ao_Topo(&lista2, &Baralho[7]);
    Adicionar_Carta_ao_Topo(&lista2, &Baralho[8]);
    Adicionar_Carta_ao_Topo(&lista2, &Baralho[9]);
    Exibir_Lista_Cartas(&lista2, 'l');
    Transferir_Carta(&lista, 2 , &lista2);
    Exibir_Lista_Cartas(&lista2, 'l');
    printf("\n");
    Retorna_Carta_do_Topo(&lista);
    printf("Lista receptora\n");

    Retorna_Carta_do_Topo(&lista2);
    printf("\n");
    /* printf("%d\n", Retornar_Tamanho_Lista(&lista2));

    printf("\n LISTA 2 \n");
    Exibir_Lista_Cartas(&lista2, 'l'); // T para topo e L para lista inteira*/
    
    //
    
     // printf("A carta dessa posicao eh %d %c %d\n ", cartinha.valor, cartinha.naipe, cartinha.posicao);
    /*printf("\n BASE \n");
    Exibir_Lista_Cartas(&lista, 'l'); // T para topo e L para lista inteira
    printf("\n TEABLAU \n");
    Embaralhar_Baralho(&lista);
    Exibir_Lista_Cartas(&lista, 'l');
*/
    Mesa mesa;
    Inicializar_Mesa(&mesa);
    Carregar_Baralho_Aleatorio(&mesa);
    //Preparar_Tableau(&mesa);
    //Exibir_Mesa(&mesa);

    //printf("%d\n", Retornar_Tamanho_Lista(&lista));
    return 0;
}
