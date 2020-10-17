 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <string.h>
 
 
 #define UNO_Y_CINCO(X)((X) >= 1 && (X) <= 5)
 
 // Retorna la elección del usuario
 // de continuar agregando trabajadores 
 // o no.
 char ingresarCondicionFin ();
 
 // Ingreso de valores de entrada
 int ingresarCodigoEmpleado();
 int ingresarDiasTrabajados();
 void esProfesional(char *);
 int ingresarCCalidad();
 int ingresarACreatividad();
 int ingresarCooperacion();
 
 int rendimiento ( const int, const int, const int );
 void mostrarEstado(int, int);
 float promedioRendimiento (const int , const int, const int);
 void mostrarResultados(int, int );
 
 
 int main() {
 	unsigned int cEmpleado, 
	 			 diasTrabajados, 
				 cctrabajo, 
				 cooperacion, 
				 cacreatividad,
				 resRendimiento;
				 
 	char profesional[3]; 
 	int bandera = 1, 
	 	codMax, 
		diasMax, 
		cantidadFueraNivel = 0;
 	
 	
 	
 	char cond = ingresarCondicionFin();
 	
 	
 	
 	while( cond == 'S' || cond == 's' ) {
 		
 		
 		cEmpleado 		= ingresarCodigoEmpleado();
 		diasTrabajados 	= ingresarDiasTrabajados();
		cctrabajo 		= ingresarCCalidad();
		cooperacion 	= ingresarCooperacion();
 		
 		esProfesional(profesional);
 		
 		
 		if( !strcmpi( profesional, "si" ) ) {
 			cacreatividad = ingresarACreatividad();
 			if( !( resRendimiento = rendimiento(cctrabajo,cooperacion,cacreatividad) ) ) 
 				if(promedioRendimiento(cctrabajo,cooperacion,cacreatividad) < 3) 
 					cantidadFueraNivel ++;
 			mostrarEstado(cEmpleado, resRendimiento);
		} 
		
		if (bandera == 1) {
			codMax = cEmpleado;
			diasMax = diasTrabajados;
			bandera = 0;
		}else if( diasMax < diasTrabajados ) {
			codMax = cEmpleado;
			diasMax = diasTrabajados;
		}
		
		
		cond = ingresarCondicionFin();		
	}
	mostrarResultados(cantidadFueraNivel, codMax);
 	return 0;
 }
 
 
 void mostrarResultados(int cantidadFn, int codMax ) {
 	system("cls");
	printf("**********************************************\n");
	printf("Cantidad de profesionales fuera de nivel %d \n", cantidadFn);
 	printf("Trabajador con mas horas trabajadas %d \n", codMax);
 	printf("********************************************** \n\n");
 	system("pause");
 }
 
 char ingresarCondicionFin () {
 	system("cls");
 	fflush(stdin);
 	char op;
	printf("Desea cargar un nuevo empleado: ");
 	scanf("%c", &op);
 	return op;
 }
 
 int rendimiento ( const int cctrabajo, const int cooperacion, const int cacreatividad) {
 	return cctrabajo >= 4 && cooperacion >= 4 && cacreatividad >= 4 ? 1:0;
 }
 
 void mostrarEstado(int codigo, int resRendimiento) {
 	if(resRendimiento == 1) 
 		printf("\n\nEl empleado %d TIENE CAPACIDAD DE DESARROLLO \n\n", codigo );
 	else 
 		printf("\n\nEl empleado %d NO TIENE CAPACIDAD DE DESARROLLO \n\n", codigo);
 	system("pause");
 }
 
 float promedioRendimiento (const int cctrabajo, const int cooperacion, const int cacreatividad) {
 	return (float)(cctrabajo + cooperacion + cacreatividad) / 3;
 }
 
 int ingresarCodigoEmpleado() {
 	int cEmpleado;
 	printf("Ingresar codigo del empleado: ");
 	scanf("%d", &cEmpleado);
 	return cEmpleado;
 }
 
 
 int ingresarDiasTrabajados() {
 	int dias;
 	printf("Ingresar dias trabajados: ");
 	scanf("%d", &dias);
 	return dias;
 }
 
 int ingresarCCalidad() {
 	int cctrabajo;
 	do {
 		printf("Ingresar cantidad y calidad de trabajo: ");
 		scanf("%d", &cctrabajo);
 	} while(!UNO_Y_CINCO(cctrabajo)); 
 	return cctrabajo;
 }
 
 int ingresarCooperacion() {
 	int coop;
 	
 	do {
 		printf("Ingresar nivel de cooperacion: ");
 		scanf("%d", &coop);
	} while(!UNO_Y_CINCO(coop)); 

 	return coop;
 }
 
 
 int ingresarACreatividad() {
 	int acreatividad;
 	do {
 		printf("Ingresar el nivel de capacidad de analisis y creatividad: ");
 		scanf("%d", &acreatividad);
 	} while(!UNO_Y_CINCO(acreatividad)); 
 	return acreatividad;
 }
 
 void esProfesional(char * profesional) {
 	printf("Es profesional (si / no): ");
 	fflush(stdin);
 	gets(profesional);
 }
