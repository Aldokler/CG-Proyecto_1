#include "pan.h"
#include "traslado.h"

void P_puntos(double d_x, double d_y){
    double** matriz_min = declararMatrizD (3,1);
    double** matriz_max = declararMatrizD (3,1);
    
    matriz_min[0][0] = x_min_universal;
    matriz_min[1][0] = y_min_universal;
    matriz_min[2][0] = 1;

    matriz_max[0][0] = x_max_universal;
    matriz_max[1][0] = y_max_universal;
    matriz_max[2][0] = 1;
    matriz_min = trasladarD(d_x, d_y, matriz_min);
    matriz_max = trasladarD(d_x, d_y, matriz_max);
    x_min_universal = matriz_min[0][0];
    x_max_universal = matriz_max[0][0];
    y_min_universal = matriz_min[1][0];
    y_max_universal = matriz_max[1][0];
}
