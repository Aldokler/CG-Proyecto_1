#include "Constantes.h"

double x_min_universal = 0;
double x_max_universal = 28.41;
double y_min_universal = 0;
double y_max_universal = 26.8;

int** declararMatriz(int a, int b){
    int i, j;
    int** matriz;

    matriz = (int**)malloc(a*sizeof(int*));
    for (i = 0; i < a; i++){
        matriz[i] = (int*)malloc(b*sizeof(int));
        for (j = 0; j < b; j++){
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

void print_matrix (int** matrix,int i, int j){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d, ",matrix[i][j]);
        }
        printf("\n");
    }
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

double** declararMatrizD(int a, int b){
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

double** multiplicarD(double** matriz1, double** matriz2, int len_row_1, int len_col_2, int len_col_1) {
    double** matrix = declararMatrizD(len_row_1,len_col_2);

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
