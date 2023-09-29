#include "Carta.h"

typedef struct Celula {
    Carta carta;
    struct Celula* prox; 
} Celula;

typedef struct {
    Celula* primeiro;
    Celula* ultimo;
} Lista_de_Cartas;

void Inicializar_Lista_Vazia(Lista_de_Cartas* lista_de_cartas);
int Retornar_Tamanho_Lista(Lista_de_Cartas* lista_de_cartas);
int Verifica_Lista_Vazia(Lista_de_Cartas* lista_de_cartas);
Carta Retorna_Carta_do_Topo(Lista_de_Cartas* lista_de_cartas);
Carta Retorna_Carta_Posicao(Lista_de_Cartas* lista_de_cartas, int posicaoCarta);
void Adicionar_Carta_ao_Topo(Lista_de_Cartas* lista_de_cartas, Carta* carta);
int Retirar_Carta_do_Topo(Lista_de_Cartas* lista_de_cartas);
void Embaralhar_Baralho(Lista_de_Cartas* lista_de_cartas);
void Exibir_Lista_Cartas(Lista_de_Cartas *lista_de_cartas, char tipo_exibicao);
void Transferir_Carta(Lista_de_Cartas* lista_de_cartas, int quantidadeCarta, Lista_de_Cartas* lista_de_cartas_receptora);
