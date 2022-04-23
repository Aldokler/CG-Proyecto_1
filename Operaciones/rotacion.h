#ifndef CONSTANTE_H
#define CONSTANTE_H
#include "../Constantes.h"
#include "traslado.h"
#endif


double ** matriz_R;

double degree_to_radius(double degree) {
    return degree * (PI / 180);
}

void create_R_Matrix(){
    matriz_R = declararMatriz(3,3);
    
    matriz_R[0][0] = 1;
    matriz_R[1][1] = 1;
    matriz_R[2][2] = 1;
}

double** rotar(double alpha, double** matriz_XY){
    
    matriz_R[0][0] = cos(alpha);
    matriz_R[0][1] = -1*sin(alpha);
    matriz_R[1][0] = sin(alpha);
    matriz_R[1][1] = cos(alpha);

    return multiplicar(matriz_R,matriz_XY,3,1,3);
}

void R_puntos(PIX* apex_list, int n, double alpha){
    double** matriz_final = declararMatriz (3,1);
    double** matriz_temp1;
    double** matriz_temp2;

    matriz_final[2][0] = 1;

    for (int i = 0; i < n; i++){
        matriz_final[0][0] = apex_list[i].x;
        matriz_final[1][0] = apex_list[i].y;
        
        //printf("x_b= %f, y_b= %f\n", matriz_final[0][0], matriz_final[1][0]);
        matriz_temp1 = trasladar(-(H_SIZE/2), -(V_SIZE/2), matriz_final);
        //printf("x_1= %f, y_1= %f\n", matriz_temp1[0][0], matriz_temp1[1][0]);
        matriz_temp2 = rotar( degree_to_radius(alpha), matriz_temp1);
        //printf("x_2= %f, y_2= %f\n", matriz_temp2[0][0], matriz_temp2[1][0]);
        matriz_final = trasladar(H_SIZE/2, V_SIZE/2, matriz_temp2);
        //printf("x_new= %f, y_new= %f\n", matriz_final[0][0], matriz_final[1][0]);
        apex_list[i].x = round(matriz_final[0][0]);
        apex_list[i].y = round(matriz_final[1][0]);

    }
    //printf("---------------------\n");
    free(matriz_final);
}
