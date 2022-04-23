#include "zoom.h"

void create_Z_Matrix(){
    matriz_Z = declararMatriz(3,3);
    
    matriz_Z[2][2] = 1;
}

int** zoom(int z, int** matriz_XY){
    int x_c = (x_min_universal + x_max_universal)/2;
    int y_c = (y_min_universal + y_max_universal)/2;
    matriz_Z[0][0] = z;
    matriz_Z[0][2] = x_c - x_c*z;
    matriz_Z[1][1] = z;
    matriz_Z[1][2] = y_c - y_c*z;


    return multiplicar(matriz_Z,matriz_XY,3,1,3);
}

void Z_puntos(int z){
    int** matriz_min = declararMatriz (3,1);
    int** matriz_max = declararMatriz (3,1);
    
    matriz_min[0][0] = x_min_universal;
    matriz_min[1][0] = y_min_universal;
    matriz_min[2][0] = 1;

    matriz_max[0][0] = x_max_universal;
    matriz_max[1][0] = y_max_universal;
    matriz_max[2][0] = 1;
    matriz_min = zoom(z, matriz_min);
    matriz_max = zoom(z, matriz_max);
    x_min_universal = matriz_min[0][0];
    x_max_universal = matriz_max[0][0];
    y_min_universal = matriz_min[1][0];
    y_max_universal = matriz_max[1][0];
}
