#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "Carta.h"
#include "Lista_de_Cartas.h"

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

void Embaralhar(Carta Baralho[53]){
    int nova_posicao;
    Carta carta_aux;
    srand(time(NULL));

    for (int i = 52; i > 0; i--){
        nova_posicao = (rand() % i)+1; 
        // gerando uma posição aleatória que vai de 1 ate i, o (rand() % i) gera um valor de 0 até i-1, 
        // o "+1" no final garante que i esteja entre 0 e i 
        carta_aux = Baralho[i];
        Baralho[i] = Baralho[nova_posicao];
        Baralho[nova_posicao] = carta_aux;
    }
}

int main() {
    Carta Baralho[53];
    
    Preenher_Baralho_Iterativo(Baralho);
    Embaralhar(Baralho);
    for (int i = 0; i < 53; i++){
        printf("- %d - %d %c %d\n", i, Baralho[i].valor, Baralho[i].naipe, Baralho[i].posicao);
    }

/* Testando os returns e a alteração da posição da carta (APAGAR DEPOIS)
    Altera_Posicao_Carta(&Baralho[5]);
    printf("A posicao da carta eh %d\n", Retorna_Posicao_Carta(&Baralho[5]));
    printf("O naipe da carta eh %c\n", Retorna_Naipe_Carta(&Baralho[5]));
    printf("O valor da carta eh %d", Retorna_Valor_Carta(&Baralho[5]));

    printf("A sequencia de naipe eh %d\n", Verifica_Sequencia_Naipe(&Baralho[0], &Baralho[40]));
    printf("A sequencia de alternada eh %d\n", Verifica_Sequencia_Alternada(&Baralho[38], &Baralho[37]));
    
    Exibir_Carta(&Baralho[0]);
    Altera_Posicao_Carta(&Baralho[1]);
    Exibir_Carta(&Baralho[1]);
    return 0;
*/

    Lista_de_Cartas lista;
    Inicializar_Lista_Vazia(&lista);
    printf("%d\n", Verifica_Lista_Vazia(&lista));
    Adicionar_Carta_ao_Topo(&lista, &Baralho[1]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[2]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[3]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[4]);
    Adicionar_Carta_ao_Topo(&lista, &Baralho[5]);
    
    
    printf("t1%d\n", Retornar_Tamanho_Lista(&lista));
    Retirar_Carta_do_Topo(&lista);
    printf("t2%d\n", Retornar_Tamanho_Lista(&lista));

    Carta cartinha = Retorna_Carta_Posicao(&lista, 5);

    Lista_de_Cartas lista2;
    Inicializar_Lista_Vazia(&lista2);
    Adicionar_Carta_ao_Topo(&lista2, &Baralho[1]);
    Adicionar_Carta_ao_Topo(&lista2, &Baralho[2]);
    printf("%d\n", Retornar_Tamanho_Lista(&lista2));
    
    Transferir_Carta(&lista, 2 , &lista2);
    
    printf("A carta dessa posicao eh %d %c %d\n ", cartinha.valor, cartinha.naipe, cartinha.posicao);

    // printf("%d\n", Retornar_Tamanho_Lista(&lista));
    return 0;
}
