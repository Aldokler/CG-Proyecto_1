

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#include "./Operaciones/traslado.h"


int len_x_universal = 28.41;
int len_y_universal = 26.8;

typedef struct {
  long double x;
  long double y;
} UPOINT;

//HEREDIA
	UPOINT hrd_0 = {.x = 14.83, .y = 22.5};
	UPOINT hrd_1 = {.x = 14.95, .y = 22.37};
	UPOINT hrd_2 = {.x = 15.13, .y = 22.43};
	UPOINT hrd_3 = {.x = 15.3, .y = 22.32};
	UPOINT hrd_4 = {.x = 15.489, .y = 22.36};
	UPOINT hrd_5 = {.x = 15.51, .y = 22.48};
	UPOINT hrd_6 = {.x = 15.69, .y = 22.41};
	UPOINT hrd_7 = {.x = 15.74, .y = 22.57};
	UPOINT hrd_8 = {.x = 15.84, .y = 22.4};
	UPOINT hrd_9 = {.x = 16.13, .y = 22.25};
	UPOINT hrd_10 = {.x = 16.2, .y = 22.1};
	UPOINT hrd_11 = {.x = 16.44, .y = 22.02};
	UPOINT hrd_12 = {.x = 16.5, .y = 21.98};
	UPOINT hrd_13 = {.x = 16.82, .y = 22.05};
	UPOINT hrd_14 = {.x = 17, .y = 22.001};
	UPOINT hrd_15 = {.x = 17.21, .y = 22.24};
	UPOINT hrd_16 = {.x = 17.39, .y = 22.23};
	UPOINT hrd_17 = {.x = 17.6, .y = 22.44};
	UPOINT hrd_18 = {.x = 17.87, .y = 22.43}; //Limon
	UPOINT hrd_19 = {.x = 18.001, .y = 22.3};
	UPOINT hrd_20 = {.x = 17.998, .y = 22.089}; 
	UPOINT hrd_21 = {.x = 18.09, .y = 22};
	UPOINT hrd_22 = {.x = 18.2, .y = 21.91};
	UPOINT hrd_23 = {.x = 17.93, .y = 21.9};
	UPOINT hrd_24 = {.x = 17.8, .y = 21.91};
	UPOINT hrd_25 = {.x = 17.7, .y = 21.88};
	UPOINT hrd_26 = {.x = 17.51, .y = 21.8};
	UPOINT hrd_27 = {.x = 17.38, .y = 21.6};
	UPOINT hrd_28 = {.x = 17.23, .y = 21.57};
	UPOINT hrd_29 = {.x = 17.2, .y = 21.17};
	UPOINT hrd_30 = {.x = 17.27, .y = 21.08};
	UPOINT hrd_31 = {.x = 17.18, .y = 20.77};
	UPOINT hrd_32 = {.x = 17.31, .y = 20.34};
	UPOINT hrd_33 = {.x = 17.21, .y = 20};
	UPOINT hrd_34 = {.x = 17.07, .y = 19.91};
	UPOINT hrd_35 = {.x = 16.9, .y = 19.59};
	UPOINT hrd_36 = {.x = 17.15, .y = 19.37};
	UPOINT hrd_37 = {.x = 17.175, .y = 19.08};
	UPOINT hrd_38 = {.x = 17.15, .y = 18.89};
	UPOINT hrd_39 = {.x = 17.175, .y = 18.615};
	UPOINT hrd_40 = {.x = 17.05, .y = 18.4};
	UPOINT hrd_41 = {.x = 16.95, .y = 18.38};
	UPOINT hrd_42 = {.x = 16.82, .y = 18.2};
	UPOINT hrd_43 = {.x = 16.675, .y = 18.16};
	UPOINT hrd_44 = {.x = 16.52, .y = 17.98}; //Limon
	UPOINT hrd_45 = {.x = 16.23, .y = 17.77};
	UPOINT hrd_46 = {.x = 16.2, .y = 17.46};
	UPOINT hrd_47 = {.x = 16.1, .y = 17.23};
	UPOINT hrd_48 = {.x = 15.85, .y = 17.15};
	UPOINT hrd_49 = {.x = 15.81, .y = 16.945};
	UPOINT hrd_50 = {.x = 15.95, .y = 16.84};
	UPOINT hrd_51 = {.x = 15.9, .y = 16.6};
	UPOINT hrd_52 = {.x = 15.67, .y = 16.32};
	UPOINT hrd_53 = {.x = 15.3, .y = 16.19};
	UPOINT hrd_54 = {.x = 15.1, .y = 16.22};
	UPOINT hrd_55 = {.x = 14.9, .y = 16.189};
	UPOINT hrd_56 = {.x = 14.65, .y = 16.27};
	UPOINT hrd_57 = {.x = 14.82, .y = 17.2};

//HEREDIA
UPOINT * heredia[58] = {
	&hrd_0, &hrd_1, &hrd_2, &hrd_3, &hrd_4, &hrd_5, &hrd_6, &hrd_7, &hrd_8, &hrd_9,
	&hrd_10, &hrd_11, &hrd_12, &hrd_13, &hrd_14, &hrd_15, &hrd_16, &hrd_17, &hrd_18, &hrd_19,
	&hrd_20, &hrd_21, &hrd_22, &hrd_23, &hrd_24, &hrd_25, &hrd_26, &hrd_27, &hrd_28, &hrd_29,
	&hrd_30, &hrd_31, &hrd_32, &hrd_33, &hrd_34, &hrd_35, &hrd_36, &hrd_37, &hrd_38, &hrd_39,
	&hrd_40, &hrd_41, &hrd_42, &hrd_43, &hrd_44, &hrd_45, &hrd_46, &hrd_47, &hrd_48, &hrd_49,
	&hrd_50, &hrd_51, &hrd_52, &hrd_53, &hrd_54, &hrd_55, &hrd_56, &hrd_57
};

typedef struct {
  double r;
  double g;
  double b;
} COLOR;

void bressenham_line ();

void plot();

void paint_pol();

void convert_utop();