#include "MapaCostaRica.h"

COLOR **buffer;

PIX* puntosHeredia[LEN_HEREDIA];
PIX* puntosLimon[LEN_LIMON]; 
PIX* puntosCartago[LEN_CARTAGO]; 
PIX* puntosSanJose[LEN_SANJOSE]; 
PIX* puntosAlajuela[LEN_ALAJUELA]; 
PIX* puntosGuanacaste[LEN_GUANACASTE]; 
PIX* puntosPuntarenas[LEN_PUNTARENAS]; 
PIX* puntosPuntarenasB[LEN_PUNTARENASB]; 

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

void display (void)
{
  glClear (GL_COLOR_BUFFER_BIT);

  convert_utop(heredia, puntosHeredia, LEN_HEREDIA);
  convert_utop(limon, puntosLimon, LEN_LIMON);
  convert_utop(cartago, puntosCartago, LEN_CARTAGO);
  convert_utop(sanJose, puntosSanJose, LEN_SANJOSE);
  convert_utop(alajuela, puntosAlajuela, LEN_ALAJUELA);
  convert_utop(guanacaste, puntosGuanacaste, LEN_GUANACASTE);
  convert_utop(puntarenas, puntosPuntarenas, LEN_PUNTARENAS);
  convert_utop(puntarenasB, puntosPuntarenasB, LEN_PUNTARENASB);
  
  paint_pol(puntosHeredia, LEN_HEREDIA);
  paint_pol(puntosLimon, LEN_LIMON);
  paint_pol(puntosCartago, LEN_CARTAGO);
  paint_pol(puntosSanJose, LEN_SANJOSE);
  paint_pol(puntosAlajuela, LEN_ALAJUELA);
  paint_pol(puntosGuanacaste, LEN_GUANACASTE);
  paint_pol(puntosPuntarenas, LEN_PUNTARENAS);
  paint_pol(puntosPuntarenasB, LEN_PUNTARENASB);

  //glClear (GL_COLOR_BUFFER_BIT);
  /**
  rotateMap(-45);
  glClear (GL_COLOR_BUFFER_BIT);
  trasladeMap(0,-100);
  */
  glFlush();
}

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

void keyLector(unsigned char key, int x, int y){
  if (key == 27){
    exit(0);
  }
  if (key == 'r' || key == 'R'){
    display();
  }
  if (key == '0'){ //Mapa sin colorear
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1,1,1);
    paint_pol(puntosHeredia, LEN_HEREDIA);
    paint_pol(puntosLimon, LEN_LIMON);
    paint_pol(puntosCartago, LEN_CARTAGO);
    paint_pol(puntosSanJose, LEN_SANJOSE);
    paint_pol(puntosAlajuela, LEN_ALAJUELA);
    paint_pol(puntosGuanacaste, LEN_GUANACASTE);
    paint_pol(puntosPuntarenas, LEN_PUNTARENAS);
    paint_pol(puntosPuntarenasB, LEN_PUNTARENASB);
    glFlush();
  }
  if (key == '1'){
    glClear (GL_COLOR_BUFFER_BIT);
    //Mapa con relleno de color
    glFlush();
  }
  if (key == '2'){
    glClear (GL_COLOR_BUFFER_BIT);
    //Mapa con relleno de textura
    glFlush();
  }
}

void specialKeyLector(int key, int x, int y){
  int mod = glutGetModifiers(); // Flechitas del teclado para hacer el PAN
  /*
  GLUT_ACTIVE_SHIFT – Set if either you press the SHIFT key, or Caps Lock is on. Note that if they are both on then the constant is not set.
  GLUT_ACTIVE_CTRL – Set if you press the CTRL key.
  GLUT_ACTIVE_ALT – Set if you press the ALT key.
  */
  if (key == GLUT_KEY_LEFT){
    glClear (GL_COLOR_BUFFER_BIT);
    glFlush();
  }
  if (key == GLUT_KEY_RIGHT){
    glClear (GL_COLOR_BUFFER_BIT);
    glFlush();
  }
  if (key == GLUT_KEY_UP){
    glClear (GL_COLOR_BUFFER_BIT);
    glFlush();
  }
  if (key == GLUT_KEY_DOWN){
    glClear (GL_COLOR_BUFFER_BIT);
    glFlush();
  }
}

void mouseLector(int button, int state, int x, int y){
  switch(button){
    case 3: //acercar - zoom in - hacer la ruedita del mouse para arriba
      glClear (GL_COLOR_BUFFER_BIT);
      glFlush();
      break;
    case 4: //alejar - zoom out - hacer la ruedita del mouse para abajo
      glClear (GL_COLOR_BUFFER_BIT);
      glFlush();
      break;
  }
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

  glColor3f (1,1,1);
  glutDisplayFunc(display);

  glutKeyboardFunc(keyLector);
  glutSpecialFunc(specialKeyLector);
  glutMouseFunc(mouseLector);

  // Crea las matrices de cada operacionn
  create_T_Matrix();
  create_R_Matrix();
 
  printf("Listo! \n");
  glutMainLoop();
}

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

void plot(int x,int y){
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

void paint_pol(PIX* apex_list, int n){
  PIX* list = clip_lines(apex_list, n);
  if (counter > 0){
    for (int i = 0; i < counter-1; i++){
      //printf("i = %d\n",i);
      bressenham_line(list[i].x, list[i].y, list[i+1].x, list[i+1].y);
    }
    bressenham_line(list[counter-1].x, list[counter-1].y, list[0].x, list[0].y);
  }
  free(list);
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

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

void trasladeMap(int d_x, int d_y){
  
  T_puntos(puntosHeredia, LEN_HEREDIA, d_x, d_y);
  paint_pol(puntosHeredia, LEN_HEREDIA);
  
  T_puntos(puntosLimon, LEN_LIMON, d_x, d_y);
  paint_pol(puntosLimon, LEN_LIMON);
  
  T_puntos(puntosCartago, LEN_CARTAGO, d_x, d_y);
  paint_pol(puntosCartago, LEN_CARTAGO);

  T_puntos(puntosSanJose, LEN_SANJOSE, d_x, d_y);
  paint_pol(puntosSanJose, LEN_SANJOSE);

  T_puntos(puntosAlajuela, LEN_ALAJUELA, d_x, d_y);
  paint_pol(puntosAlajuela, LEN_ALAJUELA);

  T_puntos(puntosGuanacaste, LEN_GUANACASTE, d_x, d_y );
  paint_pol(puntosGuanacaste, LEN_GUANACASTE);
  
  T_puntos(puntosPuntarenas, LEN_PUNTARENAS, d_x, d_y);
  paint_pol(puntosPuntarenas, LEN_PUNTARENAS);
  
  T_puntos(puntosPuntarenasB, LEN_PUNTARENASB, d_x, d_y);
  paint_pol(puntosPuntarenasB, LEN_PUNTARENASB);
}

void rotateMap(double grado) {

  R_puntos(puntosHeredia, LEN_HEREDIA, grado);
  paint_pol(puntosHeredia, LEN_HEREDIA);
  
  R_puntos(puntosLimon, LEN_LIMON, grado);
  paint_pol(puntosLimon, LEN_LIMON);
  
  R_puntos(puntosCartago, LEN_CARTAGO, grado);
  paint_pol(puntosCartago, LEN_CARTAGO);

  R_puntos(puntosSanJose, LEN_SANJOSE, grado);
  paint_pol(puntosSanJose, LEN_SANJOSE);

  R_puntos(puntosAlajuela, LEN_ALAJUELA, grado);
  paint_pol(puntosAlajuela, LEN_ALAJUELA);

  R_puntos(puntosGuanacaste, LEN_GUANACASTE, grado);
  paint_pol(puntosGuanacaste, LEN_GUANACASTE);

  R_puntos(puntosPuntarenas, LEN_PUNTARENAS, grado);
  paint_pol(puntosPuntarenas, LEN_PUNTARENAS);
  
  R_puntos(puntosPuntarenasB, LEN_PUNTARENASB, grado);
  paint_pol(puntosPuntarenasB, LEN_PUNTARENASB);
}
