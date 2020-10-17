#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "./heather.h"



void limpiar() {
	system("cls");
}

void pausa() {
	system("pause");
}

int enterosMayoresCero( char *mje) {
	int num;
	do {
		printf(mje);
		scanf("%d", &num);
	}while(num < 0);
	return num;
}

void pbaPotencia() {
    double num;
    int pot;
    system("cls");
    printf("Ingrese el numero: ");
    scanf("%lf", &num);
    printf("Ingrese la potencia: ");
    scanf("%d", &pot);
    printf("\n\n El resultado es: %0.2f\n\n", potencia(num, pot));
    system("pause");
}


double sumarValores() {
	double num1;
    double num2;
    printf("Ingrese el numero 1: ");
    scanf(" %lf", &num1);
    printf("Ingrese el numero 2: ");
    scanf(" %lf", &num2);
    return suma(num1, num2);
}


double restarValores() {
	double num1;
    double num2;
    printf("Ingrese el numero 1: ");
    scanf(" %lf", &num1);
    printf("Ingrese el numero 2: ");
    scanf(" %lf", &num2);
    return resta(num1, num2);
}

double mulValores() {
	double num1;
    double num2;
    printf("Ingrese el numero 1: ");
    scanf(" %lf", &num1);
    printf("Ingrese el numero 2: ");
    scanf(" %lf", &num2);
    return mul(num1, num2);
}

double divValores() {
	double num1;
    double num2;
    printf("Ingrese el numero 1: ");
    scanf(" %lf", &num1);
    printf("Ingrese el numero 2: ");
    scanf(" %lf", &num2);
    return division(num1, num2);
}

void llamadaMat(const char * mje, t_mat funcion) {
	limpiar();
    printf(mje,funcion());
	pausa();
}

void pbaCalculadora() {
	char op;
	char opciones[][TAM] = {
        "ARMDS",
        "Suma",
        "Resta",
        "Multiplicacion",
        "Division",
        "Salir"
    } ;
	system("cls");
	
	
	 do {
        op = seleccionarOpcion(opciones, "Calculadora");
        switch(op) {
            case 'A': 
            	llamadaMat(" \nResultado: %lf\n\n", sumarValores);
            break;
            case 'R': 
            	llamadaMat(" \nResultado: %lf\n\n", restarValores);
            break;
            case 'M': 
            	llamadaMat(" \nResultado: %lf\n\n", mulValores);
            break;
            case 'D': 
            	llamadaMat(" \nResultado: %lf\n\n", divValores);
            break;
        }
    }while(op != 'S');
}

void pbaMostrarIntercambio(int num1, int num2) {
	printf("Intercambiados N1: %d N2: %d\n", num2, num1);
	system("pause");
	
}


void pbaPedirValores() {
	int num1, num2;
	system("cls");
	printf("Ingrese el numero 1: ");
    scanf(" %d", &num1);
    printf("Ingrese el numero 2: ");
    scanf(" %d", &num2);
    pbaMostrarIntercambio(num1, num2);
}

int area1() {
	return mul(3,3);
}

int area2 () {
	return mul(suma(4,3), 2);
}

int area() {
	return area1() + area2();
}

void pbaAreas() {
	system("cls");
	printf("El area total es: %d\n", area());
	system("pause");
}

void pbaEsPar() {
	int num1;
	system("cls");
	printf("Ingrese el numero: ");
    scanf(" %d", &num1);
    printf("%s\n", esPar(num1)? "Es Par": "No es par");
    system("pause");
}


void pbaMedia() {
	double num1;
    double num2;
    limpiar();
    printf("Ingrese el numero 1: ");
    scanf(" %lf", &num1);
    printf("Ingrese el numero 2: ");
    scanf(" %lf", &num2);
    printf("La media es: %0.2lf\n", media(num1, num2));
   	pausa();
}


void pbaNegativo() {
	int num1;
    limpiar();
    printf("Ingrese el numero: ");
    scanf(" %d", &num1);
    printf("Es negativo: %d\n", negativo(num1));
   	pausa();
}


void calcularEdades(const int edadUno, const int edadDos) {
	int menor = edadUno < edadDos ? edadUno : edadDos;
    printf("La menor edad es %d\n",menor);
    if(menor < 18)
    	printf("A la menor edad le faltan %d para llegar a 18 años\n", 18 - menor);
    else
    	printf("La edad menor ya supera la mayria de edad\n");
}

void pbaEdades() {
	int num1;
    int num2;
    int menor;
    limpiar();
	printf("Ingrese la primera edad: ");
    scanf(" %d", &num1);
    printf("Ingrese la segunda edad: ");
    scanf(" %d", &num2);
    calcularEdades(num1, num2);
    pausa();
}

float cobroHora(int horas, int categoria) {
	float cHora;
	switch(categoria) {
		case 1: cHora = horas * 10;
			break;
		case 2: cHora = horas * 20;
			break;
		case 3: cHora = horas * 25;
			break;
		case 4: cHora = horas * 30;
			break;
	}
	
	return cHora;	
}

float cobroAnt(int antiguedad) {
	return antiguedad * 50;
}

void pbaEmpleado() {
	int horas, antiguedad, categoria;
	float sueldo;
	limpiar();
	
	
	horas = enterosMayoresCero("Ingrese la cantidad de horas trabajadas: ");
	antiguedad = enterosMayoresCero("Ingrese la antiguedad: ");
	categoria = enterosMayoresCero("Ingrese la categoria: ");
	
	sueldo = cobroHora(horas, categoria) + cobroAnt(antiguedad);
	
	if(sueldo > 1000)
		printf("El sueldo del empleado es %0.2f: ", sueldo);
	else
		printf("El sueldo no supera los 1000 $");
	
	printf("\n\n");
	pausa();
}

float pbaCalcularSalario(int horas) {
	int extras;
	int normales;
	float salario;
	if(horas > 35) {
		extras 	 = horas - 35;
		normales = horas - extras;
		salario  = normales * 50;
		salario  += extras * 75; 
	}else {
		salario = horas * 50;
	}
	return salario;
}

void pbaSalario() {
	int horas;
	char cond;
	float salario;
	printf("Desea calcular un salario: ");
	fflush(stdin);
	scanf("%c", &cond);

	
	while(cond == 'S' || cond == 's') {
		limpiar();
		horas = enterosMayoresCero("Ingrese la cantidad de horas trabajadas: ");
		salario = pbaCalcularSalario(horas);
		printf("El salario es %f\n\n", salario);
		
		printf("Desea calcular un salario: ");
		fflush(stdin);
		scanf("%c", &cond);
	}
}

void pbaMultiplos5() {
	const int num1 = 5;
	int i, sumatoria = 0;
	
	limpiar();

	for(i = num1; i<= 100; i++ ) {
		if(multiplo(num1, i)) {
			printf("Valor %d\n", i);
			sumatoria += i;
		}	
	}
	
	printf("La sumatoria de los valores es %d\n", sumatoria);
	
	pausa();
}

void pbaPares200() {
	int i, sumatoria = 0;
	limpiar();
	for(i = 2; i <= 200; i += 2) {
		printf("El valor es: %d\n", i);
		sumatoria += i;
	}
		
	printf("La sumatoria es: %d\n\n", sumatoria);
	pausa();
}

void pbaFactorial() {
	int num;
	limpiar();
	num = enterosMayoresCero("Ingrese el numero para calcular el factorial: ");
	printf("\nEl factorial es: %ld\n", factorial(num));
	
	pausa();
}

void pbaPrimo() {
	int num;
	int primo;
	limpiar();
	num = enterosMayoresCero("Ingrese el numero: ");
	primo = esPrimo(num);
	if(primo == 1)
		printf("Es Primo\n\n");
	else if(primo == 0)
		printf("No Es Primo\n\n");
	else 
		printf("Es %d no se considera\n\n", num);
	pausa();
}

void calcularAntSig(const int num) {
	int i;
	printf("Mayores Menores\n");
	for(i = 1; i <= 5; i ++) 
		printf("%2d %7d\n", num + i, num - i);
}

void pbaAntSig () {
	int num;
	limpiar();
	printf("Ingrese el numero: ");
	scanf("%d", &num);
	calcularAntSig(num);
	pausa();
}


int menor(void *arreglo, int ce, int inicio, size_t tam, t_cmp comp) {
	int menor = inicio;
	void *aux = malloc(sizeof(tam));
	while(inicio < ce) {
		if(comp((arreglo + (inicio * tam)), (arreglo + (menor * tam))) < 0)
			menor = inicio;
		inicio ++;
	}
	free(aux);
	return menor;
}

void seleccion(void *arreglo, int ce, size_t tam, t_cmp comp) {
	void *aux = malloc(sizeof(tam));
	int inicio = 0;
	int menorValor;
	while(inicio < ce) {
		menorValor = menor(arreglo,ce,inicio,tam,comp);
		if(menorValor != inicio) {
			memcpy(aux, (arreglo + (inicio * tam)), tam);
			memcpy((arreglo + (inicio * tam)), (arreglo + (menorValor * tam)), tam);
			memcpy((arreglo + (menorValor * tam)), aux, tam);
		}
		inicio ++;
	}
	free(aux);
}


void qs(void *arreglo, int ini,int fin, size_t tam, t_cmp comp) {
	int i = ini;
	int j = fin;
	void *aux = malloc(sizeof(tam));
	int pivote = (i + j) / 2;
	do   {
		while( comp((arreglo + (pivote * tam)), (arreglo + (i * tam))) > 0 && i < fin)
			i ++;
		while( comp((arreglo + (pivote * tam)), (arreglo + (j * tam))) <= 0 && j > ini)
			j --;
		if(i <= j) {
			memcpy(aux, (arreglo + (i * tam)), tam);
			memcpy((arreglo + (i * tam)), (arreglo + (j * tam)), tam);
			memcpy((arreglo + (j * tam)), aux, tam);
			i ++;
			j --;
		}
	}while(i <= j);
	free(aux);
	if(ini<j)
		qs(arreglo,ini,j, tam,comp);
    if(fin > i)
		qs(arreglo,i,fin, tam,comp );
}

void q_sort(void *arreglo, int ce, size_t tam, t_cmp comp) {
	qs(arreglo, 0, ce -1, tam, comp);
}
