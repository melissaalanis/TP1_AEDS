#include "Mesa.h"
#include <stdlib.h>
//#include <stdio.h>

void Inicializar_Mesa(Mesa* mesa){ // Inicializa a nossa mesa e as nossas listas vazias
    Inicializar_Lista_Vazia(&(mesa -> Baralho));
    Inicializar_Lista_Vazia(&(mesa -> Descarte));

    for(int i=0; i<Qtd_Bases; i++){
        Inicializar_Lista_Vazia(&(mesa -> Base[i]));
        Carta* carta_vazia = (Carta*)malloc(sizeof(Carta));
        Inicializa_Carta(carta_vazia, 0, 'V');
        Adicionar_Carta_ao_Topo(&(mesa->Base[i]), (carta_vazia)); //Adiciona a carta nula
        /*
            Adicionamos uma carta vazia em todas as nossas bases para que a função
            Verificar Sequência Naipe funcione corretamente.
        */

    }

    for(int j=0; j<Qtd_Tableau; j++){
        Inicializar_Lista_Vazia(&(mesa -> Tableau[j]));
    }

    mesa -> pontuacao = 0;
}


void Carregar_Baralho_Aleatorio(Mesa* mesa){
    int valor, naipe;
    char naipes[Qtd_Naipes] = {'C', 'O', 'P', 'E'}; // C = copas, E = espada, P = paus, O = ouro

    for (int i = 0; i < Tam_Baralho; i++){
        Carta* carta_aux = (Carta*)malloc(sizeof(Carta));
        valor = (i % 13) + 1; // Como o i%13 vai  gerar numeros de 0 a 12, por isso utilizei o "+1"
        naipe = naipes[i % Qtd_Naipes];
        Inicializa_Carta(carta_aux, valor, naipe);
        Adicionar_Carta_ao_Topo(&(mesa -> Baralho), carta_aux);
    }
    Embaralhar_Baralho(&(mesa -> Baralho)); //Embaralha meu baralho
}


void Comprar_Carta(Mesa* mesa){
    int tamanho_Descarte = Retornar_Tamanho_Lista(&(mesa -> Descarte));  // Retorna o tamanho da lista Descarte    
    int tamanho_Baralho = Retornar_Tamanho_Lista(&(mesa -> Baralho)); // Retorna o tamanho da lista Baralho
       
   // Carta* auxiliar_Descarte = Retorna_Carta_do_Topo (&(mesa -> Descarte));

    if (tamanho_Baralho == 0){ // Verifica se o tamanho do Baralho é 0, se for, 
    //iremos passar todas as cartas do descarte para o barallho, virando-as para 0
        Carta* auxiliar = Retorna_Carta_do_Topo (&(mesa -> Baralho));
        mesa -> pontuacao -= 50;
        if (mesa -> pontuacao < 0){
            mesa -> pontuacao = 0;
        }
    
        for (int i=0; i<tamanho_Descarte; i++){ 
            Transferir_Carta(&(mesa -> Descarte), 1 ,(&mesa -> Baralho)); 
            // Transferi carta por carta do descarte para o Baralho
            auxiliar = Retorna_Carta_do_Topo (&(mesa -> Baralho));  
            Altera_Posicao_Carta(auxiliar); // Enquanto vamos transferindo, vamos virando ela para 0 
            //(Ja que todas as cartas que estavam no Descarte estavam na posicao 1);
        }
    } else {
        Transferir_Carta(&(mesa -> Baralho), 1 , &(mesa -> Descarte)); 
        Carta* auxiliar_Descarte = Retorna_Carta_do_Topo (&(mesa -> Descarte)); 
        Altera_Posicao_Carta(auxiliar_Descarte);
    }
}


void Preparar_Tableau(Mesa* mesa){
    for (int i = 0; i < Qtd_Tableau; i++){
        Transferir_Carta(&(mesa->Baralho), i + 1, &(mesa->Tableau[i]));
        Carta* carta_topo = Retorna_Carta_do_Topo(&(mesa->Tableau[i]));
        Altera_Posicao_Carta(carta_topo);
    }
}


int Verificar_Vitoria(Mesa * mesa){
    Carta* carta_aux;
    int contador=0;
    for(int i=0; i< Qtd_Bases; i++){ // Para cada base, verificaremos se o item do topo é igual a 13. Se for, acrescentar ao cont.
        carta_aux = Retorna_Carta_do_Topo(&(mesa -> Base[i]));
        if (Retorna_Valor_Carta(carta_aux) == 13){
            contador++;
        }
    }
    if(contador == Qtd_Bases){ // Quando o contador for igual a Qtd_Bases, então todas as bases estão preenchidas e a pessoa venceu.

        return True;
    }

    return False;
}


void Mover_Descarte_Base(Mesa* mesa){
    int i; 
    int contador = 0;
    Carta* carta_aux_Descarte = Retorna_Carta_do_Topo(&(mesa->Descarte)); //Pegando a carta do topo do descarte
    Carta* carta_aux_Base;
    
    for (i = 0; i < Qtd_Bases; i++){
        carta_aux_Base = Retorna_Carta_do_Topo(&(mesa->Base[i])); //Pegando a carta do topo das Bases
   
        if (Verifica_Sequencia_Naipe(carta_aux_Base, carta_aux_Descarte)){ //Verifica se o movimento é válido
            Transferir_Carta(&(mesa -> Descarte), 1, &(mesa -> Base[i]));
            Carta *novo_topo_base = Retorna_Carta_do_Topo(&(mesa -> Base[i]));
            Altera_Posicao_Carta(novo_topo_base);
            contador ++;
            break;
        } 
    }
    if(contador == 0){
        printf("MOVIMENTO INVALIDO\n");
    }
    mesa -> pontuacao += 10;
}

void Mover_Descarte_Tableau(Mesa* mesa, int tableau){
    Carta* carta_aux_descarte = Retorna_Carta_do_Topo(&(mesa->Descarte)); //Pegando a carta do topo do descarte
    Carta* carta_aux_tableau = Retorna_Carta_do_Topo(&(mesa->Tableau[tableau-1])); //Pegando a carta do topo do tableau 
    //(usamos tableau-1 porque recebemos um valor de 1 a Qtd_Tableau, mas o valor é de 0 a 6)
    
    if (Verifica_Sequencia_Alternada(carta_aux_tableau, carta_aux_descarte)){ 
        if(Retorna_Valor_Carta(carta_aux_tableau) == 0){
            Retirar_Carta_do_Topo(&(mesa->Tableau[tableau - 1]));
        }
        // # RELEMBRANDO: A funcao acima verifica se a carta 1 é exatamente uma unidade maior que a segunda
        Transferir_Carta(&(mesa -> Descarte), 1, &(mesa -> Tableau[tableau-1]));
        mesa -> pontuacao += 5;
    } else {
        printf("MOVIMENTO INVALIDO\n");
    }

    
}

void Mover_Tableau_Base(Mesa* mesa, int tableau){
    int i; 
    int contador = 0;
    Carta* carta_aux_Tableau = Retorna_Carta_do_Topo(&(mesa->Tableau[tableau-1])); //Pegando a carta do topo do TABLEAU
    Carta* carta_aux_Base;
    for (i = 0; i < Qtd_Bases; i++){
        carta_aux_Base = Retorna_Carta_do_Topo(&(mesa->Base[i])); //Pegando a carta do topo das Bases

        if (Verifica_Sequencia_Naipe(carta_aux_Base, carta_aux_Tableau)){ //Verifica se o movimento é válido
            Transferir_Carta(&(mesa -> Tableau[tableau-1]), 1, &(mesa -> Base[i]));
            mesa -> pontuacao += 10;
            if (Verifica_Lista_Vazia(&(mesa->Tableau[tableau- 1]))){
                Carta* carta_vazia = (Carta*)malloc(sizeof(Carta));
                Inicializa_Carta(carta_vazia, 0, 'V');
                Adicionar_Carta_ao_Topo(&(mesa->Tableau[tableau - 1]), (carta_vazia)); //Adiciona a carta nula
            
            } else {
                Carta *novo_topo_tableau = Retorna_Carta_do_Topo(&(mesa -> Tableau[tableau-1]));
                Altera_Posicao_Carta(novo_topo_tableau);
                mesa -> pontuacao += 5;
            }
            contador ++;
            break;
        } 
    }
    if(contador == 0){
        printf("MOVIMENTO INVALIDO\n");
    }
    
}   

void Mover_no_Tableau(Mesa* mesa, int qtd, int tableau_chegada, int tableau_saida){
    Carta* carta_aux_saida = Retorna_Carta_Posicao(&(mesa->Tableau[tableau_saida - 1]), qtd-1); 
    //Pegando a carta referencia do bloco de saída
    //(a carta que ira definir se o movimento eh valido)
    if(Retorna_Posicao_Carta(carta_aux_saida) == True){
        Carta* carta_aux_chegada = Retorna_Carta_do_Topo(&(mesa->Tableau[tableau_chegada- 1])); 
        //Pegando a primeira carta do tableu que recebera o novo bloco
        //(usamos tableu-1 porque recebemos um valor de 1 a Qtd_Tableau, mas o valor eh de 0 a 6)
        
        if (Verifica_Sequencia_Alternada(carta_aux_chegada, carta_aux_saida)){ //Verifica se o movimento eh valido
            if(Retorna_Valor_Carta(carta_aux_chegada) == 0){
                Retirar_Carta_do_Topo(&(mesa->Tableau[tableau_chegada - 1]));
            }

            Transferir_Carta(&(mesa->Tableau[tableau_saida - 1]), qtd, &(mesa->Tableau[tableau_chegada - 1]));
            
            //Como foi movido n cartas, o meu topo muda e sera necessario alterar minha nova carta do topo 
            //(revelar a carta do Tableau, se minha lista nao for vazia, se for adicionar minha carta nula a minha lista)  
            
            if (Verifica_Lista_Vazia(&(mesa->Tableau[tableau_saida - 1]))){
                Carta* carta_vazia = (Carta*)malloc(sizeof(Carta));
                Inicializa_Carta(carta_vazia, 0, 'V');
                Adicionar_Carta_ao_Topo(&(mesa->Tableau[tableau_saida - 1]), (carta_vazia)); //Adiciona a carta nula
            } else {      
                Carta* novo_topo = Retorna_Carta_do_Topo(&(mesa->Tableau[tableau_saida- 1])); 
                Altera_Posicao_Carta(novo_topo); //Revelando a carta do topo
                mesa -> pontuacao += 5;
            }
            
        } else {
            printf("MOVIMENTO INVALIDO\n");
        }
    } else {
        printf("MOVIMENTO INVALIDO! REVELE ANTES TODAS AS CARTAS QUE DESEJA MOVER!\n");
    }
    
}

void Mover_Bases_Tableau(Mesa * mesa, int base, int tableau){ // Move uma carta de uma das bases para o Tableau
    Carta* carta_aux_base = Retorna_Carta_do_Topo(&(mesa->Base[base-1])); //Pegando a carta do topo do descarte
    //Não tem o base-1 pq o valor das bases vai de 0 a 3, segundo o arquivo teste 
    Carta* carta_aux_tableau = Retorna_Carta_do_Topo(&(mesa->Tableau[tableau-1])); //Pegando a carta do topo do tableau 
    //(usamos tableau-1 porque recebemos um valor de 1 a Qtd_Tableau, mas o valor é de 0 a 6)
    
    if (Verifica_Sequencia_Alternada(carta_aux_tableau, carta_aux_base)){ 
        if(Retorna_Valor_Carta(carta_aux_tableau) == 0){
            Retirar_Carta_do_Topo(&(mesa->Tableau[tableau - 1]));
        }
        // # RELEMBRANDO: A funcao acima verifica se a carta 1 é exatamente uma unidade maior que a segunda
        Transferir_Carta(&(mesa -> Base[base-1]), 1, &(mesa -> Tableau[tableau-1]));
        mesa -> pontuacao -= 15; 
        if (mesa -> pontuacao < 0){ // Se a pontuacao ficar negativa, então ela é zerada.
            mesa -> pontuacao = 0;
        }
    } else {
        printf("MOVIMENTO INVALIDO");
    }

}

void Exibir_Mesa(Mesa* mesa){
    printf("PONTUACAO: %d\n", mesa -> pontuacao);
    
    printf("\nBASES:\n");
    for(int j=0; j < Qtd_Bases ; j++){
        Exibir_Lista_Cartas(&(mesa -> Base[j]), 't'); //Exibe apenas o topo das bases
    }
    
    printf("\n");
    printf("\nTABLEAU:\n");
    for(int i=0; i < Qtd_Tableau ; i++){
        printf("%d) ", i+1);
        Exibir_Lista_Cartas(&(mesa -> Tableau[i]), 'l'); //Exibe o tableau inteiro
        printf("\n");
    }

    printf("\nBARALHO | DESCARTE\n");
    Exibir_Lista_Cartas(&(mesa-> Baralho), 't'); //Exibe apenas o topo do Baralho 
    printf("   ");
    Exibir_Lista_Cartas(&(mesa-> Descarte), 't'); //Exibe apenas o topo do Descarte
}
void Inicializar_Baralho_Arquivo(Mesa *mesa, FILE *arq){ 
    //Recebo um ponteiro para o arquivo que foi informado no main
    int tamanho_total;
    
    int valor;
    char naipe;

    fscanf(arq, "%d\n", &tamanho_total);//Pego o tamanho do meu baralho

    for (int i = 0; i < tamanho_total; i++){
        fscanf(arq, "(%d %c) ", &valor, &naipe);//Lendo o valor e naipe das cartas que estão no arquivo
        Carta* carta_aux = (Carta*)malloc(sizeof(Carta));
        Inicializa_Carta(carta_aux, valor, naipe);
        Adicionar_Carta_ao_Topo(&(mesa->Baralho), carta_aux);
    }

}


//Como escolhemos trabalhar com o topo sendo o final da lista, 
//mas o arquivo seguia uma abordagem difente, foi necessário
//alterar o tableau, invertendo cada base dele
void Preparar_Tableau_Arquivo(Mesa* mesa){ 
    Lista_de_Cartas lista_aux;
    for (int i = 0; i < Qtd_Tableau; i++){
        Inicializar_Lista_Vazia(&lista_aux);
        Transferir_Carta(&(mesa->Baralho), i + 1, &lista_aux);

        for (int j = 0; j < i+1; j++){
            Transferir_Carta(&lista_aux, 1, &(mesa->Tableau[i]));
        }

        Carta* carta_topo = Retorna_Carta_do_Topo(&(mesa->Tableau[i]));
        Altera_Posicao_Carta(carta_topo);
    }
}