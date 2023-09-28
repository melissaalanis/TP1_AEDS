#include "Mesa.h"
#include <stdlib.h>
#include <stdio.h>

void Inicializar_Mesa(Mesa* mesa){ // Inicializa a nossa mesa e as nossas listas vazias
    Inicializar_Lista_Vazia(&(mesa -> Baralho));
    Inicializar_Lista_Vazia(&(mesa -> Descarte));
    
    for(int i=0; i<4; i++){
        Inicializar_Lista_Vazia(&(mesa -> Base[i]));
    }

    for(int j=0; j<7; j++){
        Inicializar_Lista_Vazia(&(mesa -> Tableau[j]));
    }

    mesa -> pontuacao = 0;
}


void Carregar_Baralho_Aleatorio(Mesa* mesa){
    int valor, naipe;
    char naipes[4] = {'C', 'O', 'P', 'E'}; // C = copas, E = espada, P = paus, O = ouro 
    //Inicializa_Carta(&Baralho[0], 0, 'V'); // Tornando a carta vazia "NULL", padronizamos que terá uma carta com o valor 0, ela será carta nula, por isso o vetor tem 53 posições

    for (int i = 0; i < 52; i++){
        Carta* carta_aux = (Carta*)malloc(sizeof(Carta));
        valor = (i % 13) + 1; // Como o i%13 vai  gerar numeros de 0 a 12, por isso utilizei o "+1"
        naipe = naipes[i % 4];
        Inicializa_Carta(carta_aux, valor, naipe);
        Adicionar_Carta_ao_Topo(&(mesa -> Baralho), carta_aux);
    }
    Embaralhar_Baralho(&(mesa -> Baralho)); //Embaralha meu baralho*/
    
}


void Comprar_Carta(Mesa* mesa){
    int tamanho_Descarte = Retornar_Tamanho_Lista(&(mesa -> Descarte));  // Retorna o tamanho da lista Descarte    
    int tamanho_Baralho = Retornar_Tamanho_Lista(&(mesa -> Baralho)); // Retorna o tamanho da lista Baralho
    Carta auxiliar = Retorna_Carta_do_Topo (&(mesa -> Baralho));   
    Carta auxiliar_Descarte = Retorna_Carta_do_Topo (&(mesa -> Descarte));

    if (tamanho_Baralho == 0){ // Verifica se o tamanho do Baralho é 0, se for, iremos passar todas as cartas do descarte para o barallho, virando-as para 0

        mesa -> pontuacao -= 50;
        if (mesa -> pontuacao < 0){
            mesa -> pontuacao = 0;
        }
        
        for (int i=0; i<tamanho_Descarte; i++){ 
            Transferir_Carta(&(mesa -> Descarte), 1 ,(&(mesa -> Baralho))); // Tranferi carta por carta do descarte para o Baralho
            Altera_Posicao_Carta(&auxiliar); // Enquanto vamos transferindo, vamos virando ela para 0 (Ja que todas as cartas que estavam no Descarte estavam na posicao 1);
        }
    }

    Transferir_Carta(&(mesa -> Baralho), 1 , &(mesa -> Descarte));  
    Altera_Posicao_Carta(&auxiliar_Descarte);
    
}


void Preparar_Tableau(Mesa* mesa){
    Carta carta_aux;
    for (int i = 0; i < 7; i++){ //O for repete 7 vezes, uma para cada lista do tablau
        carta_aux = Retorna_Carta_do_Topo(&(mesa -> Tableau[i]));
        Transferir_Carta(&(mesa -> Baralho), i+1, &(mesa -> Tableau[i])); //Transferindo minhas cartas do baralho para as listas do tablau, 
        //de acordo com as especificações de tamannho
        Altera_Posicao_Carta(&carta_aux); //deixando apenas o topo da minha lista para cima
    }
}


int Verificar_Vitoria(Mesa * mesa){
    Carta carta_aux;
    int contador=0;
    for(int i=0; i< 4; i++){ // Para cada base, verificaremos se o item do topo é igual a 13. Se for, acrescentar ao cont.
        carta_aux = Retorna_Carta_do_Topo(&(mesa -> Base[i]));
        if (Retorna_Valor_Carta(&carta_aux) == 13){
            contador++;
        }
    }
    if(contador == 4){ // Quando o contador for igual a 4, então todas as bases estão preenchidas e a pessoa venceu.

        return True;
    }

    return False;
}


void Mover_Descarte_Base(Mesa* mesa, int base){
    Carta carta_aux_descarte = Retorna_Carta_do_Topo(&(mesa->Descarte)); //Pegando a carta do topo do descarte
    Carta carta_aux_base = Retorna_Carta_do_Topo(&(mesa->Base[base-1])); //Pegando a carta do topo da base 
    //(usamos base-1 porque recebemos um valor de 1 a 4, mas o valor é de 0 a 3)
    
    if (Verifica_Sequencia_Naipe(&(carta_aux_descarte), &(carta_aux_base))){ //Verifica se o movimento é válido
        Transferir_Carta(&(mesa -> Descarte), 1, &(mesa -> Base[base-1]));
    } else {
        printf("Movimento Inválido");
    }

    mesa -> pontuacao += 10;
}

void Mover_Descarte_Tableau(Mesa* mesa, int tableau){
    Carta carta_aux_descarte = Retorna_Carta_do_Topo(&(mesa->Descarte)); //Pegando a carta do topo do descarte
    Carta carta_aux_tableau = Retorna_Carta_do_Topo(&(mesa->Tableau[tableau-1])); //Pegando a carta do topo do tableau 
    //(usamos tableau-1 porque recebemos um valor de 1 a 7, mas o valor é de 0 a 6)
    
    if (Verifica_Sequencia_Alternada(&(carta_aux_descarte), &(carta_aux_tableau))){ 
        // # RELEMBRANDO: A funcao acima verifica se a carta 1 é exatamente uma unidade maior que a segunda
        Transferir_Carta(&(mesa -> Descarte), 1, &(mesa -> Tableau[tableau-1]));
    } else {
        printf("Movimento Inválido");
    }

    mesa -> pontuacao += 5;
}

void Mover_Tableau_Base(Mesa* mesa, int base){
    Carta carta_aux_Tableau = Retorna_Carta_do_Topo(&(mesa->Descarte)); //Pegando a carta do topo do Tableau
    Carta carta_aux_Base = Retorna_Carta_do_Topo(&(mesa->Base[base-1])); //Pegando a carta do topo da base 
    //(usamos base-1 porque recebemos um valor de 1 a 4, mas o valor é de 0 a 3)
    
    if (Verifica_Sequencia_Naipe(&(carta_aux_Tableau), &(carta_aux_Base))){ //Verifica se o movimento é válido
        Transferir_Carta(&(mesa -> Tableau), 1, &(mesa -> Base[base-1]));
    } else {
        printf("Movimento Inválido");
    }

    mesa -> pontuacao += 10;
}


void Mover_no_Tableau(Mesa* mesa, int qtd, int tableau_chegada, int tableau_saida){
    Carta carta_aux_saida = Retorna_Carta_Posicao(&(mesa->Tableau[tableau_saida - 1]), qtd); //Pegando a carta referência do bloco de saída
    //(a carta que irá definir se o movimento é válido)
    Carta carta_aux_chegada = Retorna_Carta_do_Topo(&(mesa->Tableau[tableau_chegada- 1])); //Pegando a primeira carta do tableu que receberá o novo bloco
    //(usamos tableu-1 porque recebemos um valor de 1 a 7, mas o valor é de 0 a 6)
    
    if (Verifica_Sequencia_Alternada(&(carta_aux_chegada), &(carta_aux_saida))){ //Verifica se o movimento é válido
        Transferir_Carta(&(mesa->Tableau[tableau_saida - 1]), qtd, &(mesa->Tableau[tableau_chegada - 1]));
        
        //Como foi movido n cartas, o meu topo muda e será necessário alterar minha nova carta do topo 
        //(revelar a carta do Tableau, se minha lista não for vazia, se for adicionar minha carta nula a minha lista)  
        
        if (Verifica_Lista_Vazia){
            Carta novo_topo;
            Inicializa_Carta(&novo_topo, 0, 'V');
            Adicionar_Carta_ao_Topo(&(mesa->Tableau[tableau_saida - 1]), &(novo_topo)); //Adiciona a carta nula
        } else {      
            Carta novo_topo = Retorna_Carta_do_Topo(&(mesa->Tableau[tableau_saida- 1])); 
            Altera_Posicao_Carta(&(novo_topo)); //Revelando a carta do topo
            mesa -> pontuacao += 5;
        }
        
    } else {
        printf("Movimento Inválido");
    }
    
}

void Mover_Bases_Tableau(Mesa * mesa, int base, int tableau){ // Move uma carta de uma das bases para o Tableau
    Carta carta_aux_base = Retorna_Carta_do_Topo(&(mesa->Base[base-1])); //Pegando a carta do topo do descarte
    Carta carta_aux_tableau = Retorna_Carta_do_Topo(&(mesa->Tableau[tableau-1])); //Pegando a carta do topo do tableau 
    //(usamos tableau-1 porque recebemos um valor de 1 a 7, mas o valor é de 0 a 6)
    
    if (Verifica_Sequencia_Alternada(&(carta_aux_base), &(carta_aux_tableau))){ 
        // # RELEMBRANDO: A funcao acima verifica se a carta 1 é exatamente uma unidade maior que a segunda
        Transferir_Carta(&(mesa -> Base[base-1]), 1, &(mesa -> Tableau[tableau-1]));
        mesa -> pontuacao -= 15; 
        if (mesa -> pontuacao < 0){ // Se a pontuacao ficar negativa, então ela é zerada.
            mesa -> pontuacao = 0;
        }
    } else {
        printf("Movimento Inválido");
    }

}

void Exibir_Mesa(Mesa* mesa){
    for(int j=0; j < 4 ; j++){
        Exibir_Lista_Cartas(&(mesa -> Base[j]), "l");}
    for(int i=0; i < 7 ; i++){
        Exibir_Lista_Cartas(&(mesa -> Tableau[i]), "l");}
    Exibir_Lista_Cartas(&(mesa-> Descarte), "t");
    
}