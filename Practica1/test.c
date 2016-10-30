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
int main(int argc, char** argv) {
    
    //Funcion head(N);
    if (argc == 1) {
        head(10);
    } else if (argc == 2) {
        char *num = argv[1] + 1; //Avanzamos una posición el puntero para saltar el caracter '-'. Recibe los argumentos con un '-'
        head(atoi(num));
    } else {
        printf("Uso: \"%s -N\" para ver las N primeras líneas, o \"%s\" para las 10 primeras líneas\n", argv[0], argv[0]);
        return 1;
    }
/*   
    //Funcion tail(N);
    if (argc == 1) {
        tail(10);
    } else if (argc == 2) {
        char *num = argv[1] + 1; //Avanzamos una posición el puntero para saltar el caracter '-'. Recibe los argumentos con un '-'
        tail(atoi(num));
    } else {
        printf("Uso: \"%s -N\" para ver las N últimas líneas, o \"%s\" para las 10 ultimas líneas\n", argv[0], argv[0]);
        return 1;
    }
    
    //Funcion longlines(N);
    if (argc == 1) {
        longlines(10);
    } else if (argc == 2) {
        char *num = argv[1] + 1; //Avanzamos una posición el puntero para saltar el caracter '-'. Recibe los argumentos con un '-'
        longlines(atoi(num));
    } else {
        printf("Uso: \"%s -N\" para ver las N líneas más largas, o \"%s\" para las 10 líneas más largas\n", argv[0], argv[0]);
        return 1;
    }
 */
    return (EXIT_SUCCESS);
}

