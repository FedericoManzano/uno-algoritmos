#include "./header.h"

int main(int argc, char *argv[]) {
	
	char op;
	float oprandos1[TAM_MAX], oprandos2[TAM_MAX];
	char operacion[TAM_MAX] = {'\0'};
	float oper1, oper2;
	char operacionSeleccionada; 

	do {
		op = seleccionarOpcion();
		switch(op) {
			case '1':
					ingresarDatos(&oper1, &oper2, &operacionSeleccionada);
					realizarCalculos(&oper1, &oper2, &operacionSeleccionada);
					guardarDatos(&oper1, &oper2, &operacionSeleccionada,oprandos1,  oprandos2,operacion);
				break;
			case '2':
				mostrarDatos(oprandos1, oprandos2, operacion);
				break;
		}	
	}while(op != 'S');
	
	
	
	return 0;
}
