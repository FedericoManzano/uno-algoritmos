#include <stdio.h>
#include <stdlib.h>


int main()
{
    int cantTurnos = 0;
    int reca = 0;
    int anosMen = 200;
    int toteUno = 0;
    int toteDos = 0;
    int toteTres = 0;
    int toteCuatro = 0;
    int cantPar = 0;
    int cantSoc = 0;

    char cond;
    int edad;
    int esp;
    char nombre[45];

    printf("Ingrese la condicion: ");
    fflush(stdin);
    scanf(" %c", &cond);


    while(cond != 'E') {
        printf("Ingrese su nombre: ");
        scanf(" %[^\n]%*c", nombre);

        printf("Ingrese su edad: ");
        scanf("%d", &edad);

        printf("Ingrese especialidad: ");
        scanf("%d", &esp);


        if(cond == 'S') {
            cantSoc ++;
            printf("A pagar $0");
        } else {
            cantPar ++;
            printf("A pagar $400");
            switch(esp) {
                case 1: toteUno += 400;
                    break;
                case 2: toteDos += 400;
                    break;
                case 3: toteTres += 400;
                    break;
                case 4: toteCuatro += 400;
                    break;
            }
            reca += 400;
        }

        if(anosMen > edad) {
            anosMen = edad;
        }

        cantTurnos ++;


        printf("Ingrese la condicion: ");
        fflush(stdin);
        scanf(" %c", &cond);
    }

    printf("Cantidad turnos particulares: %d\n", cantPar);
    printf("Cantidad turnos socios: %d\n", cantSoc);
    printf("Cantidad turnos totales: %d\n", cantTurnos);

    printf("Esp 1: %d Esp2: %d Esp3: %d Esp4: %d\n", toteUno, toteDos, toteTres, toteCuatro);
    printf("Menores: %d", anosMen);

    return 0;
}
