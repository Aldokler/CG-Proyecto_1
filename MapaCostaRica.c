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
int herediaInside[36000][2] ;
int limonInside[36000][2];
int cartagoInside[36000][2];
int sanjoseInside[36000][2];
int alajuelaInside[36000][2];
int guanacasteInside[36000][2];
int puntarenasInside[36000][2];
int herediaInsideLen=0;
int limonInsideLen=0;
int cartagoInsideLen=0;
int sanjoseInsideLen=0;
int alajuelaInsideLen=0;
int guanacasteInsideLen=0;
int puntarenasInsideLen=0;
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

  if (MODE_VALUE == 0){ //Mapa sin colorear
    glColor3f (1,1,1);
    paint_pol(puntosHeredia, LEN_HEREDIA);
    paint_pol(puntosLimon, LEN_LIMON);
    paint_pol(puntosCartago, LEN_CARTAGO);
    paint_pol(puntosSanJose, LEN_SANJOSE);
    paint_pol(puntosAlajuela, LEN_ALAJUELA);
    paint_pol(puntosGuanacaste, LEN_GUANACASTE);
    paint_pol(puntosPuntarenas, LEN_PUNTARENAS);
    paint_pol(puntosPuntarenasB, LEN_PUNTARENASB);
    MODE_VALUE = 0;
  } else if(MODE_VALUE == 1){
    paint(puntosHeredia, LEN_HEREDIA,puntosLimon,LEN_LIMON,puntosCartago,LEN_CARTAGO,puntosSanJose,LEN_SANJOSE,puntosAlajuela,LEN_ALAJUELA,puntosGuanacaste,LEN_GUANACASTE,puntosPuntarenas,LEN_PUNTARENAS,puntosPuntarenasB,LEN_PUNTARENASB);
    MODE_VALUE = 1;
  } else if (MODE_VALUE == 2){
    texture(puntosHeredia, LEN_HEREDIA,puntosLimon,LEN_LIMON,puntosCartago,LEN_CARTAGO,puntosSanJose,LEN_SANJOSE,puntosAlajuela,LEN_ALAJUELA,puntosGuanacaste,LEN_GUANACASTE,puntosPuntarenas,LEN_PUNTARENAS,puntosPuntarenasB,LEN_PUNTARENASB);
    MODE_VALUE = 2;
    
  }

  glFlush();
}

/*
#########################################################################################################################################
-----------------------------------------------------------------------------------------------------------------------------------------
#########################################################################################################################################
*/

void keyLector(unsigned char key, int x, int y){
  int mod = glutGetModifiers();
  if (key == 27){
    exit(0);
  }
  if (key == 'r' || key == 'R'){
    glColor3f (1,1,1);
    x_min_universal = 0;
    x_max_universal = 28.41;
    y_min_universal = 0;
    y_max_universal = 26.8;
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
    MODE_VALUE = 0;
    glFlush();
  }
  if (key == '1'){
    glClear (GL_COLOR_BUFFER_BIT);
    paint(puntosHeredia, LEN_HEREDIA,puntosLimon,LEN_LIMON,puntosCartago,LEN_CARTAGO,puntosSanJose,LEN_SANJOSE,puntosAlajuela,LEN_ALAJUELA,puntosGuanacaste,LEN_GUANACASTE,puntosPuntarenas,LEN_PUNTARENAS,puntosPuntarenasB,LEN_PUNTARENASB);
    MODE_VALUE = 1;
    glFlush();
  }
  if (key == '2'){
    glClear (GL_COLOR_BUFFER_BIT);
    texture(puntosHeredia, LEN_HEREDIA,puntosLimon,LEN_LIMON,puntosCartago,LEN_CARTAGO,puntosSanJose,LEN_SANJOSE,puntosAlajuela,LEN_ALAJUELA,puntosGuanacaste,LEN_GUANACASTE,puntosPuntarenas,LEN_PUNTARENAS,puntosPuntarenasB,LEN_PUNTARENASB);
    MODE_VALUE = 2;
    glFlush();
  }
  // Teclas para el traslado
  if (key == 'a' || key == 'A'){
    glClear (GL_COLOR_BUFFER_BIT);
    if (mod == GLUT_ACTIVE_SHIFT){
      trasladeMap(-trunc(TRASLADE_VALUE/2),0);   
    }
    else if (mod == GLUT_ACTIVE_ALT){
      trasladeMap(-TRASLADE_VALUE*2,0);   
    }
    else{
      trasladeMap(-TRASLADE_VALUE,0);      
    }
    glFlush();
  }
  if (key == 'd' || key == 'D'){
    glClear (GL_COLOR_BUFFER_BIT);
    if (mod == GLUT_ACTIVE_SHIFT){
      trasladeMap(trunc(TRASLADE_VALUE/2),0);
    }
    else if (mod == GLUT_ACTIVE_ALT){
      trasladeMap(TRASLADE_VALUE*2,0);
    }
    else{
      trasladeMap(TRASLADE_VALUE,0);
    }
    glFlush();
  }
  if (key == 'w' || key == 'W'){
    glClear (GL_COLOR_BUFFER_BIT);
    if (mod == GLUT_ACTIVE_SHIFT){
      trasladeMap(0,trunc(TRASLADE_VALUE/2));
    }
    else if (mod == GLUT_ACTIVE_ALT){
      trasladeMap(0,TRASLADE_VALUE*2);
    }
    else{
      trasladeMap(0,TRASLADE_VALUE);      
    }
    glFlush();
  }
  if (key == 's' || key == 'S'){
    glClear (GL_COLOR_BUFFER_BIT);
    if (mod == GLUT_ACTIVE_SHIFT){
      trasladeMap(0,-trunc(TRASLADE_VALUE/2)); 
    }
    else if (mod == GLUT_ACTIVE_ALT){
      trasladeMap(0,-TRASLADE_VALUE*2); 
    }
    else{
      trasladeMap(0,-TRASLADE_VALUE);      
    }
    glFlush();
  }

  //Teclas para rotaciones
  if (key == 'q' || key == 'Q'){
    glClear (GL_COLOR_BUFFER_BIT);
    if (mod == GLUT_ACTIVE_SHIFT){
      rotateMap(trunc(ROTATE_VALUE/2));
    }
    else if (mod == GLUT_ACTIVE_ALT){
      rotateMap(ROTATE_VALUE*2);
    }
    else{
      rotateMap(ROTATE_VALUE);      
    }
    glFlush();
  }
  if (key == 'e' || key == 'E'){
    glClear (GL_COLOR_BUFFER_BIT);
    if (mod == GLUT_ACTIVE_SHIFT){
      rotateMap(-trunc(ROTATE_VALUE/2));
    }
    else if (mod == GLUT_ACTIVE_ALT){
      rotateMap(-ROTATE_VALUE*2);
    }
    else{
      rotateMap(-ROTATE_VALUE);
    }
    glFlush();
  }

}

void specialKeyLector(int key, int x, int y){
  int mod = glutGetModifiers(); // Flechitas del teclado para hacer el PAN
  /*
  GLUT_ACTIVE_SHIFT – Set if either you press the SHIFT key, or Caps Lock is on. Note that if they are both on then the constant is not set.
  GLUT_ACTIVE_CTRL – Set if you press the CTRL key.
  GLUT_ACTIVE_ALT – Set if you press the ALT key.
  GLUT_ACTIVE_ALT|GLUT_ACTIVE_CTRL - Set if you press both the ALT and the CTRL key.
  */
  /**
  if (key == GLUT_KEY_LEFT){
    P_puntos(1, 0);
    glutPostRedisplay();
  }
  if (key == GLUT_KEY_RIGHT){
    P_puntos(-1, 0);
    glutPostRedisplay();
  }
  if (key == GLUT_KEY_UP){
    P_puntos(0, -1);
    glutPostRedisplay();
  }
  if (key == GLUT_KEY_DOWN){
    P_puntos(0, 1);
    glutPostRedisplay();
  }*/
}

void mouseLector(int button, int state, int x, int y){
  int mod = glutGetModifiers();
  switch(button){
    case 3: //acercar - zoom in - hacer la ruedita del mouse para arriba
      if (mod == GLUT_ACTIVE_SHIFT){
        Z_puntos(0.9);
      }
      else if (mod == GLUT_ACTIVE_ALT){
        Z_puntos(0.8);
      }
      else{
        Z_puntos(0.85);
      }
      glutPostRedisplay(); 
      break;
    case 4: //alejar - zoom out - hacer la ruedita del mouse para abajo
      if (mod == GLUT_ACTIVE_SHIFT){
        Z_puntos(1.15);
      }
      else if (mod == GLUT_ACTIVE_ALT){
        Z_puntos(1.25);
      }
      else{
        Z_puntos(1.2);
      }
      glutPostRedisplay(); 
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

  create_Z_Matrix();

  
  printf("Listo! \n");
  help();
  glutMainLoop();
}

void help(){
  printf(" ______________________________________________ \n");
  printf("| Comandos para el manejo del mapa             |\n");
  printf("| (W,A,S,D)               => Pan               |\n");
  printf("| (Q,E)                   => Rotacion          |\n");
  printf("| (Mouse Wheel)           => Zoom in, Zoom out |\n");
  printf("| R                       => Reiniciar         |\n");
  printf("| ESC                     => Cerrar            |\n");
  printf("|                                              |\n");
  printf("| SHIFT                    => Modo lento       |\n");
  printf("| ALT                     => Modo Rápido       |\n");
  printf("|______________________________________________|\n");

  printf(" ________________________\n");
  printf("| Modos del mapa         |\n");
  printf("| Blanco y Negro  => 0   |\n");
  printf("| Colores         => 1   |\n");
  printf("| Texturas        => 2   |\n");
  printf("|________________________|\n");

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
    x = trunc(H_SIZE*((apex_list[i]->x-x_min_universal)/(x_max_universal-x_min_universal)));
    y = trunc(V_SIZE*((apex_list[i]->y-y_min_universal)/(y_max_universal-y_min_universal)));
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
  T_puntos(puntosLimon, LEN_LIMON, d_x, d_y);
  T_puntos(puntosCartago, LEN_CARTAGO, d_x, d_y);
  T_puntos(puntosSanJose, LEN_SANJOSE, d_x, d_y);
  T_puntos(puntosAlajuela, LEN_ALAJUELA, d_x, d_y);
  T_puntos(puntosGuanacaste, LEN_GUANACASTE, d_x, d_y );
  T_puntos(puntosPuntarenas, LEN_PUNTARENAS, d_x, d_y);
  T_puntos(puntosPuntarenasB, LEN_PUNTARENASB, d_x, d_y);
  if (MODE_VALUE == 0){ // Sin colores
    paint_pol(puntosHeredia, LEN_HEREDIA);
    paint_pol(puntosLimon, LEN_LIMON);
    paint_pol(puntosCartago, LEN_CARTAGO);
    paint_pol(puntosSanJose, LEN_SANJOSE);
    paint_pol(puntosAlajuela, LEN_ALAJUELA);
    paint_pol(puntosGuanacaste, LEN_GUANACASTE);
    paint_pol(puntosPuntarenas, LEN_PUNTARENAS);
    paint_pol(puntosPuntarenasB, LEN_PUNTARENASB);
  } else if (MODE_VALUE == 1) { // Colores
    paint(puntosHeredia, LEN_HEREDIA,
          puntosLimon,LEN_LIMON,
          puntosCartago,LEN_CARTAGO,
          puntosSanJose,LEN_SANJOSE,
          puntosAlajuela,LEN_ALAJUELA,
          puntosGuanacaste,LEN_GUANACASTE,
          puntosPuntarenas,LEN_PUNTARENAS,
          puntosPuntarenasB,LEN_PUNTARENASB);
  } else if (MODE_VALUE == 2) { // Texturas
    texture(puntosHeredia, LEN_HEREDIA,
          puntosLimon,LEN_LIMON,
          puntosCartago,LEN_CARTAGO,
          puntosSanJose,LEN_SANJOSE,
          puntosAlajuela,LEN_ALAJUELA,
          puntosGuanacaste,LEN_GUANACASTE,
          puntosPuntarenas,LEN_PUNTARENAS,
          puntosPuntarenasB,LEN_PUNTARENASB);
  }
}

void rotateMap(double grado) {
  R_puntos(puntosHeredia, LEN_HEREDIA, grado);
  R_puntos(puntosLimon, LEN_LIMON, grado);
  R_puntos(puntosCartago, LEN_CARTAGO, grado);
  R_puntos(puntosSanJose, LEN_SANJOSE, grado);
  R_puntos(puntosAlajuela, LEN_ALAJUELA, grado);
  R_puntos(puntosGuanacaste, LEN_GUANACASTE, grado);
  R_puntos(puntosPuntarenas, LEN_PUNTARENAS, grado);
  R_puntos(puntosPuntarenasB, LEN_PUNTARENASB, grado);
  if (MODE_VALUE == 0){
    paint_pol(puntosHeredia, LEN_HEREDIA);
    paint_pol(puntosLimon, LEN_LIMON);
    paint_pol(puntosCartago, LEN_CARTAGO);
    paint_pol(puntosSanJose, LEN_SANJOSE);
    paint_pol(puntosAlajuela, LEN_ALAJUELA);
    paint_pol(puntosGuanacaste, LEN_GUANACASTE);
    paint_pol(puntosPuntarenas, LEN_PUNTARENAS);
    paint_pol(puntosPuntarenasB, LEN_PUNTARENASB);
  } else if (MODE_VALUE == 1) {
    paint(puntosHeredia, LEN_HEREDIA,
          puntosLimon,LEN_LIMON,
          puntosCartago,LEN_CARTAGO,
          puntosSanJose,LEN_SANJOSE,
          puntosAlajuela,LEN_ALAJUELA,
          puntosGuanacaste,LEN_GUANACASTE,
          puntosPuntarenas,LEN_PUNTARENAS,
          puntosPuntarenasB,LEN_PUNTARENASB);
  } else if (MODE_VALUE == 2) {
    texture(puntosHeredia, LEN_HEREDIA,
          puntosLimon,LEN_LIMON,
          puntosCartago,LEN_CARTAGO,
          puntosSanJose,LEN_SANJOSE,
          puntosAlajuela,LEN_ALAJUELA,
          puntosGuanacaste,LEN_GUANACASTE,
          puntosPuntarenas,LEN_PUNTARENAS,
          puntosPuntarenasB,LEN_PUNTARENASB);
  } 
}

void paint(PIX* P1, int n1,PIX* P2, int n2,PIX* P3, int n3,PIX* P4, int n4,PIX* P5, int n5,PIX* P6, int n6,PIX* P7, int n7,PIX* P8, int n8){
  //if(herediaInsideLen==0){
  herediaInsideLen = 0;
  limonInsideLen = 0;
  cartagoInsideLen = 0;
  sanjoseInsideLen = 0;
  alajuelaInsideLen = 0;
  guanacasteInsideLen = 0;
  puntarenasInsideLen = 0;

  PIX* list1 = clip_lines(P1, n1);
  n1 = counter;
  PIX* list2 = clip_lines(P2, n2);
  n2 = counter;
  PIX* list3 = clip_lines(P3, n3);
  n3 = counter;
  PIX* list4 = clip_lines(P4, n4);
  n4 = counter;
  PIX* list5 = clip_lines(P5, n5);
  n5 = counter;
  PIX* list6 = clip_lines(P6, n6);
  n6 = counter;
  PIX* list7 = clip_lines(P7, n7);
  n7 = counter;
  PIX* list8 = clip_lines(P8, n8);
  n8 = counter;
  for (int i = 0; i <600; i++)
  {
    for (int o = 0; o <600; o++)
  {
    if(pointInside(n1,list1,o,i)==1){
      glColor3f (1,1,1);
      plot(o,i);
      herediaInside[herediaInsideLen][0]=o;
      herediaInside[herediaInsideLen][1]=i;
      herediaInsideLen+=1;
    }
    else if(pointInside(n2,list2,o,i)==1){
      glColor3f (1,0,0);
      plot(o,i);
      limonInside[limonInsideLen][0]=o;
      limonInside[limonInsideLen][1]=i;
      limonInsideLen+=1;
    }
    else if(pointInside(n3,list3,o,i)==1){
      glColor3f (0,1,0);
      plot(o,i);
      cartagoInside[cartagoInsideLen][0]=o;
      cartagoInside[cartagoInsideLen][1]=i;
      cartagoInsideLen+=1;
    }
    else if(pointInside(n4,list4,o,i)==1){
      glColor3f (0,0,1);
      plot(o,i);
      sanjoseInside[sanjoseInsideLen][0]=o;
      sanjoseInside[sanjoseInsideLen][1]=i;
      sanjoseInsideLen+=1;
    }
    else if(pointInside(n5,list5,o,i)==1){
      glColor3f (0,1,1);
      plot(o,i);
      alajuelaInside[alajuelaInsideLen][0]=o;
      alajuelaInside[alajuelaInsideLen][1]=i;
      alajuelaInsideLen+=1;
    }
    else if(pointInside(n6,list6,o,i)==1){
      glColor3f (1,1,0);
      plot(o,i);
      guanacasteInside[guanacasteInsideLen][0]=o;
      guanacasteInside[guanacasteInsideLen][1]=i;
      guanacasteInsideLen+=1;
    }
    else if(pointInside(n7,list7,o,i)==1){
      glColor3f (1,0,1);
      plot(o,i);
      puntarenasInside[puntarenasInsideLen][0]=o;
      puntarenasInside[puntarenasInsideLen][1]=i;
      puntarenasInsideLen+=1;
    }
    else if(pointInside(n8,list8,o,i)==1){
      glColor3f (1,0,1);
      plot(o,i);
      puntarenasInside[puntarenasInsideLen][0]=o;
      puntarenasInside[puntarenasInsideLen][1]=i;
      puntarenasInsideLen+=1;
    }
    
  }
  }
  free(list1);
  free(list2);
  free(list3);
  free(list4);
  free(list5);
  free(list6);
  free(list7);
  free(list8);
/**}
else{
  glColor3f (1,1,1);
  for (int i = 0; i < herediaInsideLen; i++)
  {
    plot(herediaInside[i][0],herediaInside[i][1]);
  }
  glColor3f (0,1,1);
  for (int i = 0; i < alajuelaInsideLen; i++)
  {
    plot(alajuelaInside[i][0],alajuelaInside[i][1]);
  }
  glColor3f (1,0,1);
  for (int i = 0; i < cartagoInsideLen; i++)
  {
    plot(cartagoInside[i][0],cartagoInside[i][1]);
  }
  glColor3f (1,1,0);
  for (int i = 0; i < sanjoseInsideLen; i++)
  {
    plot(sanjoseInside[i][0],sanjoseInside[i][1]);
  }
  glColor3f (0,0,1);
  for (int i = 0; i < limonInsideLen; i++)
  {
    plot(limonInside[i][0],limonInside[i][1]);
  }
  glColor3f (1,0,0);
  for (int i = 0; i < guanacasteInsideLen; i++)
  {
    plot(guanacasteInside[i][0],guanacasteInside[i][1]);
  }
  glColor3f (1,0,0);
  for (int i = 0; i < puntarenasInsideLen; i++)
  {
    plot(puntarenasInside[i][0],puntarenasInside[i][1]);
  }
}*/

}

void texture(PIX* P1, int n1,PIX* P2, int n2,PIX* P3, int n3,PIX* P4, int n4,PIX* P5, int n5,PIX* P6, int n6,PIX* P7, int n7,PIX* P8, int n8){
  herediaInsideLen = 0;
  limonInsideLen = 0;
  cartagoInsideLen = 0;
  sanjoseInsideLen = 0;
  alajuelaInsideLen = 0;
  guanacasteInsideLen = 0;
  puntarenasInsideLen = 0;

  PIX* list1 = clip_lines(P1, n1);
  n1 = counter;
  PIX* list2 = clip_lines(P2, n2);
  n2 = counter;
  PIX* list3 = clip_lines(P3, n3);
  n3 = counter;
  PIX* list4 = clip_lines(P4, n4);
  n4 = counter;
  PIX* list5 = clip_lines(P5, n5);
  n5 = counter;
  PIX* list6 = clip_lines(P6, n6);
  n6 = counter;
  PIX* list7 = clip_lines(P7, n7);
  n7 = counter;
  PIX* list8 = clip_lines(P8, n8);
  n8 = counter;
  //if(herediaInsideLen==0){
  for (int i = 0; i <600; i++)
  {
    for (int o = 0; o <600; o++)
  {
    if(pointInside(n1,list1,o,i)==1){
      
      herediaInside[herediaInsideLen][0]=o;
      herediaInside[herediaInsideLen][1]=i;
      herediaInsideLen+=1;
    }
    else if(pointInside(n2,list2,o,i)==1){
      
      limonInside[limonInsideLen][0]=o;
      limonInside[limonInsideLen][1]=i;
      limonInsideLen+=1;
    }
    else if(pointInside(n3,list3,o,i)==1){
      
      cartagoInside[cartagoInsideLen][0]=o;
      cartagoInside[cartagoInsideLen][1]=i;
      cartagoInsideLen+=1;
    }
    else if(pointInside(n4,list4,o,i)==1){
      
      sanjoseInside[sanjoseInsideLen][0]=o;
      sanjoseInside[sanjoseInsideLen][1]=i;
      sanjoseInsideLen+=1;
    }
    else if(pointInside(n5,list5,o,i)==1){
      
      alajuelaInside[alajuelaInsideLen][0]=o;
      alajuelaInside[alajuelaInsideLen][1]=i;
      alajuelaInsideLen+=1;
    }
    else if(pointInside(n6,list6,o,i)==1){
      
      guanacasteInside[guanacasteInsideLen][0]=o;
      guanacasteInside[guanacasteInsideLen][1]=i;
      guanacasteInsideLen+=1;
    }
    else if(pointInside(n7,list7,o,i)==1){
      
      puntarenasInside[puntarenasInsideLen][0]=o;
      puntarenasInside[puntarenasInsideLen][1]=i;
      puntarenasInsideLen+=1;
    }
    else if(pointInside(n8,list8,o,i)==1){
      
      puntarenasInside[puntarenasInsideLen][0]=o;
      puntarenasInside[puntarenasInsideLen][1]=i;
      puntarenasInsideLen+=1;
    }
    
  }
  } 
  free(list1);
  free(list2);
  free(list3);
  free(list4);
  free(list5);
  free(list6);
  free(list7);
  free(list8);
  //printf("Pasa 0\n");
//}

  size_t x;
  MagickWand *magick_wand;
  PixelIterator *iterator;
  PixelWand **pixels;
  MagickWandGenesis();
  magick_wand = NewMagickWand();

  MagickReadImage(magick_wand, "images/hr.jpg");
  for (int i = 0; i < herediaInsideLen; i++)
  {
    iterator = NewPixelRegionIterator(magick_wand,herediaInside[i][0],herediaInside[i][1],1,1);
    pixels=PixelGetNextIteratorRow(iterator,&x);
    float colorR=PixelGetRed(pixels[0]);
    float colorG=PixelGetGreen(pixels[0]);
    float colorB=PixelGetBlue(pixels[0]);
      
    glColor3f (colorR,colorG,colorB);
    plot(herediaInside[i][0],herediaInside[i][1]);
    iterator=DestroyPixelIterator(iterator); 
  }
  //printf("Pasa 1\n");

  ClearMagickWand(magick_wand);

  MagickReadImage(magick_wand, "images/al.jpg");

  for (int i = 0; i < alajuelaInsideLen; i++)
  {
    iterator = NewPixelRegionIterator(magick_wand,alajuelaInside[i][0],alajuelaInside[i][1],1,1);
    pixels=PixelGetNextIteratorRow(iterator,&x);
    float colorR=PixelGetRed(pixels[0]);
    float colorG=PixelGetGreen(pixels[0]);
    float colorB=PixelGetBlue(pixels[0]);
      
    glColor3f (colorR,colorG,colorB);
    plot(alajuelaInside[i][0],alajuelaInside[i][1]);
    iterator=DestroyPixelIterator(iterator); 
  }
  //printf("Pasa 2\n");
  
  ClearMagickWand(magick_wand);

  MagickReadImage(magick_wand, "images/ct.jpg");
  for (int i = 0; i < cartagoInsideLen; i++)
  {
    iterator = NewPixelRegionIterator(magick_wand,cartagoInside[i][0],cartagoInside[i][1],1,1);

    pixels=PixelGetNextIteratorRow(iterator,&x);
    float colorR=PixelGetRed(pixels[0]);
    float colorG=PixelGetGreen(pixels[0]);
    float colorB=PixelGetBlue(pixels[0]);
      
    glColor3f (colorR,colorG,colorB);
    plot(cartagoInside[i][0],cartagoInside[i][1]);
    iterator=DestroyPixelIterator(iterator);
  }
  //printf("Pasa 3\n");
   
  ClearMagickWand(magick_wand);

  MagickReadImage(magick_wand, "images/sj.jpg");
  for (int i = 0; i < sanjoseInsideLen; i++)
  {
    iterator = NewPixelRegionIterator(magick_wand,sanjoseInside[i][0],sanjoseInside[i][1],1,1);
    pixels=PixelGetNextIteratorRow(iterator,&x);
    float colorR=PixelGetRed(pixels[0]);
    float colorG=PixelGetGreen(pixels[0]);
    float colorB=PixelGetBlue(pixels[0]);
      
    glColor3f (colorR,colorG,colorB);
    plot(sanjoseInside[i][0],sanjoseInside[i][1]);
    iterator=DestroyPixelIterator(iterator); 
  }
  //printf("Pasa 4 \n");
  
  ClearMagickWand(magick_wand);

  MagickReadImage(magick_wand, "images/lm.jpg");
  for (int i = 0; i < limonInsideLen; i++)
  {
    iterator = NewPixelRegionIterator(magick_wand,limonInside[i][0],limonInside[i][1],1,1);
    pixels=PixelGetNextIteratorRow(iterator,&x);
    float colorR=PixelGetRed(pixels[0]);
    float colorG=PixelGetGreen(pixels[0]);
    float colorB=PixelGetBlue(pixels[0]);
      
    glColor3f (colorR,colorG,colorB);
    plot(limonInside[i][0],limonInside[i][1]);
    iterator=DestroyPixelIterator(iterator); 
  }
  //printf("Pasa 5\n");
  
  ClearMagickWand(magick_wand);

  MagickReadImage(magick_wand, "images/gn.jpg");
  for (int i = 0; i < guanacasteInsideLen; i++)
  {
    iterator = NewPixelRegionIterator(magick_wand,guanacasteInside[i][0],guanacasteInside[i][1],1,1);
    pixels=PixelGetNextIteratorRow(iterator,&x);
    float colorR=PixelGetRed(pixels[0]);
    float colorG=PixelGetGreen(pixels[0]);
    float colorB=PixelGetBlue(pixels[0]);
      
    glColor3f (colorR,colorG,colorB);
    plot(guanacasteInside[i][0],guanacasteInside[i][1]);
    iterator=DestroyPixelIterator(iterator); 
  }
  //printf("Pasa 6\n");

  ClearMagickWand(magick_wand);

  MagickReadImage(magick_wand, "images/pt.jpg");
  for (int i = 0; i < puntarenasInsideLen; i++)
  {
    iterator = NewPixelRegionIterator(magick_wand,puntarenasInside[i][0],puntarenasInside[i][1],1,1);
    pixels=PixelGetNextIteratorRow(iterator,&x);
    float colorR=PixelGetRed(pixels[0]);
    float colorG=PixelGetGreen(pixels[0]);
    float colorB=PixelGetBlue(pixels[0]);
      
    glColor3f (colorR,colorG,colorB);
    plot(puntarenasInside[i][0],puntarenasInside[i][1]);
    iterator=DestroyPixelIterator(iterator); 
  }
  //printf("Pasa 7\n");
  
  ClearMagickWand(magick_wand);
  magick_wand = DestroyMagickWand(magick_wand);
  MagickWandTerminus();
}

int pointInside(int vertices, PIX* vert  , int x, int y)
{
  int i, j, c = 0;
  for (i = 0, j = vertices-1; i < vertices; j = i++) {
    if ( ((vert[i].y>y) != (vert[j].y>y)) && (vert[j].y-vert[i].y + vert[i].x) != 0 &&
     (x < (vert[j].x-vert[i].x) * (y-vert[i].y) / (vert[j].y-vert[i].y) + vert[i].x) )
       c = !c;
  }
  return c;
}
