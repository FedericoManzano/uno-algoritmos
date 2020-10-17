#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// Si X >= 1 && X <= 5 Verdadero valor != de 0
// Si X < 1  || X > 5  Falso valor = de 0
#define LUN_A_VIE(X)( (X) >= 1 && (X) <= 5 )

// Si X es 1 o 2 o 3 o 4 o 5 o 6 o 7 devuelve Verdadero
// Caso contrario Falso
#define DIA_SEMANA(X)((X) == 1 || (X) == 2 || (X) == 3 || (X) == 4 || (X) == 5 || (X) == 6 || (X) == 7 )

// X es 'a' || 'A' retorna verdadero
// Caso contrario retorna falso
#define ES_PICO(X)( (X) == 'a' || (X) == 'A' )

// valida que el horario sea correcto 'a' o 'A' o 'p' o 'P' Verdadero
// Caso contrario falso
#define HORARIO_VAL(X) ( (X) == 'a' || (X) == 'A' || (X) == 'b' || (X) == 'B')

// Cuando X sea distinto de 's' y distinto de 'S' Veradero
// Caso contrario falso
#define COND_FIN(X) ( (X) != 'S' && (X) != 's' )

// Precio base de las motos
#define BASE_MOTO 		5

// Precio base de las autos
#define BASE_AUTO 		10

// Precio base de las camionetas
#define BASE_CAMIONETA 	15

// Precio base de las camiones
#define BASE_CAMION 	20 

/**
	Limpia la pantalla y muestra un titulo en la parte 
	superior de la misma.
*/
void titulo(const char *tit);

/**
	Devuelve un char con la elección del usuario
	de seguir cargando pases de peaje o no.
*/
char condicionFin();

/**
	Devuelve el precio base segun la cateforia
*/
float obtenerBase(char *);


/**
* Funciones pedidas por el enunciado
*/
float calcularImporte (const float, const int, const char);
float calcularVuelto ( const float, const float );
void mostarImporte ( const float , const float );


/**
	Muestra el resultado general 
	total en pesos de pasajes vendidos
	y cantidad de autos en hora pico
*/
void mostarResultados (const float, const int);



