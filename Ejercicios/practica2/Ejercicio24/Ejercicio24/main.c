#include <stdio.h>
#include <stdlib.h>

int main()
{
    float precio;
    float descuento;
    float neto;
    float por;
    printf("Ingrese el precio: ");
    scanf("%f", &precio);

    while(precio > 0) {
        if(precio < 50) {
            descuento = (3.5 * precio) / 100;
            neto = precio - descuento;
            por = 3.5;
        }else if(precio <= 150) {
            descuento = (10 * precio) / 100;
            neto = precio - descuento;
            por = 10;
        } else if(precio <= 300) {
            descuento = (20 * precio) / 100;
            neto = precio - descuento;
            por = 20;
        }else {            descuento = (25 * precio) / 100;
            neto = precio - descuento;
            por = 25;
        }

        printf("Precio %f $ \n", precio);
        printf("Porcentaje descuento %0.2f % \n", por);
        printf("Descuento %f $ \n", descuento);
        printf("Neto %f $ \n", neto);

        printf("Ingrese el precio: ");
        scanf("%f", &precio);
    }


    return 0;
}
