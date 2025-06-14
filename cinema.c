#include <stdio.h>  
#include <string.h>
#include <stdlib.h>

/*Definindo uma struct e criando ela*/
struct sessao  
{  
    char sala[50];  
    char filme[50];  
    int cadeirasAtras[5][7];
    int cadeirasFrente[3][5];
    int capacidade;
    int disponivel;
    float precoNormal;
    float precoVIP;
} sessao;

/*Função para exibir layout das cadeiras do cinema*/
void ExibirLayout() {
    int i, j;

    printf("Sala: %s\n", sessao.sala);    
    printf("Capacidade: %d\n", sessao.capacidade);
    printf("Cadeiras disponiveis: %d\n\n", sessao.disponivel);
    printf("       1    2    3    4    5    6    7\n");

    /*Desenhando a matriz das cadeiras de tras*/
    for (i = 0; i < 5; i++) {
        printf("  %c  ", 'A' + i);
        for (j = 0; j < 7; j++) {
            if (sessao.cadeirasAtras[i][j] == 0) {  
                printf(" |0| ");
            } else {  
                printf(" |X| ");
            }  
        }
        printf("\n");
    }  

    /*Desenhando a matriz das cadeiras da frente*/
    for (i = 0; i < 3; i++) {
        printf("  %c      ", 'F' + i);
        for (j = 0; j < 5; j++) {  
            if (sessao.cadeirasFrente[i][j] == 0) {  
                printf("  |0|");
            } else {
                printf("  |X|");
            }
        }
        printf("      VIP\n");
    }

    printf("\n\n\n\n----------------------------------------------\n|                   TELA                     |\n----------------------------------------------\n");
}

/*Função para criar sala de acordo com o nome do filme e sala*/
void CriarSalas(char sala[], char filme[], float precoNormal, float precoVIP){
    int i, j;   
    char r;

    strcpy(sessao.sala, sala);   
    strcpy(sessao.filme, filme);
    sessao.precoNormal = precoNormal;
    sessao.precoVIP = precoVIP;

    /*Defindo a matriz das cadeiras de tras como 0*/
    for (i = 0; i < 5; i++) {   
        for (j = 0; j < 7; j++) {   
            sessao.cadeirasAtras[i][j] = 0;
        }  
    }  
    /*Defindo a matriz das cadeiras da frente como 0*/
    for (i = 0; i < 3; i++) {   
        for (j = 0; j < 5; j++) {   
            sessao.cadeirasFrente[i][j] = 0;
        }  
    }  
    /*Calculando as cadeiras disponiveis e a capacidade*/
    sessao.disponivel = (5 * 7) + (3 * 5);
    sessao.capacidade = sessao.disponivel;

    system("cls");
    printf("           %s            \n", sessao.filme);
    ExibirLayout(); 

    /*Switch case para reserva de assento*/
    while (r != 'N' && r != 'S') {
        printf("Deseja reservar um assento? (S/N): ");
        scanf(" %c", &r); 

        switch (r) {
            case 'S':
                Reserva();
                break;

            case 'N':
                printf("Voce escolheu Nao. Saindo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }
}

/*Função para a funcionalidade de reserva do cinema*/
void Reserva(){
    char assento[3];
    int linha, coluna, tipo;
    float preco;
    char continuar;

    printf("Qual assento gostaria de reservar? exemplo(A5): \n");
    scanf("%s", assento);

    /*Tranformando os vaolores inbutidos pelo usuário para os valores da matriz. Exemplo (A2 -> [1][2])*/
    linha = assento[0] - 'A'; 
    coluna = atoi(&assento[1]) - 1; 


    /*Definindo os assentos VIPS e normais e os que não existe*/
    if (linha >= 0 && linha < 5 && coluna >= 0 && coluna < 7) {
        tipo = 0; 
        preco = sessao.precoNormal;
    } else if (linha >= 5 && linha < 8 && coluna >= 0 && coluna < 6) {
        tipo = 1;
        linha -= 5;
        coluna -= 1;
        preco = sessao.precoVIP;
    } else {
        printf("Assento invalido!\n");
        return;
    }

    /*Verificando se o assento está reservado, se não, o programa faz a reserva e defini o valor do assento como 1*/
    if (tipo == 0) {
        if (sessao.cadeirasAtras[linha][coluna] == 1) {
            printf("Esse assento já está reservado!\n");
        } else {
            sessao.cadeirasAtras[linha][coluna] = 1; 
            sessao.disponivel--;
            printf("Assento %s reservado com sucesso!\n", assento);
            printf("Preco: R$%.2f\n", preco);
        }
    } else { 
        if (sessao.cadeirasFrente[linha][coluna] == 1) {
            printf("Esse assento ja esta reservado!\n");
        } else {
            sessao.cadeirasFrente[linha][coluna] = 1;
            sessao.disponivel--;
            printf("Assento %s reservado com sucesso!\n", assento);
            printf("Preco: R$%.2f\n", preco);
        }
    }

    ExibirLayout();
    /*Switch case para perguntar se o usuário quer fazer outra reserva*/
    while (continuar != 'N') {
        printf("Deseja fazer outra reserva? (S/N): ");
        scanf(" %c", &continuar);

        if (continuar == 'S') {
            Reserva();
            return;
        } else if (continuar == 'N') {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
}

/*Função para as escolhas do menu*/
void CaseMenu(){
    int i = 0;

    while (i != 1 && i != 2) {
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
    }
}

/*Função para as escolhas da parte de sessoes*/
void CaseSessoes(){
    int i = 0;
    system("cls");
    printf("----------------------------------------------\n|             CineMais - Sessoes             |\n----------------------------------------------\n");
    printf("1 - Coringa: Delirio a Dois\nSala: A1\n\n");
    printf("2 - Venom: A ultima Rodada\nSala: A2\n\n");
    printf("3 - Sorria 2\nSala: B1\n\n");

    while (i != 1 && i != 2 && i != 3) {
        printf("Escolha uma opcao: ");
        scanf("%d", &i);

        switch (i) {
        case 1:
            CriarSalas("A1", "Coringa: Delirio a Dois", 22.0, 40.0);
            break;

        case 2:
            CriarSalas("A2", "Venom: A ultima Rodada", 22.0, 40.0);
            break;

        case 3:
            CriarSalas("B1", "Sorria 2", 22.0, 40.0);
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }
    }
}

/*Sistema Principal*/
int main() {
    system("cls");
    printf("----------------------------------------------\n|              CineMais - Menu               |\n----------------------------------------------\n");
    printf("1 - Sessoes\n2 - Sair\n");
    CaseMenu();

    return 0; 
}
