

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#include "./Operaciones/traslado.h"

#define LEN_HEREDIA 58
#define LEN_LIMON 125
#define LEN_CARTAGO 55
#define LEN_SANJOSE 119
#define LEN_ALAJUELA 80

int len_x_universal = 28.41;
int len_y_universal = 26.8;

typedef struct {
  long double x;
  long double y;
} UPOINT;

/*
####################################################################################################################
====================================================================================================================
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
====================================================================================================================
####################################################################################################################
*/

//HEREDIA
	UPOINT hrd_0 = {.x = 14.83, .y = 22.5}; //^^^ Alajuela ^^^
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
	UPOINT hrd_18 = {.x = 17.87, .y = 22.43}; //vvv Limon vvv
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
	UPOINT hrd_44 = {.x = 16.52, .y = 17.98}; //^^^ Limon ^^^ vvv San Jose vvv
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
	UPOINT hrd_56 = {.x = 14.65, .y = 16.27};//^^^ San Jose ^^^ vvv Alajuela vvv
	UPOINT hrd_57 = {.x = 14.82, .y = 17.2};

//HEREDIA
UPOINT * heredia[LEN_HEREDIA] = {
	&hrd_0, &hrd_1, &hrd_2, &hrd_3, &hrd_4, &hrd_5, &hrd_6, &hrd_7, &hrd_8, &hrd_9,
	&hrd_10, &hrd_11, &hrd_12, &hrd_13, &hrd_14, &hrd_15, &hrd_16, &hrd_17, &hrd_18, &hrd_19,
	&hrd_20, &hrd_21, &hrd_22, &hrd_23, &hrd_24, &hrd_25, &hrd_26, &hrd_27, &hrd_28, &hrd_29,
	&hrd_30, &hrd_31, &hrd_32, &hrd_33, &hrd_34, &hrd_35, &hrd_36, &hrd_37, &hrd_38, &hrd_39,
	&hrd_40, &hrd_41, &hrd_42, &hrd_43, &hrd_44, &hrd_45, &hrd_46, &hrd_47, &hrd_48, &hrd_49,
	&hrd_50, &hrd_51, &hrd_52, &hrd_53, &hrd_54, &hrd_55, &hrd_56, &hrd_57
};

/*
####################################################################################################################
====================================================================================================================
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
====================================================================================================================
####################################################################################################################
*/

//LIMON
	UPOINT lmn_0 = {.x = 17.87, .y = 22.43}; //^^^ Heredia ^^^
	UPOINT lmn_1 = {.x = 18.06, .y = 22.59};
	UPOINT lmn_2 = {.x = 18.42, .y = 22.6};
	UPOINT lmn_3 = {.x = 18.57, .y = 22.7};
	UPOINT lmn_4 = {.x = 18.6, .y = 22.85};
	UPOINT lmn_5 = {.x = 18.5, .y = 23.07};
	UPOINT lmn_6 = {.x = 18.5, .y = 23.4};
	UPOINT lmn_7 = {.x = 18.54, .y = 23.67};
	UPOINT lmn_8 = {.x = 18.62, .y = 23.78};
	UPOINT lmn_9 = {.x = 18.7, .y = 23.6};
	UPOINT lmn_10 = {.x = 18.8, .y = 23.46};
	UPOINT lmn_11 = {.x = 18.92, .y = 23.28};
	UPOINT lmn_12 = {.x = 19.13, .y = 22.69};
	UPOINT lmn_13 = {.x = 19.11, .y = 22.55};
	UPOINT lmn_14 = {.x = 19.61, .y = 21.05};
	UPOINT lmn_15 = {.x = 19.96, .y = 20.4};
	UPOINT lmn_16 = {.x = 20.92, .y = 19};
	UPOINT lmn_17 = {.x = 22.68, .y = 16.82};
	UPOINT lmn_18 = {.x = 22.95, .y = 16.63};
	UPOINT lmn_19 = {.x = 23, .y = 16.7};
	UPOINT lmn_20 = {.x = 23.22, .y = 16.71};
	UPOINT lmn_21 = {.x = 23.46, .y = 16.6};
	UPOINT lmn_22 = {.x = 23.45, .y = 16.43};
	UPOINT lmn_23 = {.x = 23.5, .y = 16.3};
	UPOINT lmn_24 = {.x = 24.32, .y = 15.16};
	UPOINT lmn_25 = {.x = 24.76, .y = 14.69};
	UPOINT lmn_26 = {.x = 25.08, .y = 14.78};
	UPOINT lmn_27 = {.x = 25, .y = 14.53};
	UPOINT lmn_28 = {.x = 28.41-3.21, .y = 14.18};
	UPOINT lmn_29 = {.x = 28.41-3, .y = 13.96};
	UPOINT lmn_30 = {.x = 28.41-2.91, .y = 14};
	UPOINT lmn_31 = {.x = 28.41-2.75, .y = 13.9};
	UPOINT lmn_32 = {.x = 28.41-2.5, .y = 13.875};
	UPOINT lmn_33 = {.x = 28.41-2.43, .y = 13.89};
	UPOINT lmn_34 = {.x = 28.41-2.3, .y = 13.84};
	UPOINT lmn_35 = {.x = 28.41-2.13, .y = 13.9};
	UPOINT lmn_36 = {.x = 28.41-1.86, .y = 13.85};
	UPOINT lmn_37 = {.x = 28.41-1.8, .y = 13.68};
	UPOINT lmn_38 = {.x = 28.41-1.62, .y = 13.48};
	UPOINT lmn_39 = {.x = 28.41-1.37, .y = 13.36};
	UPOINT lmn_40 = {.x = 28.41-1.3, .y = 13.07};
	UPOINT lmn_41 = {.x = 28.41-1.67, .y = 13.2};
	UPOINT lmn_42 = {.x = 28.41-1.66, .y = 12.98};
	UPOINT lmn_43 = {.x = 28.41-1.78, .y = 12.8};
	UPOINT lmn_44 = {.x = 28.41-2.15, .y = 12.79};
	UPOINT lmn_45 = {.x = 28.41-2.2, .y = 12.75};
	UPOINT lmn_46 = {.x = 28.41-2.3, .y = 12.83};
	UPOINT lmn_47 = {.x = 28.41-2.51, .y = 12.97};
	UPOINT lmn_48 = {.x = 28.41-2.49, .y = 13.09};
	UPOINT lmn_49 = {.x = 28.41-2.55, .y = 13.2};
	UPOINT lmn_50 = {.x = 28.41-2.63, .y = 13.1};
	UPOINT lmn_51 = {.x = 28.41-2.9, .y = 13.37};
	UPOINT lmn_52 = {.x = 28.41-3.28, .y = 13.49};
	UPOINT lmn_53 = {.x = 28.41-3.51, .y = 13.55};
	UPOINT lmn_54 = {.x = 28.41-3.56, .y = 13.69};
	UPOINT lmn_55 = {.x = 28.41-3.7, .y = 13.63};
	UPOINT lmn_56 = {.x = 28.41-3.9, .y = 13.25};
	UPOINT lmn_57 = {.x = 28.41-3.78, .y = 13.2};
	UPOINT lmn_58 = {.x = 28.41-3.73, .y = 13.09};
	UPOINT lmn_59 = {.x = 28.41-3.8, .y = 12.98};
	UPOINT lmn_60 = {.x = 28.41-3.5, .y = 12.78};
	UPOINT lmn_61 = {.x = 24.24, .y = 12.52};
	UPOINT lmn_62 = {.x = 24.24, .y = 9.58};//vvv Puntarenas vvv
	UPOINT lmn_63 = {.x = 23.95, .y = 9.69};
	UPOINT lmn_64 = {.x = 23.8, .y = 10.13};
	UPOINT lmn_65 = {.x = 23.33, .y = 10.23};
	UPOINT lmn_66 = {.x = 23.35, .y = 10.45};
	UPOINT lmn_67 = {.x = 23.24, .y = 10.6};
	UPOINT lmn_68 = {.x = 23.23, .y = 10.79};
	UPOINT lmn_69 = {.x = 22.71, .y = 11.08};
	UPOINT lmn_70 = {.x = 22.43, .y = 11.47};
	UPOINT lmn_71 = {.x = 22.08, .y = 11.4};
	UPOINT lmn_72 = {.x = 21.6, .y = 11.64};
	UPOINT lmn_73 = {.x = 21.36, .y = 11.85};
	UPOINT lmn_74 = {.x = 21.17, .y = 11.8};
	UPOINT lmn_75 = {.x = 21.09, .y = 11.6};
	UPOINT lmn_76 = {.x = 20.83, .y = 11.61};
	UPOINT lmn_77 = {.x = 20.68, .y = 11.52};
	UPOINT lmn_78 = {.x = 20.6, .y = 11.73};
	UPOINT lmn_79 = {.x = 20.41, .y = 11.7};//^^^ Puntarenas ^^^ vvv San Jose vvv
	UPOINT lmn_80 = {.x = 20.1, .y = 12.2};
	UPOINT lmn_81 = {.x = 20.08, .y = 12.4};
	UPOINT lmn_82 = {.x = 20, .y = 12.47};
	UPOINT lmn_83 = {.x = 19.84, .y = 12.8};//^^^ San Jose ^^^ vvv Cartago vvv
	UPOINT lmn_84 = {.x = 19.74, .y = 13.21};
	UPOINT lmn_85 = {.x = 19.68, .y = 13.38};
	UPOINT lmn_86 = {.x = 19.9, .y = 13.6};
	UPOINT lmn_87 = {.x = 20.05, .y = 13.63};
	UPOINT lmn_88 = {.x = 20.39, .y = 14.1};
	UPOINT lmn_89 = {.x = 20.42, .y = 14.32};
	UPOINT lmn_90 = {.x = 21.067, .y = 15.23};
	UPOINT lmn_91 = {.x = 21.1, .y = 15.68};
	UPOINT lmn_92 = {.x = 21.03, .y = 15.79};
	UPOINT lmn_93 = {.x = 21, .y = 16.09};
	UPOINT lmn_94 = {.x = 21.09, .y = 16.13};
	UPOINT lmn_95 = {.x = 21.07, .y = 16.26};
	UPOINT lmn_96 = {.x = 21.28, .y = 16.4};
	UPOINT lmn_97 = {.x = 19.1, .y = 16.4};
	UPOINT lmn_98 = {.x = 16.5, .y = 17.68};//^^^ Cartago ^^^ vvv San Jose vvv
	UPOINT lmn_99 = {.x = 16.52, .y = 17.98}; //vvv Heredia vvv ^^^ San Jose ^^^
	UPOINT lmn_100 = {.x = 16.675, .y = 18.16};
	UPOINT lmn_101 = {.x = 16.82, .y = 18.2};
	UPOINT lmn_102 = {.x = 16.95, .y = 18.38};
	UPOINT lmn_103 = {.x = 17.05, .y = 18.4};
	UPOINT lmn_104 = {.x = 17.175, .y = 18.615};
	UPOINT lmn_105 = {.x = 17.15, .y = 18.89};
	UPOINT lmn_106 = {.x = 17.175, .y = 19.08};
	UPOINT lmn_107 = {.x = 17.15, .y = 19.37};
	UPOINT lmn_108 = {.x = 16.9, .y = 19.59};
	UPOINT lmn_109 = {.x = 17.07, .y = 19.91};
	UPOINT lmn_110 = {.x = 17.21, .y = 20};
	UPOINT lmn_111 = {.x = 17.31, .y = 20.34};
	UPOINT lmn_112 = {.x = 17.18, .y = 20.77};
	UPOINT lmn_113 = {.x = 17.27, .y = 21.08};
	UPOINT lmn_114 = {.x = 17.2, .y = 21.17};
	UPOINT lmn_115 = {.x = 17.23, .y = 21.57};
	UPOINT lmn_116 = {.x = 17.38, .y = 21.6};
	UPOINT lmn_117 = {.x = 17.51, .y = 21.8};
	UPOINT lmn_118 = {.x = 17.7, .y = 21.88};
	UPOINT lmn_119 = {.x = 17.8, .y = 21.91};
	UPOINT lmn_120 = {.x = 17.93, .y = 21.9};
	UPOINT lmn_121 = {.x = 18.2, .y = 21.91};
	UPOINT lmn_122 = {.x = 18.09, .y = 22};
	UPOINT lmn_123 = {.x = 17.998, .y = 22.089}; 
	UPOINT lmn_124 = {.x = 18.001, .y = 22.3};

//LIMON
UPOINT * limon[LEN_LIMON] = {
	&lmn_0, &lmn_1, &lmn_2, &lmn_3, &lmn_4, &lmn_5, &lmn_6, &lmn_7, &lmn_8, &lmn_9,
	&lmn_10, &lmn_11, &lmn_12, &lmn_13, &lmn_14, &lmn_15, &lmn_16, &lmn_17, &lmn_18, &lmn_19,
	&lmn_20, &lmn_21, &lmn_22, &lmn_23, &lmn_24, &lmn_25, &lmn_26, &lmn_27, &lmn_28, &lmn_29,
	&lmn_30, &lmn_31, &lmn_32, &lmn_33, &lmn_34, &lmn_35, &lmn_36, &lmn_37, &lmn_38, &lmn_39,
	&lmn_40, &lmn_41, &lmn_42, &lmn_43, &lmn_44, &lmn_45, &lmn_46, &lmn_47, &lmn_48, &lmn_49,
	&lmn_50, &lmn_51, &lmn_52, &lmn_53, &lmn_54, &lmn_55, &lmn_56, &lmn_57, &lmn_58, &lmn_59,
	&lmn_60, &lmn_61, &lmn_62, &lmn_63, &lmn_64, &lmn_65, &lmn_66, &lmn_67, &lmn_68, &lmn_69,
	&lmn_70, &lmn_71, &lmn_72, &lmn_73, &lmn_74, &lmn_75, &lmn_76, &lmn_77, &lmn_78, &lmn_79,
	&lmn_80, &lmn_81, &lmn_82, &lmn_83, &lmn_84, &lmn_85, &lmn_86, &lmn_87, &lmn_88, &lmn_89,
	&lmn_90, &lmn_91, &lmn_92, &lmn_93, &lmn_94, &lmn_95, &lmn_96, &lmn_97, &lmn_98, &lmn_99,
	&lmn_100, &lmn_101, &lmn_102, &lmn_103, &lmn_104, &lmn_105, &lmn_106, &lmn_107, &lmn_108, &lmn_109,
	&lmn_110, &lmn_111, &lmn_112, &lmn_113, &lmn_114, &lmn_115, &lmn_116, &lmn_117, &lmn_118, &lmn_119,
	&lmn_120, &lmn_121, &lmn_122, &lmn_123, &lmn_124
};

/*
####################################################################################################################
====================================================================================================================
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
====================================================================================================================
####################################################################################################################
*/

//CARTAGO
	UPOINT crt_0 = {.x = 16.5, .y = 17.68};//^^^ San Jose ^^^ vvv Limon vvv
	UPOINT crt_1 = {.x = 19.1, .y = 16.4};
	UPOINT crt_2 = {.x = 21.28, .y = 16.4};
	UPOINT crt_3 = {.x = 21.07, .y = 16.26};
	UPOINT crt_4 = {.x = 21.09, .y = 16.13};
	UPOINT crt_5 = {.x = 21, .y = 16.09};
	UPOINT crt_6 = {.x = 21.03, .y = 15.79};
	UPOINT crt_7 = {.x = 21.1, .y = 15.68};
	UPOINT crt_8 = {.x = 21.067, .y = 15.23};
	UPOINT crt_9 = {.x = 20.42, .y = 14.32};
	UPOINT crt_10 = {.x = 20.39, .y = 14.1};
	UPOINT crt_11 = {.x = 20.05, .y = 13.63};
	UPOINT crt_12 = {.x = 19.9, .y = 13.6};
	UPOINT crt_13 = {.x = 19.68, .y = 13.38};
	UPOINT crt_14 = {.x = 19.74, .y = 13.21};
	UPOINT crt_15 = {.x = 19.84, .y = 12.8};//vvv San Jose vvv ^^^ Limon ^^^
	UPOINT crt_16 = {.x = 19.5, .y = 12.99};
	UPOINT crt_17 = {.x = 19.33, .y = 13};
	UPOINT crt_18 = {.x = 18.81, .y = 13.35};
	UPOINT crt_19 = {.x = 18.67, .y = 13.33};
	UPOINT crt_20 = {.x = 18.6, .y = 13.12};
	UPOINT crt_21 = {.x = 18.5, .y = 13.135};
	UPOINT crt_22 = {.x = 18.38, .y = 13.12};
	UPOINT crt_23 = {.x = 18, .y = 13.16};
	UPOINT crt_24 = {.x = 17.91, .y = 13.27};
	UPOINT crt_25 = {.x = 18, .y = 13.4};
	UPOINT crt_26 = {.x = 17.33, .y = 13.66};
	UPOINT crt_27 = {.x = 17.3, .y = 13.91};
	UPOINT crt_28 = {.x = 16.68, .y = 14.19};
	UPOINT crt_29 = {.x = 16.58, .y = 14.16};
	UPOINT crt_30 = {.x = 16.51, .y = 14.39};
	UPOINT crt_31 = {.x = 16.41, .y = 14.52};
	UPOINT crt_32 = {.x = 16.29, .y = 14.55};
	UPOINT crt_33 = {.x = 16.19, .y = 14.7};
	UPOINT crt_34 = {.x = 16.2, .y = 14.89};
	UPOINT crt_35 = {.x = 15.93, .y = 14.73};
	UPOINT crt_36 = {.x = 15.46, .y = 14.73};
	UPOINT crt_37 = {.x = 15.56, .y = 14.99};
	UPOINT crt_38 = {.x = 15.81, .y = 15.125};
	UPOINT crt_39 = {.x = 15.93, .y = 15.315};
	UPOINT crt_40 = {.x = 16.1, .y = 15.49};
	UPOINT crt_41 = {.x = 16.08, .y = 15.62};
	UPOINT crt_42 = {.x = 15.85, .y = 15.65};
	UPOINT crt_43 = {.x = 15.9, .y = 15.78};
	UPOINT crt_44 = {.x = 16.09, .y = 15.85};
	UPOINT crt_45 = {.x = 16.18, .y = 16.08};
	UPOINT crt_46 = {.x = 16.64, .y = 16.2};
	UPOINT crt_47 = {.x = 16.95, .y = 16.32};
	UPOINT crt_48 = {.x = 17.2, .y = 16.32};
	UPOINT crt_49 = {.x = 17.1, .y = 16.46};
	UPOINT crt_50 = {.x = 17.09, .y = 16.68};
	UPOINT crt_51 = {.x = 17, .y = 16.8};
	UPOINT crt_52 = {.x = 16.98, .y = 16.92};
	UPOINT crt_53 = {.x = 16.635, .y = 17.15};
	UPOINT crt_54 = {.x = 16.6, .y = 17.39};

//CARTAGO
UPOINT * cartago[LEN_CARTAGO] = {
	&crt_0, &crt_1, &crt_2, &crt_3, &crt_4, &crt_5, &crt_6, &crt_7, &crt_8, &crt_9,
	&crt_10, &crt_11, &crt_12, &crt_13, &crt_14, &crt_15, &crt_16, &crt_17, &crt_18, &crt_19,
	&crt_20, &crt_21, &crt_22, &crt_23, &crt_24, &crt_25, &crt_26, &crt_27, &crt_28, &crt_29,
	&crt_30, &crt_31, &crt_32, &crt_33, &crt_34, &crt_35, &crt_36, &crt_37, &crt_38, &crt_39,
	&crt_40, &crt_41, &crt_42, &crt_43, &crt_44, &crt_45, &crt_46, &crt_47, &crt_48, &crt_49,
	&crt_50, &crt_51, &crt_52, &crt_53, &crt_54
};

/*
####################################################################################################################
====================================================================================================================
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
====================================================================================================================
####################################################################################################################
*/

//SAN JOSE
	UPOINT sjs_0 = {.x = 16.52, .y = 17.98}; //^^^ Limon ^^^ vvv Heredia vvv
	UPOINT sjs_1 = {.x = 16.23, .y = 17.77};
	UPOINT sjs_2 = {.x = 16.2, .y = 17.46};
	UPOINT sjs_3 = {.x = 16.1, .y = 17.23};
	UPOINT sjs_4 = {.x = 15.85, .y = 17.15};
	UPOINT sjs_5 = {.x = 15.81, .y = 16.945};
	UPOINT sjs_6 = {.x = 15.95, .y = 16.84};
	UPOINT sjs_7 = {.x = 15.9, .y = 16.6};
	UPOINT sjs_8 = {.x = 15.67, .y = 16.32};
	UPOINT sjs_9 = {.x = 15.3, .y = 16.19};
	UPOINT sjs_10 = {.x = 15.1, .y = 16.22};
	UPOINT sjs_11 = {.x = 14.9, .y = 16.189};
	UPOINT sjs_12 = {.x = 14.65, .y = 16.27};//^^^ Heredia ^^^ vvv Alajuela vvv
	UPOINT sjs_13 = {.x = 14.05, .y = 15.93};
	UPOINT sjs_14 = {.x = 13.84, .y = 15.92};
	UPOINT sjs_15 = {.x = 13.45, .y = 15.81};
	UPOINT sjs_16 = {.x = 13.12, .y = 16};
	UPOINT sjs_17 = {.x = 12.92, .y = 15.9};
	UPOINT sjs_18 = {.x = 12.43, .y = 15.82};
	UPOINT sjs_19 = {.x = 12, .y = 15.5};
	UPOINT sjs_20 = {.x = 11.8, .y = 15.21};//vvv Puntarenas vvv ^^^ Alajuela ^^^
	UPOINT sjs_21 = {.x = 11.79, .y = 15.06};
	UPOINT sjs_22 = {.x = 11.81, .y = 14.86};
	UPOINT sjs_23 = {.x = 12, .y = 14.79};
	UPOINT sjs_24 = {.x = 11.93, .y = 14.66};
	UPOINT sjs_25 = {.x = 11.68, .y = 14.59};
	UPOINT sjs_26 = {.x = 11.6, .y = 14.49};
	UPOINT sjs_27 = {.x = 11.7, .y = 14.22};
	UPOINT sjs_28 = {.x = 11.66, .y = 14.02};
	UPOINT sjs_29 = {.x = 11.94, .y = 13.65};
	UPOINT sjs_30 = {.x = 12.06, .y = 13.2};
	UPOINT sjs_31 = {.x = 12.39, .y = 13.19};
	UPOINT sjs_32 = {.x = 12.49, .y = 13.23};
	UPOINT sjs_33 = {.x = 12.58, .y = 13.21};
	UPOINT sjs_34 = {.x = 12.67, .y = 13.3};
	UPOINT sjs_35 = {.x = 12.84, .y = 13.19};
	UPOINT sjs_36 = {.x = 13.1, .y = 13.37};
	UPOINT sjs_37 = {.x = 13.19, .y = 13.75};
	UPOINT sjs_38 = {.x = 13.55, .y = 13.8};
	UPOINT sjs_39 = {.x = 13.94, .y = 13.78};
	UPOINT sjs_40 = {.x = 14.07, .y = 13.699};
	UPOINT sjs_41 = {.x = 14.45, .y = 13.65};
	UPOINT sjs_42 = {.x = 14.8, .y = 13.7};
	UPOINT sjs_43 = {.x = 15.02, .y = 13.64};
	UPOINT sjs_44 = {.x = 15.06, .y = 13.535};
	UPOINT sjs_45 = {.x = 15, .y = 13.38};
	UPOINT sjs_46 = {.x = 15.1, .y = 13.2};
	UPOINT sjs_47 = {.x = 15.385, .y = 13.25};
	UPOINT sjs_48 = {.x = 15.6, .y = 13.07};
	UPOINT sjs_49 = {.x = 15.59, .y = 12.82};
	UPOINT sjs_50 = {.x = 16.27, .y = 12.31};
	UPOINT sjs_51 = {.x = 16.28, .y = 12.19};
	UPOINT sjs_52 = {.x = 16.65, .y = 11.85};
	UPOINT sjs_53 = {.x = 16.7, .y = 12};
	UPOINT sjs_54 = {.x = 16.91, .y = 11.91};
	UPOINT sjs_55 = {.x = 17.02, .y = 11.61};
	UPOINT sjs_56 = {.x = 17.3, .y = 11.48};
	UPOINT sjs_57 = {.x = 17.24, .y = 11};
	UPOINT sjs_58 = {.x = 17.7, .y = 10.6};
	UPOINT sjs_59 = {.x = 18, .y = 10.699};
	UPOINT sjs_60 = {.x = 18.045, .y = 10.94};
	UPOINT sjs_61 = {.x = 18.565, .y = 10.42};
	UPOINT sjs_62 = {.x = 18.72, .y = 10};
	UPOINT sjs_63 = {.x = 19.15, .y = 9.835};
	UPOINT sjs_64 = {.x = 19.46, .y = 9.57};
	UPOINT sjs_65 = {.x = 19.87, .y = 9.56};
	UPOINT sjs_66 = {.x = 20.18, .y = 10.09};
	UPOINT sjs_67 = {.x = 20.07, .y = 10.39};
	UPOINT sjs_68 = {.x = 19.89, .y = 10.4};
	UPOINT sjs_69 = {.x = 19.72, .y = 10.51};
	UPOINT sjs_70 = {.x = 19.87, .y = 10.9};
	UPOINT sjs_71 = {.x = 20.01, .y = 11};
	UPOINT sjs_72 = {.x = 20.05, .y = 11.17};
	UPOINT sjs_73 = {.x = 20.24, .y = 11.45};
	UPOINT sjs_74 = {.x = 20.41, .y = 11.7};//^^^ Puntarenas ^^^ vvv Limon vvv
	UPOINT sjs_75 = {.x = 20.1, .y = 12.2};
	UPOINT sjs_76 = {.x = 20.08, .y = 12.4};
	UPOINT sjs_77 = {.x = 20, .y = 12.47};
	UPOINT sjs_78 = {.x = 19.84, .y = 12.8};//vvv Cartago vvv ^^^ Limon ^^^
	UPOINT sjs_79 = {.x = 19.5, .y = 12.99};
	UPOINT sjs_80 = {.x = 19.33, .y = 13};
	UPOINT sjs_81 = {.x = 18.81, .y = 13.35};
	UPOINT sjs_82 = {.x = 18.67, .y = 13.33};
	UPOINT sjs_83 = {.x = 18.6, .y = 13.12};
	UPOINT sjs_84 = {.x = 18.5, .y = 13.135};
	UPOINT sjs_85 = {.x = 18.38, .y = 13.12};
	UPOINT sjs_86 = {.x = 18, .y = 13.16};
	UPOINT sjs_87 = {.x = 17.91, .y = 13.27};
	UPOINT sjs_88 = {.x = 18, .y = 13.4};
	UPOINT sjs_89 = {.x = 17.33, .y = 13.66};
	UPOINT sjs_90 = {.x = 17.3, .y = 13.91};
	UPOINT sjs_91 = {.x = 16.68, .y = 14.19};
	UPOINT sjs_92 = {.x = 16.58, .y = 14.16};
	UPOINT sjs_93 = {.x = 16.51, .y = 14.39};
	UPOINT sjs_94 = {.x = 16.41, .y = 14.52};
	UPOINT sjs_95 = {.x = 16.29, .y = 14.55};
	UPOINT sjs_96 = {.x = 16.19, .y = 14.7};
	UPOINT sjs_97 = {.x = 16.2, .y = 14.89};
	UPOINT sjs_98 = {.x = 15.93, .y = 14.73};
	UPOINT sjs_99 = {.x = 15.46, .y = 14.73};
	UPOINT sjs_100 = {.x = 15.56, .y = 14.99};
	UPOINT sjs_101 = {.x = 15.81, .y = 15.125};
	UPOINT sjs_102 = {.x = 15.93, .y = 15.315};
	UPOINT sjs_103 = {.x = 16.1, .y = 15.49};
	UPOINT sjs_104 = {.x = 16.08, .y = 15.62};
	UPOINT sjs_105 = {.x = 15.85, .y = 15.65};
	UPOINT sjs_106 = {.x = 15.9, .y = 15.78};
	UPOINT sjs_107 = {.x = 16.09, .y = 15.85};
	UPOINT sjs_108 = {.x = 16.18, .y = 16.08};
	UPOINT sjs_109 = {.x = 16.64, .y = 16.2};
	UPOINT sjs_110 = {.x = 16.95, .y = 16.32};
	UPOINT sjs_111 = {.x = 17.2, .y = 16.32};
	UPOINT sjs_112 = {.x = 17.1, .y = 16.46};
	UPOINT sjs_113 = {.x = 17.09, .y = 16.68};
	UPOINT sjs_114 = {.x = 17, .y = 16.8};
	UPOINT sjs_115 = {.x = 16.98, .y = 16.92};
	UPOINT sjs_116 = {.x = 16.635, .y = 17.15};
	UPOINT sjs_117 = {.x = 16.6, .y = 17.39};
	UPOINT sjs_118 = {.x = 16.5, .y = 17.68};//^^^ Cartago ^^^ vvv Limon vvv

//SAN JOSE
UPOINT * sanJose[LEN_SANJOSE] = {
	&sjs_0, &sjs_1, &sjs_2, &sjs_3, &sjs_4, &sjs_5, &sjs_6, &sjs_7, &sjs_8, &sjs_9,
	&sjs_10, &sjs_11, &sjs_12, &sjs_13, &sjs_14, &sjs_15, &sjs_16, &sjs_17, &sjs_18, &sjs_19,
	&sjs_20, &sjs_21, &sjs_22, &sjs_23, &sjs_24, &sjs_25, &sjs_26, &sjs_27, &sjs_28, &sjs_29,
	&sjs_30, &sjs_31, &sjs_32, &sjs_33, &sjs_34, &sjs_35, &sjs_36, &sjs_37, &sjs_38, &sjs_39,
	&sjs_40, &sjs_41, &sjs_42, &sjs_43, &sjs_44, &sjs_45, &sjs_46, &sjs_47, &sjs_48, &sjs_49,
	&sjs_50, &sjs_51, &sjs_52, &sjs_53, &sjs_54, &sjs_55, &sjs_56, &sjs_57, &sjs_58, &sjs_59,
	&sjs_60, &sjs_61, &sjs_62, &sjs_63, &sjs_64, &sjs_65, &sjs_66, &sjs_67, &sjs_68, &sjs_69,
	&sjs_70, &sjs_71, &sjs_72, &sjs_73, &sjs_74, &sjs_75, &sjs_76, &sjs_77, &sjs_78, &sjs_79,
	&sjs_80, &sjs_81, &sjs_82, &sjs_83, &sjs_84, &sjs_85, &sjs_86, &sjs_87, &sjs_88, &sjs_89,
	&sjs_90, &sjs_91, &sjs_92, &sjs_93, &sjs_94, &sjs_95, &sjs_96, &sjs_97, &sjs_98, &sjs_99,
	&sjs_100, &sjs_101, &sjs_102, &sjs_103, &sjs_104, &sjs_105, &sjs_106, &sjs_107, &sjs_108, &sjs_109,
	&sjs_110, &sjs_111, &sjs_112, &sjs_113, &sjs_114, &sjs_115, &sjs_116, &sjs_117, &sjs_118
};

/*
####################################################################################################################
====================================================================================================================
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
====================================================================================================================
####################################################################################################################
*/

//ALAJUELA
	UPOINT ljl_0 = {.x = 6.7, .y = 24.72};//^^^ Guanacaste ^^^ vvv Nicaragua vvv
	UPOINT ljl_1 = {.x = 9.08, .y = 23.79};
	UPOINT ljl_2 = {.x = 10.9, .y = 24.8};
	UPOINT ljl_3 = {.x = 11.4, .y = 24.4};
	UPOINT ljl_4 = {.x = 11.57, .y = 24.51};
	UPOINT ljl_5 = {.x = 11.7, .y = 24.41};
	UPOINT ljl_6 = {.x = 12.38, .y = 24.17};
	UPOINT ljl_7 = {.x = 12.55, .y = 23.85};
	UPOINT ljl_8 = {.x = 12.82, .y = 23.82};
	UPOINT ljl_9 = {.x = 12.95, .y = 23.97};
	UPOINT ljl_10 = {.x = 13.29, .y = 24.025};
	UPOINT ljl_11 = {.x = 13.32, .y = 23.92};
	UPOINT ljl_12 = {.x = 13.29, .y = 23.76};
	UPOINT ljl_13 = {.x = 13.42, .y = 23.53};
	UPOINT ljl_14 = {.x = 13.68, .y = 23.46};
	UPOINT ljl_15 = {.x = 13.79, .y = 23.29};
	UPOINT ljl_16 = {.x = 14.2, .y = 23.19};
	UPOINT ljl_17 = {.x = 14.28, .y = 22.83};
	UPOINT ljl_18 = {.x = 14.11, .y = 22.69};
	UPOINT ljl_19 = {.x = 14.43, .y = 22.46};
	UPOINT ljl_20 = {.x = 14.83, .y = 22.5};//vvv Heredia vvv ^^^ Nicaragua ^^^
	UPOINT ljl_21 = {.x = 14.82, .y = 17.2};
	UPOINT ljl_22 = {.x = 14.65, .y = 16.27};//^^^ Heredia ^^^ vvv San Jose vvv
	UPOINT ljl_23 = {.x = 14.05, .y = 15.93};
	UPOINT ljl_24 = {.x = 13.84, .y = 15.92};
	UPOINT ljl_25 = {.x = 13.45, .y = 15.81};
	UPOINT ljl_26 = {.x = 13.12, .y = 16};
	UPOINT ljl_27 = {.x = 12.92, .y = 15.9};
	UPOINT ljl_28 = {.x = 12.43, .y = 15.82};
	UPOINT ljl_29 = {.x = 12, .y = 15.5};
	UPOINT ljl_30 = {.x = 11.8, .y = 15.21};//vvv Puntarenas vvv ^^^ San Jose ^^^
	UPOINT ljl_31 = {.x = 11.5, .y = 15.49};
	UPOINT ljl_32 = {.x = 11.21, .y = 15.48};
	UPOINT ljl_33 = {.x = 10.93, .y = 15.59};
	UPOINT ljl_34 = {.x = 10.92, .y = 15.79};
	UPOINT ljl_35 = {.x = 11.09, .y = 15.82};
	UPOINT ljl_36 = {.x = 11.195, .y = 16.03};
	UPOINT ljl_37 = {.x = 11.615, .y = 16.29};
	UPOINT ljl_38 = {.x = 11.91, .y = 16.4};
	UPOINT ljl_39 = {.x = 11.8, .y = 16.76};
	UPOINT ljl_40 = {.x = 11.7, .y = 16.62};
	UPOINT ljl_41 = {.x = 11.55, .y = 16.88};
	UPOINT ljl_42 = {.x = 11.36, .y = 16.81};
	UPOINT ljl_43 = {.x = 11.3, .y = 17.01};
	UPOINT ljl_44 = {.x = 11.18, .y = 17.2};
	UPOINT ljl_45 = {.x = 11, .y = 17.41};
	UPOINT ljl_46 = {.x = 11.065, .y = 17.68};
	UPOINT ljl_47 = {.x = 10.96, .y = 17.935};
	UPOINT ljl_48 = {.x = 11.1, .y = 18.24};
	UPOINT ljl_49 = {.x = 11.1, .y = 18.49};
	UPOINT ljl_50 = {.x = 10.99, .y = 18.52};
	UPOINT ljl_51 = {.x = 10.97, .y = 18.66};
	UPOINT ljl_52 = {.x = 10.54, .y = 18.56};
	UPOINT ljl_53 = {.x = 10.31, .y = 18.565};
	UPOINT ljl_54 = {.x = 10.19, .y = 18.71};
	UPOINT ljl_55 = {.x = 10.09, .y = 18.95};//^^^ Puntarenas ^^^ vvv Guanacaste vvv
	UPOINT ljl_56 = {.x = 10.19, .y = 19.31};
	UPOINT ljl_57 = {.x = 10.11, .y = 19.47};
	UPOINT ljl_58 = {.x = 10.19, .y = 19.65};
	UPOINT ljl_59 = {.x = 10.13, .y = 20.2};
	UPOINT ljl_60 = {.x = 9.71, .y = 20.5};
	UPOINT ljl_61 = {.x = 9.41, .y = 20.68};
	UPOINT ljl_62 = {.x = 9.06, .y = 20.8};
	UPOINT ljl_63 = {.x = 8.69, .y = 21.16};
	UPOINT ljl_64 = {.x = 8.2, .y = 21.99};
	UPOINT ljl_65 = {.x = 7.46, .y = 22.15};
	UPOINT ljl_66 = {.x = 7.18, .y = 22.32};
	UPOINT ljl_67 = {.x = 6.35, .y = 22.34};
	UPOINT ljl_68 = {.x = 6.18, .y = 22.55};
	UPOINT ljl_69 = {.x = 6.05, .y = 22.72};
	UPOINT ljl_70 = {.x = 5.55, .y = 22.96};
	UPOINT ljl_71 = {.x = 5.085, .y = 23.46};
	UPOINT ljl_72 = {.x = 5.18, .y = 23.54};
	UPOINT ljl_73 = {.x = 5.5, .y = 23.6};
	UPOINT ljl_74 = {.x = 5.49, .y = 23.9};
	UPOINT ljl_75 = {.x = 5.62, .y = 24.29};
	UPOINT ljl_76 = {.x = 5.87, .y = 24.4};
	UPOINT ljl_77 = {.x = 6.3, .y = 24.2};
	UPOINT ljl_78 = {.x = 6.42, .y = 24.29};
	UPOINT ljl_79 = {.x = 6.4, .y = 24.5};//vvv Nicaragua vvv ^^^ Guanacaste ^^^

//ALAJUELA
UPOINT * alajuela[LEN_ALAJUELA] = {
	&ljl_0, &ljl_1, &ljl_2, &ljl_3, &ljl_4, &ljl_5, &ljl_6, &ljl_7, &ljl_8, &ljl_9,
	&ljl_10, &ljl_11, &ljl_12, &ljl_13, &ljl_14, &ljl_15, &ljl_16, &ljl_17, &ljl_18, &ljl_19,
	&ljl_20, &ljl_21, &ljl_22, &ljl_23, &ljl_24, &ljl_25, &ljl_26, &ljl_27, &ljl_28, &ljl_29,
	&ljl_30, &ljl_31, &ljl_32, &ljl_33, &ljl_34, &ljl_35, &ljl_36, &ljl_37, &ljl_38, &ljl_39,
	&ljl_40, &ljl_41, &ljl_42, &ljl_43, &ljl_44, &ljl_45, &ljl_46, &ljl_47, &ljl_48, &ljl_49,
	&ljl_50, &ljl_51, &ljl_52, &ljl_53, &ljl_54, &ljl_55, &ljl_56, &ljl_57, &ljl_58, &ljl_59,
	&ljl_60, &ljl_61, &ljl_62, &ljl_63, &ljl_64, &ljl_65, &ljl_66, &ljl_67, &ljl_68, &ljl_69,
	&ljl_70, &ljl_71, &ljl_72, &ljl_73, &ljl_74, &ljl_75, &ljl_76, &ljl_77, &ljl_78, &ljl_79
};

/*
####################################################################################################################
====================================================================================================================
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
====================================================================================================================
####################################################################################################################
*/

typedef struct {
  double r;
  double g;
  double b;
} COLOR;

void bressenham_line ();

void plot();

void paint_pol();

void convert_utop();