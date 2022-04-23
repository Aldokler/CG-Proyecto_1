#include "pan.h"
#include "traslado.h"

void P_puntos(int d_x, int d_y){
    int** matriz_min = declararMatriz (3,1);
    int** matriz_max = declararMatriz (3,1);
    
    matriz_min[0][0] = x_min_universal;
    matriz_min[1][0] = y_min_universal;
    matriz_min[2][0] = 1;

    matriz_max[0][0] = x_max_universal;
    matriz_max[1][0] = y_max_universal;
    matriz_max[2][0] = 1;
    matriz_min = trasladar(d_x, d_y, matriz_min);
    matriz_max = trasladar(d_x, d_y, matriz_max);
    x_min_universal = matriz_min[0][0];
    x_max_universal = matriz_max[0][0];
    y_min_universal = matriz_min[1][0];
    y_max_universal = matriz_max[1][0];
}
