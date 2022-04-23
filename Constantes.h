#include <malloc.h>

#define H_SIZE 600
#define V_SIZE 600

typedef struct {
  int x;
  int y;
} PIX;

int** declararMatriz(int a, int b);

int** multiplicar(int** matriz1, int** matriz2, int len_row_1, int len_col_2, int len_col_1);