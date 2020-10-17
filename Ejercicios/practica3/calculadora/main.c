 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 
 #define TAM 100
 
 
 
 
 float suma(const float, const float );
 float resta(const float, const float );
 float mul(const float , const float );
 float division(const float, const float );
 
 char mostrarMenu(char opciones[][TAM], const char *);
 int validarOpcion(char *opciones, char op);
 char seleccionarOpcion(char opciones[][TAM], const char *);
 
 
 float ingresarOperador ( int  );
 void pbaSuma ();
 void pbaResta ();
 void pbaMul ();
 void pbaDiv ();
 
 int main () {
 	
 	char opciones[][TAM] = {
		"ARMDS",
		"Suma",
		"Resta",
		"Multiplicacion",
		"Division",
		"Salir"
	}, op;
	
	
	
 	do {
 		op = seleccionarOpcion(opciones, "Calculadora");
 		switch(op) {
 			case 'A':
			 	pbaSuma();
			 break;	
			 case 'R':
			 	pbaResta();
			 break;
			 case 'M':
			 	pbaMul();
			 break;
			 case 'D':
			 	pbaDiv();
			 break;
		}
	} while(op != 'S');
 	
 	
 	return 0;
 }
 
 float ingresarOperador ( int op ) {
 	float num;
 	printf("Ingrese el operador %d: ", op);
 	scanf("%f", &num);
 	return num;
 }
 
 void pbaSuma () {
 	system("cls");
 	float num1 = ingresarOperador(1);
 	float num2 = ingresarOperador(2);
 	
 	printf("El resultado de la suma %.2f\n\n", suma(num1, num2));
	system("pause"); 
 }
 
 void pbaResta () {
 	system("cls");
 	float num1 = ingresarOperador(1);
 	float num2 = ingresarOperador(2);
 	printf("El resultado de la suma %.2f\n\n", resta(num1, num2));
	system("pause");  
 }
 
 
  void pbaMul () {
  	system("cls");
 	float num1 = ingresarOperador(1);
 	float num2 = ingresarOperador(2);
 	printf("El resultado de la suma %.2f\n\n", mul(num1, num2));
	system("pause"); 
 }
 
 void pbaDiv () {
 	system("cls");
 	float num1 = ingresarOperador(1);
 	float num2 = ingresarOperador(2);
 	if(num2 == 0)
 		printf("ERROR Div por 0\n\n");
 	else
 		printf("El resultado de la suma %.2f\n\n",division(num1, num2));
	system("pause"); 
 }
 
 float suma(const float num1, const float num2) {
 	return num1 + num2;
 }
 
 float resta(const float num1, const float num2) {
 	return num1 - num2;
 }
 
 float mul(const float num1, const float num2) {
 	return num1 * num2;
 }
 
 float division(const float num1, const float num2) {
 	return num2 != 0 ? num1 / num2: 0;
 }
 
 char mostrarMenu(char opciones[][TAM], const char *mje) {
    int i;
    char op;
    for(i = 0; i < strlen(opciones[0]); i ++) 
        printf("\t\t\t%c - %s \n", opciones[0][i] , opciones[i + 1]);
    printf("\n\n\t\t%s",mje);
    scanf(" %c", &op); 
    return op;
}

int validarOpcion(char *opciones, char op) {
    while(*opciones && opciones && *opciones != op) 
        opciones ++;
    return op == *opciones;
}

char seleccionarOpcion(char opciones[][TAM], const char * titulo) {
    char op;
    system("cls");
    printf("\n\t\t\t\t%s\n\n", titulo);
    op =  mostrarMenu(opciones, "Seleccione una opcion: ");
    while(!validarOpcion(opciones[0], toupper(op))) {
       system("cls");
       printf("\n\t\t\t\t%s\n\n", titulo);
       op =  mostrarMenu(opciones, "(Err) Ingrese de vuelta la opcion: ");  
    }

    return toupper(op);
}

