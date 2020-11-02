#include <funciones.h>

/**
	Ejercicio 1 --------------------------------------------------------------
	Suma dos numeros y muestra el resultado
	por las dudas aunque no lo pedia retorno el resultado de la suma.
*/
int suma( const int *n1, const int *n2 ) {
	printf("\n\tEl resultado es: %d", *n1 + *n2);
	return *n1 + *n2;
}

/**
	Ejercicio 2 --------------------------------------------------------------
*/
float calcularPromedioNotas(const int *n1, const int *n2, const int *n3) {
	return (*n1 + *n2 + *n3) /(float) 3;
}

/**
	Ejercicio 3 --------------------------------------------------------------
*/
void carga(int *v, const int ce) {
	int i;
	for(i = 0; i < ce; i ++) {
		printf("Ingrese el valor Vec[%d]: ", i);
		scanf("%d", (v + i));
	}
}


/**
	Ejercicio 4 --------------------------------------------------------------
*/

int copiarVector(int *v1, const int *v2, const int ce1, const int ce2) {
	int i;
	if(ce1 <= 0 || ce2 <= 0 ||  ce1 != ce2)
		return 0;
	for(i = 0; i < ce1; i ++) {
		*v1 = *v2;
		v1 ++;
		v2 ++;
	}
	
	return 1;
}

/**
	Ejercicio 5 --------------------------------------------------------------
*/
void encontrarMax(int * v, int ce, int * mayor) {
	int i;
	*mayor = *v;

	for(i = 1; i < ce; i ++) {
		v ++;
		if(*v > *mayor) 
			*mayor = *v;
	}
}


/**
	Ejercicio 6 --------------------------------------------------------------
*/
void contar(int *v, int ce, int *pares, int *impares) {
	int i;
	*pares = 0;
	*impares = 0;
	for(i = 0; i < ce; i ++) {
		if(*v % 2 == 0)
			(*pares) ++;
		else
			(*impares) ++;
		v ++;
	}
}



/**
	Ejercicio 7 --------------------------------------------------------------
*/
void ingresarRecaudado(float *rec, int dia, int cajera) {
	printf("Total recaudado del dia %d de la cajera %d: ",dia + 1, cajera );
	scanf("%f", (rec + dia));
}

float recaudacionTotal(float *rec) {
	int i;
	float total = 0;
	for(i = 0; i < 7; i ++) { 
		total += *rec;
		rec ++;
	}
	
	return total;
}

int determinarPremio(float total1, float total2) {
	return total1 == total2 ? 0 : total1 > total2 ? 1: 2;
}


int menorVenta(float *rec) {
	int menor = 0, i;
	
	for(i = 1; i < 7; i ++) {
		if(*(rec + i) < *(rec + menor))
			menor = i;
	}
	
	return menor;
}

void mostrarDiaMenor(int cajera, int diaMenor) {
	printf("El dia que la cajera %d vendio menor es %d\n",cajera, diaMenor );
}

/**
	Ejercicio 8 --------------------------------------------------------------
*/

char ultimoCaracter(char *cad) {
	while(*cad)
		cad ++;
	return *( -- cad);
}


/**
	Ejercicio 9 --------------------------------------------------------------
*/

int letras(char *s) {
	int cant = 0;
	while(*s) {
		s ++;
		cant ++;
	}
	return cant;
}


/**
	Ejercicio 10 --------------------------------------------------------------
*/

int cantidad(char *s, int cant) {
	return letras(s) == cant;
}


/**
	Ejercicio 11 --------------------------------------------------------------
*/

char *rev(char *s) {
	char *inicio = s;
	char *fin = s;
	char aux;
	while(*fin) 
		fin ++;
	fin --;
	while(inicio < fin) {
		aux = *fin;
		*fin = *inicio;
		*inicio = aux;
		fin --;
		inicio ++;
	}
	return s;
}

char * a_cadena(char *s, int num) {
	char *aux = s; 
	char a;
	int resto = 0;
	do {
		resto = num % 10;
		*aux = resto + '0';
		num /= 10;
		aux ++;
	}while(num > 0);
	*aux = '\0';
	return rev(s);
}


/**
	Ejercicio 12 --------------------------------------------------------------
*/

char * concat(char *s1, char *s2) {
	char *res = s1;
	while(*s1)
		s1 ++;
	while(*s2) {
		*s1 = *s2;
		s1 ++;
		s2 ++;
	}
	*s1 = '\0';
	return res;
}

char *saludar(char *nombre) {
	char sal[25] = "Hola ";
	return concat(sal, nombre);
}
