#include <header.h>

int main(int argc, char *argv[]) {
	t_menu menu;
	char opciones [][TAM_MENU] = {
		"Cargar datos",
		"Evaluar  Jugadores",
		"Salir"
	}, op;
	
	int camisetas	[TAM_JUGADORES],
		cantGoles	[TAM_JUGADORES],
		cantInfracc	[TAM_JUGADORES],
		cantPartidos[TAM_JUGADORES];
		
		
	crearMenu(&menu, opciones,"12S", "Jugadores", "Ingrese una opcion", "Err opcion erronea", "[]" );
	

	do {
		op = seleccionarOpcion(&menu);
		switch(op) {
			case '1': ingresarJugadores(camisetas, cantGoles, cantInfracc, cantPartidos);
				break;
			case '2': evaluarJugadores(camisetas, cantGoles, cantInfracc, cantPartidos);
				break;
		}
	}while(op != 'S');
	
	return 0;
}
