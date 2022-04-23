#include <malloc.h>
#include <math.h>

#define H_SIZE 600
#define V_SIZE 600
#define PI 3.141592653589793

typedef struct {
  int x;
  int y;
} PIX;

double** declararMatriz(int a, int b);

void print_matrix (double** matrix,int i, int j);

double** multiplicar(double** matriz1, double** matriz2, int len_row_1, int len_col_2, int len_col_1);