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
    int i;
    for( i=0; i<N; i++){
        lineas[i]=(char*) malloc (1024*sizeof(char));
    }
    //Nos quedamos con las últimas N lineas despues de la lectura de todas las que se nos pasan
    while ((fgets(buf, 1024, stdin) != NULL)) {        
        if(j<N){
        strcpy(lineas[j], buf);
        j++;  
        }else{
        int x;
            for( x=0; x<N-1; x++){
                strcpy(lineas[x], lineas[x+1]);
            }
            strcpy(lineas[N-1], buf);
        }
    }
    //Imprimimos el resultado por consola
    int k;
    for( k=0; k<N; k++){
        printf("%s", lineas[k]);
    }
    //Liberamos la memoria utilizada
    for( i=0; i<N; i++){
        free(lineas[i]);
    }
    free(lineas);
    
    return 0;
    
}

int longlines(int N) {
    int nlineas;
    char buf[1024];
    int cont=0;
    int linmin=0;
    //Asignamos las lineas a leer  
    nlineas=N;
    //Reservamos espacio para las N líneas
    char** lineas=(char**) malloc (N*sizeof(char*));
    int i;
    for( i=0;i<N;i++){
        lineas[i]=(char*) malloc (1024*sizeof(char*));
    }
    char* aux=(char*) malloc (1024*sizeof(char*));
    //Rellenamos el array con las líneas hasta que se vacie el buffer, recorriendolo entero
    
    //Primero rellenamos el array hasta que este lleno, luego ordenamos con quicksorts y vamos sustituyendo el último si procede
    while((fgets(buf,1024,stdin)!=NULL)){
        //Metemos las primeras N lineas
        if(cont<N){
            strcpy(lineas[cont],buf);
            cont++;     
        }else{
            //Comprobamos si la linea que leemos es mas larga que la mas corta de las que tenemos
                if(strlen(buf)>strlen(lineas[N-1])){
                    strcpy(lineas[N-1], buf);
                }
                //Reordenamos las lineas
                int i, j;
            for(i=0; i<N-1; i++){
                for(j=0; j<N-1; j++){
                    if(strlen(lineas[j])<strlen(lineas[j+1])){
                        strcpy(aux, lineas[j]);
                        strcpy(lineas[j], lineas[j+1]);
                        strcpy(lineas[j+1], aux);                     
                    }
                }
            }
            
        }
    }
    //Volvemos a ordenar las lineas por si se introducen mas lineas de las que disponemos
    int x, y;
    for(x=0; x<N-1; x++){
                for(y=0; y<N-1; y++){
                    if(strlen(lineas[y])<strlen(lineas[y+1])){
                        strcpy(aux, lineas[y]);
                        strcpy(lineas[y], lineas[y+1]);
                        strcpy(lineas[y+1], aux);                     
                    }
                }
            }
    
    free(aux);
    //Imprimimos el resultado por consola
    int k;
    for( k=0; k<N; k++){
        printf("%s", lineas[k]);
    }
    //Liberamos la memoria utilizada
    for( i=0; i<N; i++){
        free(lineas[i]);
    }
    free(lineas);
    return 0;
}


