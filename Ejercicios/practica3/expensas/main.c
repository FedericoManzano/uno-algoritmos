 #include <stdio.h>
 #include <stdlib.h>
 
 #define A_MAY(X) ( (X) >= 'a' && (X) <= 'z' ? (X) - ' ' : (X) )
 #define CATEGORIA(X) ( A_MAY(X) == 'P' || A_MAY(X) == 'S' || A_MAY(X) == 'D' || A_MAY(X) == 'M'  )
 #define PROFESIONAL(X) ( (X) == 1 || (X) == 0 ) 
 #define POSITIVO(X)( (X) > 0 )
 
 #define PROF 1
 #define PART 0
 
 
 
 char condicionFin();
 float calcularExpensas( const char cat, const int prof,  const char cochera) ;
 void ingresarEntradas ( int *nroDepto, char * cat, int * prof, char * cochera );
 float montoMultas();
 char tieneMultas();
 void mostrarCantidad ( const int cantDAmProf);
 
 int main () {
 	
 	// Entradas
	int  nroDepto,uso;

 	char categoria, tMultas, cochera;
 	
 	float expensas, total;
 	int cantDAmProf = 0;
 	
 	char op = condicionFin();
 	
 	while ( op == 'S' || op == 's' ) {
 		
 		ingresarEntradas(&nroDepto,&categoria, &uso, &cochera);
 		
 		expensas = calcularExpensas(categoria, uso, cochera);
 		
 		tMultas = tieneMultas();
 		
 		
 		if( tMultas == 's' || tMultas == 'S' ) {
 			total = expensas + montoMultas();
 			system("cls");
 			printf("\n\n\t - *El total a pagar por del depto %d es %.2f* -\n\n", nroDepto, total);
		}else {
			system("cls");
			printf("\n\n\t - *El total a pagar por del depto %d es %.2f* -\n\n",nroDepto, expensas);
		}
 			
 		if( ( categoria == 'd' || categoria == 'D' ) && uso )
 			cantDAmProf ++;
 		
 		op = condicionFin();
	}
 	mostrarCantidad ( cantDAmProf);
 	return  0;
 }
 
 void mostrarCantidad ( const int cantDAmProf)  {
 	system("cls");
 	printf("\n\n\t-*La cantidad de deptos de dos ambientes profesionales es de: %d*-\n\n", cantDAmProf);
 	system("pause");
 }
 
 float montoMultas() {
 	float multas;
 	printf("Ingrese monto de multas: ");
 	scanf("%f", &multas);
 	return multas;
 }
 char tieneMultas() {
 	char mul;
 	printf("El deprto tiene multas ( S / N ): ");
 	fflush(stdin);
 	scanf("%c", &mul);
 	return mul;
 }
 
 float calcularExpensas( const char cat, const int prof,  const char cochera) {
 	float monto;
 	if( cat == 'p' || cat == 'P' ) 
 		monto = 4000;
 	if(	cat == 's' || cat == 'S' )
 		monto = 3000;
 	if( cat == 'd' || cat == 'D' )
 		monto = 2000;
 	if( cat == 'm' || cat == 'M' ) 
 		monto = 1000;
 	if(prof)
 		monto += 2500;
 	if(cochera == 's' || cochera == 's') 
	 	monto += 1500;
	return monto; 
 }
 
 char condicionFin() {
 	char op;
 	printf("Desea calcular impuestos de un departamento ( S / N ): ");
 	fflush(stdin);
 	scanf("%c", &op);
 	return op;
 }
 
 
 int ingresarDepto() {
 	int val = 0, depto;
 	do{
 		if(val) {
 			printf("\n\tErr ingrese el nro de depto nuevamente !! \n\n");	
 			val = 0;
		}
 		printf("Ingrese el numero de depto: ");
 		scanf("%d", &depto);
 		val = 1;
	} while( !POSITIVO( depto ) );
	
	return depto;
 }
 
 char ingresarCategoria() {
 	char cat;
 	int val = 0;
 	do{
 		if(val) {
 			printf("\n\tErr ingrese la categoria nuevamente !! \n\n");	
 			val = 0;
		}
 		printf("Ingrese la categoria de depto ( p / s / d / m ): ");
 		fflush(stdin);
 		scanf("%c", &cat);
 		val = 1;
	} while( !CATEGORIA(cat) );
	return cat;
 }
 
 int ingresarFuncion () {
 	int val = 0, prof;
 	
 	do{
 		if(val) {
 			printf("\n\tErr es ( 1 / 0 ) ingrese nuevamente !! \n\n");	
 			val = 0;
		}
 		printf("Destinado a profesional ( 1 / 0 ): ");
 		fflush(stdin);
 		scanf("%d", &prof);
 		val = 1;
	} while( !PROFESIONAL(prof) );
	return prof;
 	
 }
 
 char ingresarCochera () {
 	char cochera;
 	int val = 0;
 	do{
 		if(val) {
 			printf("\n\tErr es ( S / N ) ingrese nuevamente !! \n\n");	
 			val = 0;
		}
 		printf("Tiene cochera ( S / N): ");
 		fflush(stdin);
 		scanf("%c", &cochera);
 		val = 1;
	} while( cochera != 's' && cochera != 'S' && cochera != 'n' &&  cochera != 'N');
	return cochera;
 }
 
 void ingresarEntradas ( int *nroDepto, char * cat,  int  *prof, char * cochera ) {
 	*nroDepto = ingresarDepto();
 	*cat = ingresarCategoria();
 	*prof = ingresarFuncion();
 	*cochera = ingresarCochera();
 } 
 
 
