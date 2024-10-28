/*Simulação de Sistema de Bilheteria de Cinema. Crie um sistema para gerenciar a compra
de bilhetes de cinema. Cada sessão deve ter uma capacidade limitada, e o sistema deve
permitir que os usuários escolham assentos. Inclua a possibilidade de diferentes preços por
assento (VIP, normal). O estudante deve decidir como representar o layout do cinema, como
lidar com reservas conflitantes e como registrar as compras*/


#include <stdio.h>  
#include <string.h>
#include <stdlib.h>

struct sessao  
{  
    char sala[50];  
    char filme[50];  
    int cadeirasAtras[5][7];
    int cadeirasFrente[3][5];
    int capacidade;
    int disponivel;
}; 



void CriarSalas(char sala[], char filme[]){
    int i, j;   
    struct sessao sessao;

    strcpy(sessao.sala, sala);   
    strcpy(sessao.filme, filme);

    system("cls");
    printf("           %s            \n", sessao.filme);


    /*Definindo todos os valores das matrizes como 0 (todas cadeiras livres)*/
    for (i = 0; i < 5; i++) {   
        for (j = 0; j < 7; j++) {   
            sessao.cadeirasAtras[i][j] = 0;
        }  
    }  
    for (i = 0; i < 3; i++) {   
        for (j = 0; j < 5; j++) {   
            sessao.cadeirasFrente[i][j] = 0;
        }  
    }  
    
    sessao.disponivel = 0;
    sessao.capacidade = (5 * 7) + (3 * 5);
    /*Calculo das cadeiras normais disponiveis */
    for (i = 0; i < 5; i++) {   
        for (j = 0; j < 7; j++) {   
            if (sessao.cadeirasAtras[i][j] == 0){
                sessao.disponivel++;
            }
        }  

    }  
    /*Calculo das cadeiras VIPS disponiveis */
    for (i = 0; i < 3; i++) {   
        for (j = 0; j < 5; j++) {   
            if (sessao.cadeirasFrente[i][j] == 0){
                sessao.disponivel++;
            }
        }  
    }  
    printf("Sala: %s\n", sessao.sala);    
    printf("Capacidade: %d\n", sessao.capacidade);
    printf("Cadeiras disponiveis: %d\n\n", sessao.disponivel);
    printf("       1    2    3    4    5    6    7\n");

    /*Criação do layout da sala */
    for (i = 0; i < 5; i++) {
        if (i == 0) {
            printf("  A  ");
        } else if (i == 1) {
            printf("  B  ");
        } else if (i == 2) {
            printf("  C  ");
        } else if (i == 3) {
            printf("  D  ");
        } else if (i == 4) {
            printf("  E  ");
        }

        for (j = 0; j < 7; j++) {
            if (sessao.cadeirasAtras[i][j] == 0) {  
                printf(" |0| ");
            } else {  
                printf(" |X| ");
            }  
        }
        printf("\n");
    }  

    for (i = 0; i < 3; i++) {
        if (i == 0) {
            printf("  F      ");
        } else if (i == 1) {
            printf("  G      ");
        } else if (i == 2) {
            printf("  H      ");
        }
        for (j = 0; j < 5; j++) {  
            if (sessao.cadeirasFrente[i][j] == 0) {  
                if (j == 4) {  
                    printf("  |0|      VIP");  
                } else { 
                    printf("  |0|");
                }  
            } else {
                if (j == 4) {  
                    printf("  |X|      VIP");  
                } else { 
                    printf("  |X|");
                }  
            } 
        }
        printf("\n");
    }

    printf("\n\n\n\n----------------------------------------------\n|                   TELA                     |\n----------------------------------------------\n");

}

void CaseMenu(){
    int i = 0;
    do {
        printf("Escolha uma opcao: ");
        scanf("%d", &i);

        switch (i) {
        case 1:
            CaseSessoes();
            break;

        case 2:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }
    } while (i != 1 && i != 2);
}

void CaseSessoes(){
    int i = 0;
    system("cls");
    printf("----------------------------------------------\n|             CineMais - Sessoes             |\n----------------------------------------------\n");
    printf("1 - Coringa: Delirio a Dois\nSala: A1\n\n");
    printf("2 - Venom: A ultima Rodada\nSala: A2\n\n");
    printf("3 - Sorria 2\nSala: B1\n\n");
        do {
        printf("Escolha uma opcao: ");
        scanf("%d", &i);

        switch (i) {
        case 1:
            CriarSalas("A1", "Coringa: Delirio a Dois");
            break;

        case 2:
            CriarSalas("A2", "Venom: A ultima Rodada");
            break;

        case 3:
            CriarSalas("B1", "Sorria 2");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }
    } while (i != 1 && i != 2 && i != 3);
}



int main() {
    system("cls");
    printf("----------------------------------------------\n|              CineMais - Menu               |\n----------------------------------------------\n");
    printf("1 - Sessoes\n2 - Sair\n");
    CaseMenu();

    return 0; 
}