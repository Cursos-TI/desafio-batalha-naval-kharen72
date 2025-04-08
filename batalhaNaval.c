#include <stdio.h>

#define LinhasLetras 10
#define LinhasAgua 10
#define Colunas 10

void aplicarHabilidade(int tabuleiro[LinhasAgua][Colunas], int habilidade[5][5], int origemX, int origemY) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = origemX + i - 2;
            int y = origemY + j - 2;
            if (x >= 0 && x < LinhasAgua && y >= 0 && y < Colunas) {
                if (habilidade[i][j] == 1 && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

int main (){

    printf("- Tabuleiro Batalha Naval -\n");
    printf("");
    char linha[LinhasLetras] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[LinhasAgua][Colunas] = {0};
    
    for (int i = 0; i < LinhasAgua; i++) { // Loop para imprimir a água, que é representado por 0
        for (int j = 0; j < Colunas; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //Primeiro navio
    tabuleiro [3][6] = 3; //G4
    tabuleiro [3][7] = 3; //H4
    tabuleiro [3][8] = 3; //I4

    //Segundo navio
    tabuleiro [2][1] = 3; //B2
    tabuleiro [3][1] = 3; //B3
    tabuleiro [4][1] = 3; //B4

    //Terceiro navio
    tabuleiro [5][7] = 3; //H5
    tabuleiro [6][8] = 3; //I6
    tabuleiro [7][9] = 3; //J7

    //Quarto navio
    tabuleiro [0][6] = 3; //G0
    tabuleiro [1][5] = 3; //F1
    tabuleiro [2][4] = 3; //E2

    // Matriz habilidade Cone
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Matriz habilidade Cruz
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    // Matriz habilidade Octaedro (losango)
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 1);     // Cone com origem em B1
    aplicarHabilidade(tabuleiro, cruz, 5, 5);     // Cruz com origem em F5
    aplicarHabilidade(tabuleiro, octaedro, 8, 2); // Octaedro com origem em C8

    printf("  ");
    for (int i = 0; i < LinhasLetras; i++) {  // Imprime a primeira linha que contém as letras
        printf("%c ", linha[i]);
    }
    printf("\n");

    for (int i = 0; i < LinhasAgua; i++) { // Imprime os números
        printf("%d ", i);
        for (int j = 0; j < Colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}