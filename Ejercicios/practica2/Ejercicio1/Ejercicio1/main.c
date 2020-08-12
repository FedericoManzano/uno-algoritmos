#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota = 0;

    printf("Ingrese la nota: ");
    scanf("%d", &nota);

    if(nota > 6)
        printf("La nota es mayor a 6");
    else
        printf("La nota es menor o igual a 6");

    return 0;
}
