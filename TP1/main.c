#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Mesa.h"

/*
    COPAS E OUROS - NAIPES VERMELHOS
    ESPADA E PAUS - NAIPES PRETOS
*/

int main() {
    printf("ok");
    //Mesa mesa;
    //Inicializar_Mesa(&mesa);
   
    /*int formato_jogo;

    printf("PACIENCIA\n");

    char nome_jogador[30];
    printf("Qual o nome do jogador(a)? ");
    scanf("%s", nome_jogador);
    system("clear");
    
    printf("Bem-vindo(a), %s! :)\n", nome_jogador);
    printf("\nMENU:\n1) Modo Interativo\n2) Utilizando Arquivo\n");
    printf("\nCom base nos numeros do menu acima escolha o formato do jogo:\n");
    scanf("%d", &formato_jogo);
    system("clear");

    if(formato_jogo == 1){
        printf("PACIENCIA MODO INTERATIVO\n");
        int jogada;
        int continua_jogo = True; //Será usado no while True
        int num_tableau, num_base, qtd, num_tableau_saida, num_tableau_chegada; //sera usado no switch case*/
        printf("ok");
        //Carregar_Baralho_Aleatorio(&mesa);
    
        

     //while(continua_jogo == True){
            //Preparar_Tableau(&mesa);
            //Exibir_Mesa(&mesa);
            /* printf("\n\nJOGADAS POSSÍVEIS\n1) Comprar Carta (CC)\n2) Mover do Descarte para as bases (DB)\n3) Mover do descarte para o tableau (DT)\n4) Mover do tableau para as bases (TB)\n5) Mover das bases para o tableau (BT)\n6) Mover entre colunas do Tableau (TT)\n7) Sair\nDigite o numero de acordo com a operacao desejada: ");
            scanf("%d", &jogada);

            switch (jogada){
            case 1:
                Comprar_Carta(&mesa);
                break;
            case 2:
                Mover_Descarte_Base(&mesa);
                break;
            case 3:
                printf("Digite o numero do tableau para o qual a carta será movida:\n");
                scanf("%d", &num_tableau);
                Mover_Descarte_Tableau(&mesa, num_tableau);
                break;
            case 4:
                printf("Digite o numero do tableau de onde a carta será movida:\n");
                scanf("%d", &num_tableau);
                Mover_Tableau_Base(&mesa, num_tableau);
                break;
            case 5:
                printf("Digite o numero da base de onde a carta será movida:\n");
                scanf("%d", &num_base);
                printf("Digite o numero do tableau para o qual a carta será movida:\n");
                scanf("%d", &num_tableau);
                Mover_Bases_Tableau(&mesa, num_base, num_tableau);
                break;
            case 6:
                printf("Digite a quantidade de cartas que sera movida:");
                scanf("%d", &qtd);
                printf("Digite o numero do tableau para o qual a carta será movida:\n");
                scanf("%d", &num_tableau_chegada);
                printf("Digite o numero do tableau de onde a carta será movida:\n");
                scanf("%d", &num_tableau_saida);
                Mover_no_Tableau(&mesa, qtd, num_tableau_chegada, num_tableau_saida);
                break;
            case 7:
                system("clear");
                printf("Jogo finalizado! :(");
                continua_jogo = False;
                break;
            default:
                printf("Opção inválida! Tente novamente!\n");
                break;
            }
        }
        system("clear");
        if(Verificar_Vitoria(&mesa)){
            printf("Parabens, %s! Voce venceu ;)", nome_jogador);
        }
    }
*/  
    

    //Lista_de_Cartas lista;
    //Inicializar_Lista_Vazia(&lista);


    return 0;
}
