#include "../include/header.h"
#include "../include/utilitarios.h"
#include "../include/menu.h"



void numeroPares() {
	int pares[50];
	int indicePar = 0, i;
	
	titulo("Pares entre 1 y 100");
	for(i = 2; i <= 100; i += 2) {
		pares[indicePar] = i;
		indicePar ++;
	}
	printf("%s %s\n","Numero", "Valor");
	for(i = 0; i < 50; i ++) 
		printf("%-7d pares[%d]=%d\n",i + 1,  i, pares[i]);
	pausar();
}

void sumResMulDiv() {
	int op[10];
	int i;
	titulo("Opraciones Matematicas");
	pedirVertorEnteros(op,10);
	titulo("Resultados");
	mostrarArregloEnteros(op, 10);
	printf("El resultado de la suma es: %d\n", sumaVectorEnteros(op,10));
	printf("El resultado de la resta es: %d\n", restaVectorEnteros(op,10));
	printf("El resultado de la multiplicacion es: %ld\n", mulVectorEnteros(op,10));
	printf("El resultado de la division es: %f\n", divVectorEnteros(op,10));
	pausar();
}

void mostrarInvertido() {
	int inv[10];
	int i;
	titulo("Arreglo invertido");
	pedirVertorEnteros(inv,10);
	titulo("Arreglo invertido");
	mostrarArregloEnteros(inv, 10);
	for(i = 9; i >= 0; i -- ) 
		printf("inv[%d]=%d\n", i, inv[i]);
	pausar();
}



void mostrarMenorMayor() {
	int mayMen[10];
	int i;
	titulo("Mayor, Menor, Pares");
	pedirVertorEnteros(mayMen,10);
	titulo("Pares, Mayor y Menor");
	mostrarArregloEnteros(mayMen, 10);
	printf("Pares: %d\n", cantPares(mayMen,10));
	printf("Menor: %d\n", mayMen[indiceMenorVector(mayMen,10)]);
	printf("Mayor: %d\n", mayMen[indiceMayorVector(mayMen,10)]);
	pausar();
}


void mostrarBusquedaNumero() {
	int busqueda[10];
	int i, nro, estaNumero = 0;
	titulo("Busqueda de numero");
	pedirVertorEnteros(busqueda,10);
	printf("Ingresar el numero a buscar: ");
	scanf("%d", &nro);
	titulo("Resultado de la busqueda");
	mostrarArregloEnteros(busqueda, 10);
	for(i = 0; i < 10; i ++)
		if(nro == busqueda[i])
			estaNumero = 1;
	if(estaNumero )
		printf("El numero %d esta el el vector", nro);
	else
		printf("El numero %d no esta el el vector", nro);
		
	pausar();
}

void mostrarCantMaySeis() {
	int notas[10];
	int i, cantidad = 0;
	titulo("Cantidad de notas mayores que 6");
	pedirVertorEnteros(notas,5);
	for(i = 0; i < 5; i ++)
		if(notas[i] > 6)
			cantidad ++;
	titulo("Resultado");
	mostrarArregloEnteros(notas, 5);
	printf("La cantidad de notas mayores a 6 es %d", cantidad);
	pausar();
}

void mostarPromedioPorcentaje () {
	int arr[20] = {	5,	-9,	 -5,
					3,	 4,	 -8,
					2,8,5,-9,
					-5,9,-5,
					3,4,-8,
					2,8,5,9
	};

	int acum = 0, cantidadPositivos = 0, cantidadNegativos = 0, i;
	
	titulo("Positivos y Negativos");
	
	for(i = 0; i < 20; i ++) {
		if(arr[i] > 0) {
			cantidadPositivos ++;
			acum += arr[i];
		}
			
		if(arr[i] < 0) 
			cantidadNegativos ++;
	}
	mostrarArregloEnteros(arr, 20);
	
	if(cantidadPositivos > 0)
		printf("El promedio de positivos es %.2f\n", (float)acum / cantidadPositivos);
	else
		printf("No hay positivos\n");
	
	if(cantidadNegativos > 0) 
		printf("El porcentaje de negativos es %.2f\n", (float)cantidadNegativos * 100 / 20);
	else
		printf("No hay negativos\n");
	pausar();
}


void mostrarMaxMinIndices () {
	int arr[10];
	int indiceMayor, indiceMenor;
	titulo("Maximos, Minimos, Indices");
	pedirVertorEnteros(arr,10);
	
	titulo("Resultados");
	indiceMayor = indiceMayorVector(arr,10);
	indiceMenor = indiceMenorVector(arr, 10);
	mostrarArregloEnteros(arr,10);
	
	printf("El maximo es %d en la posicion %d\n", arr[indiceMayor], indiceMayor);
	printf("El minimo es %d en la posicion %d\n", arr[indiceMenor], indiceMenor);
	
	pausar();
	
}

void mostrarPromedioProducto () {
	int arr[20], producto;
	float promedio;
	
	titulo("Promedio y Producto");
	pedirVertorEnteros(arr,20);
	
	promedio = (float)sumaVectorEnteros(arr,20) / 20;
	producto = mulVectorEnteros(arr, 20);
	
	titulo("Resultados");
	mostrarArregloEnteros(arr,20);

	printf("El promedio de los valores es %.2f\n", promedio);
	printf("El producto de los valores es %d\n", producto);
	
	pausar();
}

void mostrarInvertidoMitad () {
	int arr[200], med, i, aux, n;

	titulo("Promedio y Producto");
	
	printf("Ingrese la cantidad de elementos: ");
	scanf("%d", &n);
	pedirVertorEnteros(arr,n);
	
	titulo("Resultados");
	printf("Arreglo original n = %d\n", n);
	mostrarArregloEnteros(arr,n);

	
	if(n % 2 == 0) {
		med = n / 2 - 1;
		for (i = 0; i < n / 3; i ++) {
			aux = arr[i];
			arr[i] = arr[med];
			arr[med] = aux;
			med --;
		}
	}
	printf("Arreglo cambiado n = %d\n", n);
	mostrarArregloEnteros(arr,n);
	pausar();
}

void mostrarNombreEdad() {
	char nombre[15];
	int edad;
	titulo("Nombre y Edad");
	printf("Ingrese su nombre: ");
	fflush(stdin);
	scanf("%s", nombre);
	printf("Ingrese su edad: ");
	scanf("%d", &edad);
	titulo("Resultados");
	printf("Nombre: %s Edad: %d", nombre, edad);
	pausar();
}

void mostrarMayorMatriz () {
	int mat[3][3], mayor, fila;
	
	titulo("Mayor Fila Matriz");
	leerMatriz(mat, 3,3);
	titulo("Matriz");
	mostrarMatriz(mat, 3,3);
	printf("\nIngrese la fila (1,2,3): ");
	scanf("%d", &fila);
	mayor = calcularMayorMatriz(mat, fila, 3);
	printf("El valor mayor de la fila %d es: %d", fila, mayor);
	pausar();
}


void contarConsVocales () {
	char palabra[20];
	int i = 0, cantVoc = 0, cantCon = 0;
	titulo("Vocales Consonantes");
	printf("Ingrese la palabra: ");
	fflush(stdin);
	scanf("%s", palabra);
	while(palabra[i] != '\0'){
		if(esVocal(palabra[i]))
			cantVoc ++;
		else 
			cantCon ++;
		i ++;
	}
	titulo("Resultado");
	printf("Cantidad de vocales: %d\n", cantVoc );
	printf("Cantidad de consonantes: %d\n", cantCon );
	pausar();
}

void palabrasIguales () {
	char palabra1[20], palabra2[20];
	int i = 0;
	titulo("Palabras iguales");
	
	
	printf("Ingrese la palabra 1: ");
	fflush(stdin);
	scanf("%s", palabra1);
	
	printf("Ingrese la palabra 2: ");
	fflush(stdin);
	scanf("%s", palabra2);
	
	while( palabra1[i] && palabra2[i] && palabra1[i] == palabra2[i] ) 
		i ++;
	
	titulo("Resultados");
	
	printf("Palabra1 %s\n", palabra1);
	printf("Palabra2 %s\n", palabra2);
	
	
	if( palabra1[i] == palabra2[i] )
		printf("SON IGUALES\n");
	else 
		printf("SON DISTINTAS\n");
	
	pausar();
	
	titulo("Simulacion strcmp<string.h>");
	
	
	if(!str_cmp(palabra1, palabra2))
		printf("SON IGUALES\n");
	else 
		printf("SON DISTINTAS\n");
		
	pausar();
}

void opracionesMatrices() {
	int mat1 [3][3], mat2 [3][3], res [3][3];
	char op;
	t_menu menu;
	char opciones[3][TAM_MENU] = {
		"Sumar Matrices",
		"Multiplicar Matrices",
		"Salir"
	};
	
	titulo("Operaciones Matrices");
	
	crearMenu(&menu,opciones,"AMS","Operaciones Matrices", "Ingrese Operacion", "Err ingrese nuevamente", "<>");
	
	printf("Ingrese la primera matriz\n\n");
	leerMatriz(mat1,3,3);
	
	printf("\n\nIngrese la segunda matriz\n\n");
	leerMatriz(mat2, 3,3);
	
	do {
		op = seleccionarOpcion(&menu);
		switch(op) {
			case 'A': sumarMatrices( mat1, mat2, 3 );
				break;
			case 'M': multiplicarMatrices( (int *)mat1, (int *)mat2,3);
				break; 
		}
	}while(op != 'S');
}

void mostrarCantidadLetras() {
	char palabra[20];
	int cantidad = 0, i = 0;
	
	titulo("Cantidad letras");
	
	printf("Ingrese una palabra: ");
	fflush(stdin);
	scanf("%s", palabra);
	
	while(palabra[i]) {
		i ++;
		cantidad ++;
	}
		

	titulo("Resultado");
	
	printf("La palabra es %s\n", palabra);
	printf("Cantidad de letras %d", cantidad);
	
	pausar();
}



void mostrarAcuPosNeg () {
	int mat[3][3];
	int acumPos = 0, acumNeg = 0, i, j;
	
	
	
	titulo("Sumatoria positivos y negativos");
	leerMatriz(mat, 3, 3);
	
	for(i = 0; i < 3; i ++) {
		for(j = 0; j < 3; j ++) {
			if(mat[i][j] > 0)
				acumPos += mat[i][j];
			else if(mat[i][j] < 0)
				acumNeg += mat[i][j];
		}
	}
	
	
	titulo("Matriz");
	mostrarMatriz(mat, 3,3);
	printf("La sumatoria de positivos es %d\n", acumPos);
	printf("La sumatoria de negativos es %d\n", acumNeg);
	
	pausar();
}

void mostrarMayorMenorMatriz () {
	int mat[4][3];
	int i,j;
	
	int filMay, filMin, colMay, colMin;
	int bandera = 1;
	
	
	titulo("Mayor y Menor");
	leerMatriz(mat,4,3);
	titulo("Matriz");
	mostrarMatriz(mat,4,3);
	
	for(i = 0; i < 4; i ++) {
		for(j = 0; j < 3; j ++) {
			if(bandera) {
				filMay = i;
				colMay = j;
				filMin = i;
				colMin = j;
				bandera = 0;
			}
			if(mat[filMay][colMay] < mat[i][j]) {
				filMay = i;
				colMay = j;
			}
			if(mat[filMin][colMin] > mat[i][j]) {
				filMin = i;
				colMin = j;
			}
		}
	}
	titulo("Matriz");
	mostrarMatriz(mat,4,3);
	printf("El mayor valor de la matriz es %d (%d, %d)\n", mat[filMay][colMay], filMay + 1, colMay + 1);
	printf("El menor valor de la matriz es %d (%d, %d)\n", mat[filMin][colMin], filMin + 1, colMin + 1);
	pausar();
}


void calcularVendedores () {
	char nombres[25][20] = {""};
	int codigos[25] = 
	{
		100,101,102,103,104,105,106,107,108,
		109,110,111,112,113,114,115,116,117,
		118,119,120,124,122,123,124
	};
	float montos[25] = {0};
	
	
	int codigo, indice, i;
	float monto;
	char nombre[20], op;
	
	titulo("Ingreso de empleados");
	
	printf("Desea cargar una operacion de un vendedor (s/n): ");
	fflush(stdin);
	scanf("%c", &op);
	
	while( op == 'S' || op == 's' ) {
		
		
		printf("Ingresar el codigo del vendedor (100 al 124): ");
		fflush(stdin);
		scanf("%d", &codigo);
	
		if((indice = buscarCodigoVenddor(codigos, codigo)) >= 0) {
			printf("Ingresar el nombre del vendedor: ");
			fflush(stdin);
			scanf("%s", nombre);
			strcpy(nombres[indice], nombre);
			printf("Ingresar el monto: ");
			fflush(stdin);
			scanf("%f", &monto);
			montos[indice] +=  monto;
		} else {
			printf("El codigo ingresado no existe ...");
			pausar();
		}
		titulo("Ingreso de empleados");
		printf("Desea cargar una operacion de un vendedor (s/n): ");
		fflush(stdin);
		scanf("%c", &op);
	}
	
	
	titulo("Totales");
	printf("%-10s%-20s%-8s\n", "CODIGO", "NOMBRES", "TOTALES");
	
	for(i = 0; i < 25; i ++) 
		if(montos[i] > 0) 
			printf("%-10d%-20s%-.2f\n", codigos[i], nombres[i], montos[i]);
	pausar();
}

int comparar_int(const void *e1, const void *e2) {
	int * ele1 = (int *) e1;
	int * ele2 = (int *) e2;
	return  *ele1 -  *ele2;
}



void mostrarOrdenado() {
	int arr[20], producto;
	float promedio;
	
	titulo("Ordenar Vector 10 Elementos");
	pedirVertorEnteros(arr,10);
	titulo("Sin ordenar / Ordenado");
	mostrarArregloEnteros(arr,10);
	q_sort(arr, 10, sizeof(int), comparar_int);
	mostrarArregloEnteros(arr,10);
	pausar();
	
}
