#include "libreria.h"
#include <stdio.h>
#include <string.h>
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
    int nlineas;
    char buf[1024];
    int j=0;
    //Asignamos las lineas a leer   
    nlineas=N;
    //Reservamos espacio para las N lineas
    char ** lineas = (char**) malloc (N*sizeof(char*));
    
    for(int i=0; i<N; i++){
        lineas[i]=(char*) malloc (1024*sizeof(char));
    }
    //Nos quedamos con las últimas N lineas despues de la lectura de todas las que se nos pasan
    while ((fgets(buf, 1024, stdin) != NULL)) {        
        if(j<N){
        strcpy(lineas[j], buf);
        j++;  
        }else{
            for(int x=0; x<N-1; x++){
                strcpy(lineas[x], lineas[x+1]);
            }
            strcpy(lineas[N-1], buf);
        }
    }
    //Imprimimos el resultado por consola
    for(int k=0; k<N; k++){
        printf("%s", lineas[k]);
    }
    //Liberamos la memoria utilizada
    for(int i=0; i<N; i++){
        free(lineas[i]);
    }
    free(lineas);
    
    return 0;
    
}

int longlines(int N) {
    int lineas;
    char buf[1024];
    int cuenta = 0;
    
    //Asignamos las lineas a leer  
    lineas=N;
}