#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>

int head(int N) {
    int lineas;
    char buf[1024];
    int cuenta = 0;
    
    //Asignamos las lineas a leer  
    lineas=N;

    while ((cuenta < lineas) && (fgets(buf, 1024, stdin) != NULL)) {
        //Imprimimos por pantalla las N primeras lineas
        printf("%s", buf);
        cuenta++;
    }

    return 0;
}

int tail(int N) {
    int lineas;
    char buf[1024];
    int cuenta = 0;
    //Asignamos las lineas a leer  
    lineas=N;
    
    /*while ((cuenta < lineas) && (fgets(buf, 1024, stdin) != NULL)) {
        //Imprimimos por pantalla las N primeras lineas
        
        printf("%s", buf);
        cuenta++;
    }

    return 0;*/
    
}

int longlines(int N) {
    int lineas;
    char buf[1024];
    int cuenta = 0;
    
    //Asignamos las lineas a leer  
    lineas=N;
}