#ifndef CONSTANTE_H
#define CONSTANTE_H
#include "../Constantes.h"
#endif

int ** matriz_T;

void create_T_Matrix();

int** trasladar(int d_x, int d_y,int** matriz_XY);

void T_puntos(PIX* apex_list, int n,int d_x, int d_y);
