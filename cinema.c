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
    float precoNormal;
    float precoVIP;
} sessao;


void ExibirLayout() {
    int i, j;

    printf("Sala: %s\n", sessao.sala);    
    printf("Capacidade: %d\n", sessao.capacidade);
    printf("Cadeiras disponiveis: %d\n\n", sessao.disponivel);
    printf("       1    2    3    4    5    6    7\n");

    // Exibir cadeiras da parte traseira
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

    // Exibir cadeiras da parte frontal (VIP)
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

void CriarSalas(char sala[], char filme[], float precoNormal, float precoVIP){
    int i, j;   
    char r;

    strcpy(sessao.sala, sala);   
    strcpy(sessao.filme, filme);
    sessao.precoNormal = precoNormal;
    sessao.precoVIP = precoVIP;

    // Inicializa todas as cadeiras como disponíveis (0)
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
    
    sessao.disponivel = (5 * 7) + (3 * 5);
    sessao.capacidade = sessao.disponivel;

    system("cls");
    printf("           %s            \n", sessao.filme);
    ExibirLayout(); // Exibe o layout inicial

    do {
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
    } while (r != 'N' && r != 'S');
}

void Reserva(){
    char assento[3];
    int linha, coluna, tipo;
    float preco;

    printf("Qual assento gostaria de reservar? exemplo(A5): \n");
    scanf("%s", assento);

    // Conversão da entrada do usuário para índices de matriz
    linha = assento[0] - 'A'; // 'A' -> 0, 'B' -> 1, etc.
    coluna = atoi(&assento[1]) - 1; // '1' -> 0, '2' -> 1, etc.

    // Verifica se o assento está na parte traseira ou da frente
    if (linha >= 0 && linha < 5 && coluna >= 0 && coluna < 7) {
        tipo = 0; // Cadeiras traseiras
        preco = sessao.precoNormal;
    } else if (linha >= 5 && linha < 8 && coluna >= 0 && coluna < 5) {
        tipo = 1; // Cadeiras da frente
        linha -= 5; // Ajustando a linha para a matriz de cadeiras da frente
        coluna -= 1;
        preco = sessao.precoVIP;
    } else {
        printf("Assento invalido!\n");
        return;
    }

    // Verifica se o assento já está reservado
    if (tipo == 0) { // Cadeiras traseiras
        if (sessao.cadeirasAtras[linha][coluna] == 1) {
            printf("Esse assento já está reservado!\n");
        } else {
            sessao.cadeirasAtras[linha][coluna] = 1; // Reservando assento
            sessao.disponivel--;
            printf("Assento %s reservado com sucesso!\n", assento);
            printf("Preco: R$%.2f\n", preco);
        }
    } else { // Cadeiras da frente
        if (sessao.cadeirasFrente[linha][coluna] == 1) {
            printf("Esse assento já está reservado!\n");
        } else {
            sessao.cadeirasFrente[linha][coluna] = 1; // Reservando assento
            sessao.disponivel--;
            printf("Assento %s reservado com sucesso!\n", assento);
            printf("Preco: R$%.2f\n", preco);
        }
    }

    ExibirLayout(); // Exibe o layout atualizado após a reserva

    // Pergunta ao usuário se deseja fazer outra reserva
    char continuar;
    do {
        printf("Deseja fazer outra reserva? (S/N): ");
        scanf(" %c", &continuar);

        if (continuar == 'S') {
            Reserva(); // Faz uma nova reserva
            return; // Retorna para evitar loop adicional
        } else if (continuar == 'N') {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (continuar != 'N');
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
    } while (i != 1 && i != 2 && i != 3);
}

int main() {
    system("cls");
    printf("----------------------------------------------\n|              CineMais - Menu               |\n----------------------------------------------\n");
    printf("1 - Sessoes\n2 - Sair\n");
    CaseMenu();

    return 0; 
}
