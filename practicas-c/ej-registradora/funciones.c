#include "./header.h"



void titulo(char * tit) {
	system("cls");
	printf("\n\n\t\t\t\t-= %s =-\n\n", tit);
}

void pausar() {
	printf("\n\n");
	system("pause");
}

int gestionarIndice() {
	static int indice = -1;
	indice ++;
	return indice;
}

void mostrarMenu() {
	printf("\t[ 1 ] Efectuar Calculos\n");
	printf("\t[ 2 ] Informes\n");
	printf("\t[ S ] Salir\n\n");
}

char seleccionarOpcion() {
	char op;
	int val = 1;
	do {
		titulo("Menu Opciones");
		mostrarMenu();
		if(val)
			printf("Seleccione una opcion del menu: ");
		else
			printf("Err opcion incorrecta: ");
		fflush(stdin);
		scanf("%c", &op);
		op = toupper(op);
		val = 0;
	} while(op != '1' && op != '2' && op != 'S');
	
	return op;
}

void ingresarDatos(float *oper1, float *oper2, char *operacion) {
	titulo("Ingreso de datos");
	printf("Ingrese el operando1: ");
	fflush(stdin);
	scanf("%f", oper1);
	
	printf("Ingrese el operando2: ");
	fflush(stdin);
	scanf("%f", oper2);
	
	printf("Ingrese la operacion: ");
	fflush(stdin);
	scanf("%c", operacion);
}

float realizarCalculos(float *oper1, float *oper2, char *operacion) {
	float res;
	titulo("Realizar Calculo");
	printf("%-15s%-15s%-15s\n", "OPERANDO1", "OPERANDO2", "OPERACION");
	printf("%-15.2f%-15.2f%-15c", *oper1, *oper2, *operacion);
	printf("\n\nResultado\n\n");
	switch(*operacion) {
		case 's': 
			res = *oper1 + *oper2;
			break;
		case 'r': 
			res = *oper1 - *oper2;
			break;
		case 'm': 
			res = *oper1 * *oper2;
			break;
		case 'd': 
			res = *oper2 != 0 ?  *oper1 / *oper2 : __ERROR_DIV_CERO;
			break;
	}
	printf("El resultado es : %.2f", res);
	
	
	pausar();
	return res;
}

void guardarDatos(float *oper1, float *oper2, char *operacion, float *vOper1, float *vOper2, char *vOperacion) {
	int indice = gestionarIndice();
	*(vOper1 + indice) = *oper1;
	*(vOper2 + indice) = *oper2;
	*(vOperacion + indice) = *operacion;
}

void mostrarDatos(float *vOper1, float *vOper2, char *vOperacion) {
	int cantSumas = 0,cantRestas = 0, cantMul = 0, cantDiv = 0;
	titulo("Resultados Finales");
	while(*vOperacion) {
		switch(*vOperacion) {
			case 's': 
				printf("[ OP ] %.2f + %.2f = %.2f\n", *vOper1, *vOper2, *vOper1 + *vOper2 );
				cantSumas ++;
				break;
			case 'r': 
				printf("[ OP ] %.2f - %.2f = %.2f\n", *vOper1, *vOper2,*vOper1 - *vOper2);
				cantRestas ++;
				break;
			case 'm': 
				printf("[ OP ] %.2f * %.2f = %.2f\n", *vOper1, *vOper2, *vOper1 * *vOper2);
				cantMul ++;
				break;
			case 'd': 
				printf("[ OP ] %.2f / %.2f = %.2f\n", *vOper1, *vOper2, *vOper1 / *vOper2);
				cantDiv ++;
				break;
		}
		
		vOperacion ++;
		vOper1 ++;
		vOper2 ++;
	}
	
	printf("\n\n\tInforme Operaciones\n\n");
	
	printf("%-10s%-10s%-20s%-15s\n", "SUMAS", "RESTAS", "MULTIPLICACIONES", "DIVISIONES");
	printf("%-10d%-10d%-20d%-15d", cantSumas, cantRestas, cantMul, cantDiv);

	pausar();
}


