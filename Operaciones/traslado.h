#ifndef CONSTANTE_H
#define CONSTANTE_H
#include "../Constantes.h"
#endif

double ** matriz_T;

void create_T_Matrix(){
    matriz_T = declararMatrizD(3,3);
    
    matriz_T[0][0] = 1;
    matriz_T[1][1] = 1;
    matriz_T[2][2] = 1;
}

double** trasladar(int d_x, int d_y,double** matriz_XY){
    matriz_T[0][2] = d_x;
    matriz_T[1][2] = d_y;

    return multiplicarD(matriz_T,matriz_XY,3,1,3);
}

void T_puntos(PIX* apex_list, int n,int d_x, int d_y){
    double** matriz_final = declararMatrizD (3,1);
    matriz_final[2][0] = 1;

    for (int i = 0; i < n; i++){
        matriz_final[0][0] = apex_list[i].x;
        matriz_final[1][0] = apex_list[i].y;
        matriz_final = trasladar(d_x, d_y, matriz_final);
        apex_list[i].x = round(matriz_final[0][0]);
        apex_list[i].y = round(matriz_final[1][0]);
    }  
    free(matriz_final);
}

