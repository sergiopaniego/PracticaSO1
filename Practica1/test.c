/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: sergiopaniegoblanco
 *
 * Created on October 27, 2016, 2:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
/*
 * 
 */
int isHead(char *ce);
int isTail(char *ce);
int isLonglines(char *ce);

int main(int argc, char** argv) {
    
    if (argc == 2) {
        //Comprobamos a que metodo pertenece y pintamos 10 lineas
        if(isHead(argv[1])){
            head(10);
        }else if(isTail(argv[1])){
            tail(10);
        }else if(isLonglines(argv[1])){
            longlines(10);
        }else {
            printf("Uso: \"%s -nombreFuncion -N\" para ver N líneas, o \"%s -nombreFuncion\" para ver 10 líneas\n", argv[0], argv[0]);
            return 1;
        }
    } else if (argc == 3) {
        char *num = argv[2] + 1; //Avanzamos una posición el puntero para saltar el caracter '-'. Recibe los argumentos con un '-'
        //Comprobamos a que metodo pertenece y pintamos N lineas
        if(isHead(argv[1])){
            head(atoi(num));
        }else if(isTail(argv[1])){
            tail(atoi(num));
        }else if(isLonglines(argv[1])){
            longlines(atoi(num));
        }else {
            printf("Uso: \"%s -nombreFuncion -N\" para ver N líneas, o \"%s -nombreFuncion\" para ver 10 líneas\n", argv[0], argv[0]);
            return 1;
        }
    } else {
        printf("Uso: \"%s -nombreFuncion -N\" para ver N líneas, o \"%s -nombreFuncion\" para ver 10 líneas\n", argv[0], argv[0]);
        return 1;
    }

    
    return (EXIT_SUCCESS);
}

int isHead(char *ce){
    char *num0=ce+1;
    char *num1=ce+2;
    char *num2=ce+3;
    char *num3=ce+4;
    
    return (*num0=='h')&&(*num1=='e')&&(*num2=='a')&&(*num3=='d');
}

int isTail(char *ce){
    char *num0=ce+1;
    char *num1=ce+2;
    char *num2=ce+3;
    char *num3=ce+4;
    
    return (*num0=='t')&&(*num1=='a')&&(*num2=='i')&&(*num3=='l');
}

int isLonglines(char *ce){
    char *num0=ce+1;
    char *num1=ce+2;
    char *num2=ce+3;
    char *num3=ce+4;
    char *num4=ce+5;
    char *num5=ce+6;
    char *num6=ce+7;
    char *num7=ce+8;
    char *num8=ce+9;
    
    return (*num0=='l')&&(*num1=='o')&&(*num2=='n')&&(*num3=='g')&&(*num4=='l')&&(*num5=='i')&&(*num6=='n')&&(*num7=='e')&&(*num8=='s');
}



