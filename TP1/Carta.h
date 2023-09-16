// Os defines, linha 2 e 3, serão usados para definir a posição das cartas
#define True 1
#define False 0

typedef struct {
    char naipe; // C = copas, E = espada, P = paus, O = ouro 
    int valor; // inteiro de 1(ÁS) até 13(k)
    int posicao; // False = virado para baixo e True = virado para cima
} Carta;

void Inicializa_Carta(Carta* carta, int iValor, char naipe);

// Retorna o valor, a posição e  o naipe da carta
int Retorna_Valor_Carta(Carta* carta);
int Retorna_Posicao_Carta(Carta* carta); 
char Retorna_Naipe_Carta(Carta* carta);

//  Alterar a posição
void Altera_Posicao_Carta(Carta* carta);

// Operações entre cartas do TAD Carta
int Verifica_Sequencia_Naipe(Carta* carta1, Carta* carta2);
int Verifica_Sequencia_Alternada(Carta* carta1, Carta* carta2);// carta1= carta debaixo e carta2=carta de cima



