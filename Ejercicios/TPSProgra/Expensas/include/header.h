#include <stdio.h>
#include <stdlib.h>


// Validar el char ingresado con la categoria
#define PISO(X)		( (X) == 'p' || (X) == 'P' )
#define SEMI_PISO(X)( (X) == 's' || (X) == 'S' )
#define DOS_AMB(X)	( (X) == 'd' || (X) == 'D' )
#define MONO_AMB(X)	( (X) == 'm' || (X) == 'M' )


// Montos por categoria
#define MONTO_PISO 			4000
#define MONTO_SEMI_PISO 	3000
#define MONTO_DOS_AMB 		2000
#define MONTO_MONO_AMB 		1000

// Montos por usos
#define MONTO_COCHERA 		1500
#define MONTO_PROFESIONAL 	2500


#define ES_PROFESIONAL(X) ( (X) == 1 )

#define COND_FIN(X) ( (X) == 's' || (X) == 'S' )

/*
*	Funciones pedidad en el enunciado
*/
void mostrarResultadoFinal(int);
float montoExpensas(const char, const int, const char);
void mostrarGastosDepto(int, float);

/*
*	Funciones Utilitarias
*/
void titulo(const char * t);
char condicionFin ();
void ingresarDatosEntrada (int *, char *, int *, char *, char *);
float ingresarMontoMultas();



