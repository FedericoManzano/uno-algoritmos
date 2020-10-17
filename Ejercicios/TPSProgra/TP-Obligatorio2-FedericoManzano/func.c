 
 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <string.h>
 
 #define OK 1
 #define NO 0
 
 #define ES_POSITIVO(X)((X) >= 0) // Valor positivo 
 #define COND_FIN(X)((X) == 'S' || (X) == 's') // Verdadero si X es s o S
 
int valPartidosGanados( const int, const int );
int valCantTriples(const int);
int valCantInfracciones( const int );
void mostrarResultados( const int, const int );
int calcularGanador(int, int *, int , int , int *);
void ingresarNombreEquipo(char *);
void ingresarDatosEntrada(int *, char *, int *, int *, int *, int *);
char pedirCondicionFin(char mje[]);
int ingresarValorEntero(char *);
int definirDesempeno (const int, const int, const int, const int, const char *);
 
 
 /************************************************************************************
 	Funciones pedidas en el enunciado
 ************************************************************************************/
 
 // Si la cantidad de partidos ganados es mayor a la de perdidos 
 // retorna OK = 1 caso contrario NO = 0 
 // OK y NO son macros efinidas en el archivo include.h
 int valPartidosGanados( const int cGanados, const int cPerdidios ) {
 	return cGanados > cPerdidios ? OK : NO;
 }
 
 
 // Si la cantidad de triples en todo el torneo supera a 20
 // retorna 1 caso contrario 0
 int valCantTriples(const int cantTriples) {
 	return cantTriples > 20 ? OK : NO;
 }
 
 // Si la cantidad de infracciones en todo el torneo es menor a 10
 // retorna 1 caso contrario 0
 int valCantInfracciones( const int cInfracciones ) {
 	return cInfracciones < 10 ? OK : NO;
 }
 
 // Muestra los resultados finales del ejercicio
 void mostrarResultados( const int equipoGanador, const int cantEquiposAMejorar ) {
 	system("cls");
 	printf("\n\n\t\t******************************************* \n");
 	printf("\n\n\t\tEquipo Ganaor: %d \n", equipoGanador);
 	printf("\n\n\t\tCantidad de equipos de bajo rendimiento: %d \n\n", cantEquiposAMejorar);
 	printf("\n\n\t\t******************************************* \n\n");
 	system("pause");
 }
 
 
 
 int calcularGanador(int codMax, int *diferenciaMax, int diferencia, int codigo, int *bandera) {
 	if(*bandera == 1) {
		codMax = codigo;
		*diferenciaMax = diferencia;
		*bandera = 0;
	} else if( *diferenciaMax < diferencia) {
		*diferenciaMax = diferencia;
		codMax = codigo;
	}
	return codMax;
  }
 
 /**************************************************************************************************/
 
 
  // Recibe un puntero al primer elemento de la cadena 
 // de caracteres definida en el main y la carga 
 // con el nombre del equipo. 
 void ingresarNombreEquipo(char * nombre) {
 	printf("Ingrese el nombre del equipo: ");
 	fflush(stdin);
 	gets(nombre);
 }
 
 
 void ingresarDatosEntrada(int * codEquipo, char * nombre, int * cantVictorias, int * cantDerrotas, int * cantTriples, int * cantInfracciones) {
 	*codEquipo = ingresarValorEntero("Ingrese el codigo del equipo: ");
	ingresarNombreEquipo(nombre);
	*cantVictorias = ingresarValorEntero("Ingrese la cantidad de victorias: ");
	*cantDerrotas = ingresarValorEntero("Ingrese la cantidad de derrotas: ");
	*cantTriples = ingresarValorEntero("Ingrese la cantidad de triples: ");
	*cantInfracciones = ingresarValorEntero("Ingrese la cantidad de infracciones: ");	
 }
 
 /** 
 	Ingresa la condición de fin 
 */
 char pedirCondicionFin(char mje[]) {
 	char cond;
 	printf("%s: ", mje);
 	fflush(stdin);
 	scanf("%c",&cond);
 	return cond;
 }

  
  // Función de validación 
  // Solamente deja pasar los valores enteros positivos
  // En el caso del problema es importante que dichos valores 
  // sean positivos.
  int ingresarValorEntero(char * mje) {
  	int entero;
 	do {
 		printf(mje);
 		scanf("%d", &entero);	
	} while(!ES_POSITIVO(entero));
 	
 	return entero;
  }
 
 // Calcula el codigo del equipo que posee una diferencia entre partidos ganados 
 // y perdidos mayor. 
 int definirDesempeno (const int cantVictorias, const int cantDerrotas, const int cantTriples, const int cantInfracciones, const char *nombre) {
 	if(
		valPartidosGanados(cantVictorias, cantDerrotas) &&  
		valCantTriples(cantTriples) 					&& 
		valCantInfracciones(cantInfracciones)
	) {
		printf( "\n\t Buen Desempeño !! %s \n\n", nombre );
		return 1;
	}
	printf( "\n\t Mal Desempeño debe mejorar !! %s \n\n ", nombre );
	return 0;
 }

