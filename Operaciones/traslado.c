#include "traslado.h"

void create_T_Matrix(){
    matriz_T = declararMatriz(3,3);
    matriz_T_D = declararMatrizD(3,3);
    matriz_T[0][0] = 1;
    matriz_T[1][1] = 1;
    matriz_T[2][2] = 1;
    matriz_T_D[0][0] = 1;
    matriz_T_D[1][1] = 1;
    matriz_T_D[2][2] = 1;
}

double** trasladarD(double d_x, double d_y,double** matriz_XY){
    matriz_T_D[0][2] = d_x;
    matriz_T_D[1][2] = d_y;

    return multiplicarD(matriz_T_D,matriz_XY,3,1,3);
}

int** trasladar(int d_x, int d_y, int** matriz_XY){
    matriz_T[0][2] = d_x;
    matriz_T[1][2] = d_y;

    return multiplicar(matriz_T,matriz_XY,3,1,3);
}

void T_puntos(PIX* apex_list, int n,int d_x, int d_y){
    int** matriz_final = declararMatriz (3,1);
    matriz_final[2][0] = 1;

    for (int i = 0; i < n; i++){
        matriz_final[0][0] = apex_list[i].x;
        matriz_final[1][0] = apex_list[i].y;
        matriz_final = trasladar(d_x, d_y, matriz_final);
        apex_list[i].x = matriz_final[0][0];
        apex_list[i].y = matriz_final[1][0];
    }  
    free(matriz_final);
}

void T_puntos_D(PIX* apex_list, int n,double d_x, double d_y){
    double** matriz_final = declararMatrizD (3,1);
    matriz_final[2][0] = 1;

    for (int i = 0; i < n; i++){
        matriz_final[0][0] = apex_list[i].x;
        matriz_final[1][0] = apex_list[i].y;
        matriz_final = trasladarD(d_x, d_y, matriz_final);
        apex_list[i].x = round(matriz_final[0][0]);
        apex_list[i].y = round(matriz_final[1][0]);
    }  
    free(matriz_final);
}
