#ifndef CONSTANTE_H
#define CONSTANTE_H
#include "../Constantes.h"
#endif

double ** matriz_T_D;
int ** matriz_T;

void create_T_Matrix();

double** trasladarD(int d_x, int d_y,double** matriz_XY);
int** trasladar(int d_x, int d_y,int** matriz_XY);

void T_puntos(PIX* apex_list, int n,int d_x, int d_y);
void T_puntos_D(PIX* apex_list, int n,int d_x, int d_y);