#include "./lib/menu.c"
#include "./lib/pbaFunciones.c"

int main(char * arg, char args[]) {

    char op;
    
    char opciones[][TAM] = {
        "PBCDES",
        "Potencia",
        "Opcion 2",
        "Opción 3",
        "Opción 4",
        "Opción 5",
        "Salir"
    } ;



    do {
        op = seleccionarOpcion(opciones);
        switch(op) {
            case 'P': 
               pbaPotencia();
                break;
        }
    }while(op != 'S');

    

    return 0;
}