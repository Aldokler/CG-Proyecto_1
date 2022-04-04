#include "MapaCostaRica.h"

#define H_SIZE 600
#define V_SIZE 600

COLOR **buffer;

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

void display (void)
{
  glClear (GL_COLOR_BUFFER_BIT);

  PIX* puntosHeredia = malloc(LEN_HEREDIA * sizeof(PIX));
  convert_utop(heredia, puntosHeredia, LEN_HEREDIA);
  paint_pol(puntosHeredia, LEN_HEREDIA);

  PIX* puntosLimon = malloc(LEN_LIMON * sizeof(PIX)); 
  convert_utop(limon, puntosLimon, LEN_LIMON);
  paint_pol(puntosLimon, LEN_LIMON);

  PIX* puntosCartago = malloc(LEN_CARTAGO * sizeof(PIX)); 
  convert_utop(cartago, puntosCartago, LEN_CARTAGO);
  paint_pol(puntosCartago, LEN_CARTAGO);

  PIX* puntosSanJose = malloc(LEN_SANJOSE * sizeof(PIX)); 
  convert_utop(sanJose, puntosSanJose, LEN_SANJOSE);
  paint_pol(puntosSanJose, LEN_SANJOSE);

  PIX* puntosAlajuela = malloc(LEN_ALAJUELA * sizeof(PIX)); 
  convert_utop(alajuela, puntosAlajuela, LEN_ALAJUELA);
  paint_pol(puntosAlajuela, LEN_ALAJUELA);

  PIX* puntosGuanacaste = malloc(LEN_GUANACASTE * sizeof(PIX)); 
  convert_utop(guanacaste, puntosGuanacaste, LEN_GUANACASTE);
  paint_pol(puntosGuanacaste, LEN_GUANACASTE);
  
  /*glClear (GL_COLOR_BUFFER_BIT);

  // Traslado
  T_puntos(puntosHeredia, LEN_HEREDIA, -100, 10);
  paint_pol(puntosHeredia, LEN_HEREDIA);
  T_puntos(puntosLimon, LEN_LIMON, -100, 10);
  paint_pol(puntosLimon, LEN_LIMON);*/

  glFlush();
}

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

int main(int argc, char** argv) 
{
  int i, j;

  buffer = (COLOR **)malloc(H_SIZE * sizeof(COLOR*));
  for (i = 0; i < H_SIZE; i++) 
      {
       buffer[i] = (COLOR *)malloc(V_SIZE * sizeof(COLOR));
      }

  for (i = 0; i < H_SIZE; i++) 
      {
       for (j = 0; j < V_SIZE; j++) 
           {
            buffer[i][j].r = 0;
            buffer[i][j].g = 0;
            buffer[i][j].b = 0;
           }
      }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(H_SIZE,V_SIZE);
  glutCreateWindow("Una linea");
  glClear(GL_COLOR_BUFFER_BIT); 
  gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);

  glutDisplayFunc(display);

  // Crea las matrices de cada operacionn
  create_T_Matrix();
 
  printf("Listo! \n");
  glutMainLoop();
}

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

void plot(int x,int y){
  COLOR color;
  buffer[x][y].r = 255;
  buffer[x][y].g = 255;
  buffer[x][y].b = 255;
  glColor3f (buffer[x][y].r,buffer[x][y].g,buffer[x][y].b);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

void paint_pol(PIX* apex_list, int n){
  for (int i = 0; i < n-1; i++){
    bressenham_line(apex_list[i].x, apex_list[i].y, apex_list[i+1].x, apex_list[i+1].y);
  }
  bressenham_line(apex_list[n-1].x, apex_list[n-1].y, apex_list[0].x, apex_list[0].y);
}

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

void convert_utop(UPOINT* apex_list[], PIX* points_list, int n){
  int x,y;
  for (int i = 0; i < n; i++){
    x = trunc((apex_list[i]->x*H_SIZE)/len_x_universal);
    y = trunc((apex_list[i]->y*V_SIZE)/len_y_universal);
    //printf("%d, %d \n", x, y);
    points_list[i].x = x; 
    points_list[i].y = y;
  }
}

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

void bressenham_line(int x0, int y0, int x1, int y1){
  int Delta_E, Delta_NE, Delta_N, Delta_NO, x, xAbs, d;
  int Delta_O, Delta_SO, Delta_S, Delta_SE, y, yAbs;

  x = x0; y = y0;
  plot(x, y);

  xAbs = abs(x1 - x0);
  yAbs = abs(y1 - y0);
  
  if (x0<=x1){
    if (y0<=y1){
      Delta_NE  =  2 * ((y1 - y0) - (x1 - x0)); //Valor para avanzar un pixel hacia arriba y uno a la derecha
      if (xAbs>=yAbs){ //octante 1
        d = 2*(y1-y0) - (x1-x0);
        Delta_E   =  2 * (y1 - y0);                 //Valor para avanzar un pixel a la derecha
        while (x < x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d < 0){
            x++;
            d = d + Delta_E;
          }
          else{
            x++; y++;
            d = d + Delta_NE;
          }
          plot(x,y);
        }
      }
      else{ //octante 2
        d = (y1-y0) - 2*(x1-x0);
        Delta_N  = -2 * (x1 - x0);             //Valor para avanzar un pixel hacia arriba
        while (y < y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d > 0){
            y++;
            d = d + Delta_N;
          }
          else{
            x++; y++;
            d = d + Delta_NE;
          }
          plot(x,y);
        }
      }
    }
    else{
      Delta_SE  =  2 * ((y1 - y0) + (x1 - x0)); //Valor para avanzar un pixel hacia abajo y uno a la derecha
      if (xAbs<=yAbs){ //octante 7
        d = (y1-y0) + 2*(x1-x0);
        Delta_S   =  2 * (x1 - x0);             //Valor para avanzar un pixel hacia abajo
        while (y > y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d < 0){
            y--;
            d = d + Delta_S;
          }
          else{
            x++; y--;
            d = d + Delta_SE;
          }
          plot(x,y);
        }
      }
      else{ //octante 8
        d = 2*(y1-y0) + (x1-x0);
        Delta_E   =  2 * (y1 - y0);                 //Valor para avanzar un pixel a la derecha
        while (x < x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            x++;
            d = d + Delta_E;
          }
          else{
            x++; y--;
            d = d + Delta_SE;
          }
          plot(x,y);
        }
      }
    }
  }
  else{
    if (y0<=y1){
      Delta_NO  = -2 * ((y1 - y0) + (x1 - x0)); //Valor para avanzar un pixel hacia arriba y uno a la izquierda
      if (yAbs>=xAbs){ //octante 3
        d = -1*(y1-y0) - 2*(x1-x0);
        Delta_N   = -2 * (x1 - x0);             //Valor para avanzar un pixel hacia arriba
        while (y < y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            y++;
            d = d + Delta_N;
          }
          else{
            x--; y++;
            d = d + Delta_NO;
          }
          plot(x,y);
        }
      }    
      else{ //octante 4
        d = -2* (y1 - y0) - (x1 - x0);
        Delta_O   = -2 * (y1 - y0);                 //Valor para avanzar un pixel a la izquierda
        while (x > x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d > 0){
            x--;
            d = d + Delta_O;
          }
          else{
            x--; y++;
            d = d + Delta_NO;
          }
          plot(x,y);
        }
      }
    }
    else{
      Delta_SO  = -2 * ((y1 - y0) - (x1 - x0)); //Valor para avanzar un pixel hacia abajo y uno a la izquierda
      if (xAbs>=yAbs){ //octante 5
        d = -2* (y1 - y0) + (x1 - x0);
        Delta_O   = -2 * (y1 - y0);                 //Valor para avanzar un pixel a la izquierda
        while (x > x1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d <= 0){
            x--;
            d = d + Delta_O;
          }
          else{
            x--; y--;
            d = d + Delta_SO;
          }
          plot(x,y);
        }
      }
      else{ //octante 6
        d = -1*(y1 - y0) + 2 * (x1 - x0);
        Delta_S   =  2 * (x1 - x0);               //Valor para avanzar un pixel hacia abajo
        while (y > y1){ //escoge cual pixel pintar de acuerdo al signo de "d" hasta terminar la linea
          if (d >= 0){
            y--;
            d = d + Delta_S;
          }
          else{
            x--; y--;
            d = d + Delta_SO;
          }
          plot(x,y);
        }
      }
    }
  }
};

