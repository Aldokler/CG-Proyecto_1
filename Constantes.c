#include "Constantes.h"

double** declararMatriz(int a, int b){
    int i, j;
    double** matriz;

    matriz = (double**)malloc(a*sizeof(double*));
    for (i = 0; i < a; i++){
        matriz[i] = (double*)malloc(b*sizeof(double));
        for (j = 0; j < b; j++){
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

void print_matrix (double** matrix,int i, int j){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%f, ",matrix[i][j]);
        }
        printf("\n");
    }
}

double** multiplicar(double** matriz1, double** matriz2, int len_row_1, int len_col_2, int len_col_1) {
    double** matrix = declararMatriz(len_row_1,len_col_2);

    double suma;

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