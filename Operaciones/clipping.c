#include "clipping.h"

void clipping_x_max(PIX* lista_temp, PIX* apex_list, int i, int next_i){
    if (i < 0 || next_i < 0){
        return;
    }
    long double m, b;
    m = (long double)(apex_list[i].y - apex_list[next_i].y) / (long double)(apex_list[i].x - apex_list[next_i].x);
    b = apex_list[next_i].y - m*apex_list[next_i].x;
    if (apex_list[i].x > H_SIZE && apex_list[next_i].x > H_SIZE){ // OUT-OUT
    } else if (apex_list[i].x <= H_SIZE && apex_list[next_i].x <= H_SIZE){ // IN-IN
        lista_temp[counter].x = apex_list[next_i].x;
        lista_temp[counter].y = apex_list[next_i].y;
        counter++;
    } else if (apex_list[i].x <= H_SIZE && apex_list[next_i].x > H_SIZE) { // IN-OUT
        lista_temp[counter].x = H_SIZE;
        lista_temp[counter].y = apex_list[next_i].x*m + b;
        counter++;
    } else if (apex_list[i].x > H_SIZE && apex_list[next_i].x <= H_SIZE) { // OUT-IN
        lista_temp[counter].x = H_SIZE;
        lista_temp[counter].y = apex_list[next_i].x*m + b;
        counter++;
        lista_temp[counter].x = apex_list[next_i].x;
        lista_temp[counter].y = apex_list[next_i].y;
        counter++;
    }
}

void clipping_x_min(PIX* lista_temp, PIX* apex_list, int i, int next_i){
    if (i < 0 || next_i < 0){
        return;
    }
    long double m, b;
    m = (long double)(apex_list[i].y - apex_list[next_i].y) / (long double)(apex_list[i].x - apex_list[next_i].x);
    b = apex_list[next_i].y - m*apex_list[next_i].x;
    if (apex_list[i].x < 0 && apex_list[next_i].x < 0){ // OUT-OUT
    } else if (apex_list[i].x >= 0 && apex_list[next_i].x >= 0){ // IN-IN
        lista_temp[counter].x = apex_list[next_i].x;
        lista_temp[counter].y = apex_list[next_i].y;
        counter++;
    } else if (apex_list[i].x >= 0 && apex_list[next_i].x < 0) { // IN-OUT
        lista_temp[counter].x = 0;
        lista_temp[counter].y = apex_list[next_i].x*m + b;
        counter++;
    } else if (apex_list[i].x < 0 && apex_list[next_i].x >= 0) { // OUT-IN
        lista_temp[counter].x = 0;
        lista_temp[counter].y = apex_list[next_i].x*m + b;
        counter++;
        lista_temp[counter].x = apex_list[next_i].x;
        lista_temp[counter].y = apex_list[next_i].y;
        counter++;
    }
}

void clipping_y_max(PIX* lista_temp, PIX* apex_list, int i, int next_i){
    if (i < 0 || next_i < 0){
        return;
    }
    long double m, b;
    m = (long double)(apex_list[i].y - apex_list[next_i].y) / (long double)(apex_list[i].x - apex_list[next_i].x);
    b = apex_list[next_i].y - m*apex_list[next_i].x;
    if (apex_list[i].y > V_SIZE && apex_list[next_i].y > V_SIZE){ // OUT-OUT
    } else if (apex_list[i].y <= V_SIZE && apex_list[next_i].y <= V_SIZE){ // IN-IN
        lista_temp[counter].x = apex_list[next_i].x;
        lista_temp[counter].y = apex_list[next_i].y;
        counter++;
    } else if (apex_list[i].y <= V_SIZE && apex_list[next_i].y > V_SIZE) { // IN-OUT
        if (apex_list[i].x - apex_list[next_i].x == 0) {
            lista_temp[counter].x = apex_list[next_i].x;
        } else {
            lista_temp[counter].x = (int)((apex_list[next_i].y - b)/m); 
        }
        lista_temp[counter].y = V_SIZE;
        counter++;
    } else if (apex_list[i].y > V_SIZE && apex_list[next_i].y <= V_SIZE) { // OUT-IN
        if (apex_list[i].x - apex_list[next_i].x == 0) {
            lista_temp[counter].x = apex_list[next_i].x;
        } else {
            lista_temp[counter].x = (int)((apex_list[next_i].y - b)/m); 
        }
        lista_temp[counter].y = V_SIZE;
        counter++;
        if (apex_list[i].x - apex_list[next_i].x == 0) {
            lista_temp[counter].x = apex_list[next_i].x;
        } else {
            lista_temp[counter].x = (int)((apex_list[next_i].y - b)/m); 
        } 
        lista_temp[counter].y = V_SIZE;
        counter++;
    }
}

void clipping_y_min(PIX* lista_temp, PIX* apex_list, int i, int next_i){
    if (i < 0 || next_i < 0){
        return;
    }
    long double m, b;
    m = (long double)(apex_list[i].y - apex_list[next_i].y) / (long double)(apex_list[i].x - apex_list[next_i].x);
    b = apex_list[next_i].y - m*apex_list[next_i].x;
    if (apex_list[i].y < 0 && apex_list[next_i].y < 0){ // OUT-OUT
    } else if (apex_list[i].y >= 0 && apex_list[next_i].y >= 0){ // IN-IN
        lista_temp[counter].x = apex_list[next_i].x;
        lista_temp[counter].y = apex_list[next_i].y;
        counter++;
    } else if (apex_list[i].y >= 0 && apex_list[next_i].y < 0) { // IN-OUT
        if (apex_list[i].x - apex_list[next_i].x == 0) {
            lista_temp[counter].x = apex_list[next_i].x;
        } else {
            lista_temp[counter].x = (int)((apex_list[next_i].y - b)/m); 
        }
        lista_temp[counter].y = 0;
        counter++;
    } else if (apex_list[i].y < 0 && apex_list[next_i].y >= 0) { // OUT-IN
        if (apex_list[i].x - apex_list[next_i].x == 0) {
            lista_temp[counter].x = apex_list[next_i].x;
        } else {
            lista_temp[counter].x = (int)((apex_list[next_i].y - b)/m); 
        }
        lista_temp[counter].y = 0;
        counter++;
        if (apex_list[i].x - apex_list[next_i].x == 0) {
            lista_temp[counter].x = apex_list[next_i].x;
        } else {
            lista_temp[counter].x = (int)((apex_list[next_i].y - b)/m); 
        }
        lista_temp[counter].y = 0;
        counter++;
    }
}

PIX* clip_lines (PIX* apex_list, int size){
    int i;
    PIX* lista_temp = (PIX*)malloc(size * 2 * sizeof(PIX));
    
    for (i = 0; i < size; i++){
        lista_temp[i].x = -1;
        lista_temp[i].x = -1;
    }
    counter = 0;
    // borde x_max
    
    clipping_x_max(lista_temp, apex_list, size - 1, 0);
    for (i = 0; i < size-1; i++){
        clipping_x_max(lista_temp, apex_list, i, i+1);
    }
    lista_temp = (PIX*)realloc(lista_temp,counter * sizeof(PIX));

    // borde x_min
    PIX* lista_temp1 = (PIX*)malloc(counter * 2 * sizeof(PIX));
    size = counter;
    counter = 0;
    clipping_x_min(lista_temp1, lista_temp, size - 1, 0);
    for (i = 0; i < size-1; i++){
        clipping_x_min(lista_temp1, lista_temp, i, i+1);
    }
    lista_temp1 = (PIX*)realloc(lista_temp1,counter * sizeof(PIX));
    
    // borde y_max
    PIX* lista_temp2 = (PIX*)malloc(counter * 2 * sizeof(PIX));
    size = counter;
    counter = 0;
    clipping_y_max(lista_temp2, lista_temp1, size - 1, 0);
    for (i = 0; i < size-1; i++){
        clipping_y_max(lista_temp2, lista_temp1, i, i+1);
    }
    lista_temp2 = (PIX*)realloc(lista_temp2,counter * sizeof(PIX));

    // borde y_min
    PIX* lista_temp3 = (PIX*)malloc(counter * 2 * sizeof(PIX));
    size = counter;
    counter = 0;
    clipping_y_min(lista_temp3, lista_temp2, size - 1, 0);
    for (i = 0; i < size-1; i++){
        clipping_y_min(lista_temp3, lista_temp2, i, i+1);
    }
    lista_temp3 = (PIX*)realloc(lista_temp3, counter * sizeof(PIX));

    free(lista_temp);
    free(lista_temp1);
    free(lista_temp2);

    return lista_temp3;
}