#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


/**
	Ejercicio 1 --------------------------------------------------------------
	Suma dos numeros y muestra el resultado
	por las dudas aunque no lo pedia retorno el resultado de la suma.
*/
int suma( const int *n1, const int *n2 );

/**
	Ejercicio 2 --------------------------------------------------------------
*/
float calcularPromedioNotas(const int *n1, const int *n2, const int *n3);

/**
	Ejercicio 3 --------------------------------------------------------------
*/
void carga(int *v, const int ce);
/**
	Ejercicio 4 --------------------------------------------------------------
*/

int copiarVector(int *v1, const int *v2, const int ce1, const int ce2);
/**
	Ejercicio 5 --------------------------------------------------------------
*/
void encontrarMax(int * v, int ce, int * mayor);
/**
	Ejercicio 6 --------------------------------------------------------------
*/
void contar(int *v, int ce, int *pares, int *impares);

/**
	Ejercicio 7 --------------------------------------------------------------
*/
void 	ingresarRecaudado	( float *rec, int dia, int cajera );
float 	recaudacionTotal	( float *rec );
int 	determinarPremio	( float total1, float total2 );
void 	mostrarDiaMenor		( int cajera, int diaMenor );

/**
	Ejercicio 8 --------------------------------------------------------------
*/
char ultimoCaracter(char *);


/**
	Ejercicio 9 --------------------------------------------------------------
*/

int letras(char *);


/**
	Ejercicio 10 --------------------------------------------------------------
*/
int cantidad(char *, int);


/**
	Ejercicio 11 --------------------------------------------------------------
*/
char *rev(char *);
char * a_cadena(char *, int);


/**
	Ejercicio 12 --------------------------------------------------------------
*/
char * concat(char *s1, char *);
char *saludar(char *);
