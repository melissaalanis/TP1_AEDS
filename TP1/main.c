#include <stdio.h>
#include <stdlib.h>
#include "Carta.h"

void Preenher_Baralho_Iterativo(Carta Baralho[52]){ // Inicializa o baralho que será usado no modo iterativo
    int valor, naipe;
    char naipes[4] = {'C', 'O', 'P', 'E'};

    for (int i = 0; i < 52; i++){
        valor = (i % 13) + 1; // Como o i%13 vai  gerar numeros de 0 a 12, por isso utilizei o "+1"
        naipe = naipes[i % 4];
        Inicializa_Carta(&Baralho[i], valor, naipe);
    }
}

int main() {
    Carta Baralho[52];
    
    Preenher_Baralho_Iterativo(Baralho);

    for (int i = 0; i < 52; i++){
        printf("%d %c %d\n", Baralho[i].valor, Baralho[i].naipe, Baralho[i].posicao);
    }

    return 0;  
}
