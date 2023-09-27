#include "Lista_de_Cartas.h"

typedef struct {
    Lista_de_Cartas Baralho;
    Lista_de_Cartas Descarte;
    Lista_de_Cartas Base[4];
    Lista_de_Cartas Tableau[7];
    int pontuacao;
} Mesa;

void Inicializar_Mesa(Mesa* mesa);
void Carregar_Baralho_Aleatorio(Mesa* mesa);
void Preparar_Tableau(Mesa* mesa);
int Verificar_Vitoria(Mesa* mesa);
void Comprar_Carta(Mesa* mesa);
void Mover_Descarte_Base(Mesa* mesa, int base);