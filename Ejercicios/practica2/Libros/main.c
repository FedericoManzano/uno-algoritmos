
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char titulo[20];
    float precio;
    int nacionalidad;
    char tipo;
    int unidades;

}t_libro;


float calcularMonto(t_libro *libro) {
    return ((libro->precio * 10) / 100) * libro->unidades;
}

void ingresarDatos (t_libro *libro) {
    printf("Ingrese el titulo del libro: ");
    scanf(" %[^\n]%*c", libro->titulo);
    printf("Precio: ");
    scanf(" %f", &libro->precio);
    printf("Unidades: ");
    scanf(" %d", &libro->unidades);
    printf("Tipo: ");
    scanf(" %c", &libro->tipo);
    printf("Nacionalidad: ");
    scanf(" %d", &libro->nacionalidad);
}

int main(char *args, char arg ) {

    system("clear");


    t_libro libro;
    float precioMax;
    char tituloMax[20];
    int cantNacUno = 0;
    int cantNacDos = 0;
    int cantNacTres = 0;
    int cantNacCuatro = 0;
    float monto;
    int ban = 1;

    char cond;

    char pausa;

    printf("Desea agregar un libro: ");
    scanf(" %c", &cond);
    
    while(cond == 'S' || cond == 's') {
        ingresarDatos(&libro);

        monto = calcularMonto(&libro);

        if(libro.tipo == 'S' || libro.tipo == 's' ) {
            switch(libro.nacionalidad) {
                case 1: cantNacUno ++;
                    break;
                case 2: cantNacDos ++;
                    break;
                case 3: cantNacTres ++;
                    break;
                case 4: cantNacCuatro ++;
                    break;
            }
        }
        system("clear");
        if(ban == 1) {
            precioMax = libro.precio;
            strcpy(tituloMax, libro.titulo);
            ban = 0;
        }else if(precioMax < libro.precio){
            precioMax = libro.precio;
            strcpy(tituloMax, libro.titulo);
        }   

        if(libro.unidades < 5000) {
            printf("Malo \n");
        }else if(libro.unidades >= 5001 && libro.unidades <= 10000) {
            printf("Regular \n");
        }else if(libro.unidades >= 10001 && libro.unidades <= 20000) {
            printf("Bueno \n");
        }else {
            printf("Muy Bueno \n");
        }

        printf("El monto es: %f \n", monto);

        printf("precione S o s para continuar ....");
        scanf(" %c", &pausa);
        system("clear");


        printf("\nDesea agregar un libro: ");
        scanf(" %c", &cond);


    }

    system("clear");


    printf("La cantidad de libros de autores americanos es %d \n", cantNacUno);
    printf("La cantidad de libros de autores europeos es %d \n", cantNacDos);
    printf("La cantidad de libros de autores africanos es %d \n", cantNacTres);
    printf("La cantidad de libros de autores asiaticos es %d \n", cantNacCuatro);

    if(ban == 0) {
        printf("\nLibro mayor precio %s \n", tituloMax);
        printf("\nPrecio %f \n", precioMax);
    }
    

    return 0;
}