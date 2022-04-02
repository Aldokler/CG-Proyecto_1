#include "Constantes.h"

int** declararMatriz(int a, int b){
    int i, j, **matriz;

    matriz = (int**)malloc(a*sizeof(int*));
    for (i = 0; i < a; i++){
        matriz[i] = (int*)malloc(b*sizeof(int));
        for (j = 0; j < b; j++){
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

int** multiplicar(int** matriz1, int** matriz2, int len_row_1, int len_col_2, int len_col_1) {
    int** matrix = declararMatriz(len_row_1,len_col_2);

    int suma;

    for (int col = 0; col < len_col_2; col++) {
        for (int row = 0; row < len_row_1; row++){
            suma = 0;
            for (int inner = 0; inner < len_col_1; inner++){
                suma = suma +  matriz1[row][inner] * matriz2[inner][col];
            }
            matrix[row][col] = suma;
        }
    }

    return matrix;
}