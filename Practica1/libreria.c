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

void qs(char** lista,int limite_izq,int limite_der)
{
    int izq,der,pivote;
    char* temporal;

    izq=limite_izq;
    der = limite_der;
    pivote = strlen(lista[(izq+der)/2]);

    do{
        while(strlen(lista[izq])<pivote && izq<limite_der)izq++;
        while(pivote<strlen(lista[der]) && der > limite_izq)der--;
        if(izq >=der)
        {
            temporal= lista[izq];
            lista[izq]=lista[der];
            lista[der]=temporal;
            izq++;
            der--;

        }

    }while(izq >=der);
    if(limite_izq<der){qs(lista,limite_izq,der);}
    if(limite_der>izq){qs(lista,izq,limite_der);}
}

void quicksort(char** lista,int n)
{
    qs(lista,0,n-1);
}

int longlines(int N) {
    int nlineas;
    char buf[1024];
    int j=0;
    int linmin=0;
    //Asignamos las lineas a leer  
    nlineas=N;
    //Reservamos espacio para las N líneas
    char** lineas=(char**) malloc (N*sizeof(char*));
    int i;
    for( i=0;i<N;i++){
        lineas[i]=(char*) malloc (1024*sizeof(char*));
    }
    //Rellenamos el array con las líneas hasta que se vacie el buffer, recorriendolo entero
    
    //Primero rellenamos el array hasta que este lleno, luego ordenamos con quicksorts y vamos sustituyendo el último si procede
    while((fgets(buf,1024,stdin)!=NULL)){
        if(j<N){
            strcpy(lineas[j],buf);
            j++;     
        }else if(j==N){
            quicksort(lineas,sizeof(lineas));
            linmin=sizeof(lineas[N-1]);
            j++;
        }else{
            if(sizeof(buf)>sizeof(lineas[N-1])){
                strcpy(lineas[N-1],buf);
                quicksort(lineas,sizeof(lineas));
                linmin=sizeof(lineas[N-1]);
            }
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


