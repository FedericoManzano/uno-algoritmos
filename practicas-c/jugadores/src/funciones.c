#include <header.h>

char titulo(char *tit) {
	system("cls");
	printf("\n\n\t\t\t\t%s\n\n", tit);
}
void inicializarVectores(int * cam, int * cgoles, int * cinfracc, int * cantp) {
	int i;
	for(i = 0; i < TAM_JUGADORES; i ++) {
		cam		[ i ] = 0;
		cgoles	[ i ] = 0;
		cinfracc[ i ] = 0;
		cantp 	[ i ] = 0;
	}
}


int valorMax(int *cgoles) {
	int mayor 	= 0;
	int indice 	= 0;
	while(*(  cgoles + indice ) != 0) {
		if(*(  cgoles + mayor ) < *(  cgoles + indice ))
			mayor = indice;
		indice ++;
	}
	return mayor;
}

void ingresarJugadores(int * cam, int * cgoles, int * cinfracc, int * cantp) {
	char op = 's';
	int i = 0;
	
	inicializarVectores(cam, cgoles, cinfracc, cantp);

	
	titulo("Ingreso de jugadores");
	while(op == 's' || op == 'S') {
		printf("Ingrese el numero de camiseta del jugador: ");
		fflush(stdin);
		scanf("%d", cam + i);
		printf("Ingrese la cantidad de goles: ");
		scanf("%d", cgoles + i);
		printf("Ingrese la cantidad de infracciones: ");
		scanf("%d", cinfracc + i);
		printf("Ingrese la cantidad de partidos: ");
		scanf("%d", cantp + i);
		i++;
		
		printf("Desea seguir cargando juagadores: ");
		fflush(stdin);
		scanf("%c", &op);
		
		titulo("Ingreso de jugadores");
	}
}

void evaluarJugadores(int * cam, int * cgoles, int * cinfracc, int * cantp) {
	

	int camisetaMax = *(cam 	+ valorMax(cgoles)), 
		cantGolMax 	= *(cgoles 	+ valorMax(cgoles));
	int juegoSucio  = 1;

	titulo("Resultados ...");
	while( *cam != 0 ) {
		if( *cgoles >= 10 && *cinfracc < 5) {
		
			printf("Camiseta: %d Buen Jugador !!\n", *cam);
			if( *cantp <= 2 || *cinfracc <= 2)
				juegoSucio = 0;
		} else 
			printf("Camiseta: %d Mal Jugador !!\n", *cam);
			
		cam 		++;
		cgoles 		++;
		cinfracc 	++;
		cantp 		++;
	}
	
	
	printf("Jugador goleador del campeonato camiseta: %d  goles: %d\n", camisetaMax, cantGolMax);

	if(juegoSucio) 
		printf("Hubo Juego Sucio...\n");
	else
		printf("No hubo juego sucio...\n");
		
	system("pause");
	
	
}

