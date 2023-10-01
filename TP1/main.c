#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> // Biblioteca pra definir tempo de espera na execuçao do terminal.
#include "Mesa.h"

/*
    COPAS E OUROS - NAIPES VERMELHOS
    ESPADA E PAUS - NAIPES PRETOS
*/

int main() {
    int num_tableau, num_base, qtd, num_tableau_saida, num_tableau_chegada; //Será usado nos switchs cases
    int continua_jogo = True; //Será usado no while True
    
    Mesa mesa;
    Inicializar_Mesa(&mesa);
    int formato_jogo;
    char nome_jogador[30];

    printf("PACIENCIA\n");
    printf("Qual o nome do jogador(a)? ");
    scanf("%s", nome_jogador);
    system("clear"); //Limpando meu terminal após informar o nome do jogador
    
    printf("Bem-vindo(a), %s! :)\n", nome_jogador);
    printf("\nMENU:\n1) Modo Interativo\n2) Utilizando Arquivo\n");
    printf("\nCom base nos numeros do menu acima escolha o formato do jogo:\n");
    scanf("%d", &formato_jogo); //Escolhendo o formato do jogo
    sleep(1); //Demora um segundo para limpar o terminal
    system("clear"); //LImpa o terminal para iniciarmos o jogo somente com a mesa
    
    if(formato_jogo == 1){ //Jogo no modo intarativo

        Carregar_Baralho_Aleatorio(&mesa);
        int jogada;    
        Preparar_Tableau(&mesa);
        
        while(continua_jogo == True){ //Entra no looping para realizar as jogadas
 
            Exibir_Mesa(&mesa);
            printf("\n\n\tJOGADAS POSSÍVEIS\n1) Comprar Carta (CC)\n2) Mover do Descarte para as bases (DB)\n3) Mover do descarte para o tableau (DT)\n4) Mover do tableau para as bases (TB)\n5) Mover das bases para o tableau (BT)\n6) Mover entre colunas do Tableau (TT)\n7) Sair\nDigite o numero de acordo com a operacao desejada: ");
            //Acima temos o Menu de Jogadas, que sempre estará disponível para o usuário
            scanf("%d", &jogada);

            switch (jogada){ //De acordo com escolha do usuário uma função será execultada (os números da função estão no menu)
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
                    sleep(1); //Demora um segundo para limpar o terminal e exibir a mensagem abaixo
                    system("clear");
                    printf("Não nos deixe, %s!!\n", nome_jogador);
                    sleep(2); //Deixa o usuario visualizar a mensagem por alguns segundos
                    continua_jogo = False; //Atualiza a variavel responsável pela saida/permanência no looping 
                    break;
                default:
                    printf("Opção inválida! Tente novamente!\n");
                    break;
            }
            sleep(1);
            system("clear"); //Limpa o terminal a cada jogada execultada
            
            if(Verificar_Vitoria(&mesa)){ 
                printf("Parabens, %s! Voce venceu ;)", nome_jogador);//Se o jagador vencer, exibe a mensagem
                continua_jogo = False; //Atualiza a variavel responsável pela saida/permanência no looping 
            }
            
        }
        
        
    } else { //Entra no modo arquivo
        
        printf("PACIENCIA MODO ARQUIVO\n");
        
        FILE *arq; //Ponteriro para o meu arquivo

        char caminho_arquivo[100];
        printf("Digite o caminho do arquivo: \n"); //O arquivo a ser usado é definido pelo usuário
        scanf("%s", caminho_arquivo);

        arq = fopen(caminho_arquivo, "r"); //Abre o arquivo para leitura        
        
        if (arq == NULL) { //Verifica se ocorreu tudo bem na abertura
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
        
        //Preparando meu jogo
        Inicializar_Baralho_Arquivo(&mesa, arq);
        Preparar_Tableau_Arquivo(&mesa);
        Exibir_Mesa(&mesa);

        char jogada[3];
        
        while (continua_jogo == True){ //Entra no looping
            
            fscanf(arq, "%s", jogada); //Pegando minha jogada

            //Os proximos if e else/if verificam qual foi a jogada escolhida
            if (strcmp(jogada, "TB") == 0){ 
                fscanf(arq, "%d", &num_tableau);
                Mover_Tableau_Base(&mesa, num_tableau);
            }
            else if (strcmp(jogada, "CC") == 0) {
                Comprar_Carta(&mesa);
            }
            else if (strcmp(jogada, "DB") == 0){
                Mover_Descarte_Base(&mesa);
            }
            else if (strcmp(jogada, "TT") == 0){
                fscanf(arq, "%d %d %d", &qtd, &num_tableau_saida, &num_tableau_chegada);
                Mover_no_Tableau(&mesa, qtd, num_tableau_chegada, num_tableau_saida);
            }
            else if (strcmp(jogada, "DT") == 0){
                fscanf(arq, "%d", &num_tableau);
                Mover_Descarte_Tableau(&mesa, num_tableau);
            }
            else if (strcmp(jogada, "BT") == 0) {
                fscanf(arq, "%d %d", &num_base, &num_tableau);
                Mover_Bases_Tableau(&mesa, num_base+1, num_tableau);
            }
            else if (strcmp(jogada, "X" )== 0){ 
                continua_jogo = False; //Atualiza minha variável para sair do looping
            }

           

            int c;
            scanf("%d", &c);
            Exibir_Mesa(&mesa);
            if(continua_jogo == False){ //Verifica se meu arquivo já terminou
                break;
            }
            
        }

        //system("Clear"); //Limpo meu terminal para mostrar o resultado final da minha mesa
        Exibir_Mesa(&mesa);

        //Verifico se a condição de vitória foi atingida
        if(Verificar_Vitoria(&mesa)){
            printf("Parabens, %s! Voce venceu ;)", nome_jogador);
        } else {
            printf("Não foi dessa vez! :( Tente novamente!");
        }
        
    
        fclose(arq); // Fecha o arquivo
    }
    
    

    return 0;
}
