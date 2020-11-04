#include <pba.h>


void titulo( const char * titulo) {
	system("cls");
	printf("\n\t\t\t\t%s\n\n", titulo);
}

void pausar() {
	printf("\n\n");
	system("pause");
}

void mostrarVector(int *v, int ce) {
	int i;
	printf("\n\n[ ");
	for(i = 0; i < ce; i ++) 
		printf("%d, ", v[i]);
	printf("] \n");
}

int ingresarValorEntero( const char *mje) {
	int a;
	printf(mje);
	scanf("%d", &a);
	return a;
}


void pbaEjercicio1() {
	int a, b; 
	titulo("Suma de valores");
	a = ingresarValorEntero("Ingrese el primer valor: ");
	b = ingresarValorEntero("Ingrese el segundo valor: ");
	suma(&a, &b);
	pausar();
}

void pbaEjercicio2() {
	int n1,n2,n3;
	titulo("Promedio de notas");
	n1 = ingresarValorEntero("Ingrese la nota 1: ");
	n2 = ingresarValorEntero("Ingrese la nota 2: ");
	n3 = ingresarValorEntero("Ingrese la nota 3: ");
	printf("\n\nEl promedio del alumno es: %.2f\n", calcularPromedioNotas(&n1, &n2, &n3));
	pausar();
}

void pbaEjercicio3() {
	int vector[10], i;
	titulo("Carga Vector");
	
	
	carga(vector, 10);
	
	
	printf("\n\n[ ");
	
	
	for(i = 0; i < 10; i ++) 
		printf("%d, ", vector[i]);
	printf("] \n");
	pausar();
}

void pbaEjercicio4 () {
	int v1[10];
	int v2[10] = {15,2,54,1,3,9,8,7,5,2};
	titulo("Copiar Vector");
	
	if(copiarVector(v1,v2,10,10)) {
		mostrarVector(v1, 10);
		mostrarVector(v2, 10);
	} else 
		printf("\n\n No pudo realizarse la copia\n");
	
	pausar();
	
}


void pbaEjercicio5() {
	int vector[10], mayor;
	titulo("Carga Vector");
	carga(vector, 10);
	encontrarMax(vector, 10, &mayor);
	mostrarVector(vector, 10);
	printf("El mayor valor es %d", mayor);
	pausar();
}


void pbaEjercicio6() {
	int vector[100], pares = 0, impares = 0, i;
	titulo("Pares Impares");
	for(i = 0; i < 100; i ++) 
		vector[i] = rand() % 10;
		
	contar(vector, 100, &pares, &impares);
	mostrarVector(vector, 100);
	
	printf("\nLa cantidad de pares es %d\n", pares);
	printf("La cantidad de impares es %d", impares);
	pausar();
}

void pbaEjercicio7() {
	float ventas1[7], totalRecaudado1;
	float ventas2[7], totalRecaudado2;
	int dia = 0;
	int premio, diaMenorCaj1, diaMenorCaj2; 
	
	
	titulo("Cajeras");
	while(dia < 7) {
		ingresarRecaudado(ventas1, dia, 1);
		ingresarRecaudado(ventas2, dia, 2);
		dia ++;
	}
	
	
	totalRecaudado1 = recaudacionTotal(ventas1);
	totalRecaudado2 = recaudacionTotal(ventas2);
	premio = determinarPremio(totalRecaudado1, totalRecaudado2);
	
	
	diaMenorCaj1 = menorVenta(ventas1);
	diaMenorCaj2 = menorVenta(ventas2);
	titulo("Cajeras");
	
	printf(" *** Totales *** \n");
	printf("El total recaudado por la cajera 1 es %.2f\n", totalRecaudado1);
	printf("El total recaudado por la cajera 2 es %.2f\n\n", totalRecaudado2);
	
	printf(" *** Premio *** \n");
	if(premio != 0)
		printf("La cajera que gana el premio es la cajera  %d\n\n", premio);
	else
		printf("Ambas reciben premio tienen las mismas recaudaciones\n\n", premio);
		
	printf(" *** Dia Menor Venta *** \n");	
	mostrarDiaMenor(1, diaMenorCaj1 + 1);
	mostrarDiaMenor(2, diaMenorCaj2 + 1);
	
	pausar();
}

void pbaEjercicio8() {
	char cad[11];
	titulo("Ultimo caracter");
	
	printf("Ingrese una cadena de texto: ");
	fflush(stdin);
	gets(cad);
	titulo("Resultado");
	printf("El ultimo caracter es %c", ultimoCaracter(cad));
	pausar();
}

void pbaEjercicio9() {
	char cad[11];
	titulo("Cantidad de caracteres");
	
	printf("Ingrese una cadena de texto: ");
	fflush(stdin);
	gets(cad);
	titulo("Resultado");
	printf("La cadena %s tiene %d catacteres", cad, letras(cad));
	pausar();
}



void pbaEjercicio10() {
	char cad[11];
	int cant;
	titulo("Comparar cantidades");
	
	printf("Ingrese una cadena de texto: ");
	fflush(stdin);
	gets(cad);
	
	printf("Ingrese la cantidad: ");
	fflush(stdin);
	scanf("%d", &cant);
	
	titulo("Resultado");
	if(cantidad(cad, cant)) 
		printf("La cadena tiene la misma cantidad de caracteres que el valor ingresado\n");
	else 
		printf("La cantidad no es igual al valor ingresado\n");
	
	
	pausar();
}


void pbaEjercicio11() {
	char cad[20];
	int num;
	titulo("Entero a cadena");
	printf("Ingrese la cantidad: ");
	scanf("%d", &num);
	titulo("Resultado");
	printf("Cadena %s", a_cadena(cad, num));
	pausar();
}


void pbaEjercicio12() {
	char cad[20];
	int num;
	titulo("Saludar");
	printf("Ingrese una cadena de texto: ");
	fflush(stdin);
	gets(cad);
	titulo("Resultado");
	printf("%s", saludar(cad));
	pausar();
}
