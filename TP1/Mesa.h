#include "Lista_de_Cartas.h"

typedef struct {
    Lista_de_Cartas Baralho;
    Lista_de_Cartas Descarte;
    Lista_de_Cartas* Base[4];
    Lista_de_Cartas* Tableau[7];
    int pontuacao;
} Mesa;

void Inicializar_Mesa(Mesa* mesa);
void Carregar_Baralho_Aleatorio(Mesa* mesa);
void PreparaTableau(Mesa* mesa, Lista_de_Cartas Baralho, Lista_de_Cartas* Tableau[7]);
void Verificar_Vitoria(Mesa* mesa, Lista_de_Cartas* Bases[4]);
void Comprar_Carta(Mesa* mesa, Lista_de_Cartas Descarte);
void Verifica_Vitoria(Mesa* mesa);