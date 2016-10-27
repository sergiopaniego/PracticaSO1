#include "libreria.h"

int head(int N){
int lineas;
	char buf[1024];
  	int cuenta = 0;
	
	if(argc == 1)
	{
		lineas = 10;
	}
	else if (argc == 2)
	{
		char *num = argv[1] + 1;//Avanzamos una posición el puntero para saltar el caracter '-'. Recibe los argumentos con un '-'
		lineas = atoi(num);		
	}
	else
	{
		printf("Uso: \"%s -N\" para ver las N primeras líneas, o \"%s\" para las 10 primeras líneas\n", argv[0], argv[0]);
		return 1;
	}
	
  	
	while((cuenta < lineas) && (fgets(buf, 1024, stdin) != NULL))
	{//El fgets lee una línea. Como mucho la línea va a ser de 1024 caracteres, las lees de stdin y las almacenas en buf
	 //fgets devuelve un char*, si el char* vale null, ya no tiene más líneas que leer
	 //Si cambio las condiciones del while estaria leyendo solo una linea
	 //El and significa que si se cumple la primera condicion, hago la segunda (ejecucion perezosa)
	 //Control+D para acabar ejecucion
		printf("%s", buf);
		cuenta++;
	}
	
	return 0;
}
int tail(int N){}
int longlines(int N){}