#include <stdio.h>
#include <stdlib.h>


int main (char *args, char arg) {
    int ban = 1, 
        dia = 1, 
        acuKm = 0, 
        km, 
        i, 
        maxRecorrido, 
        maxDia;

    char  combi = 'A', 
          peaje, 
          maxCombi, 
          pause;

          
    float  totalA = 0,
           totalB = 0, 
           totalDia = 0, 
           importe, 
           importePeaje, 
           gastos, 
           promGastos;



    for(i = 0; i < 14; i++) {
        system("clear");
        printf("Agregar gastos de la combi %c\n", combi);
        printf("Ingrese la cantidad de KM recorridos: ");
        scanf("%d", &km);
        printf("Ingrese el importe: ");
        scanf("%f", &importe);

        printf("Hubo gastos de peaje ? (S/N): ");
        scanf(" %c", &peaje);

        if(peaje == 'S' || peaje == 's') {
            printf("Leer el importe del peaje: ");
            scanf("%f", &importePeaje);
            totalDia += importe + importePeaje;
            gastos = importe + importePeaje;
            acuKm += km;
        }else {
            totalDia += importe;
            gastos = importe;
            acuKm += km;
        }

        if (ban == 1) {
            maxRecorrido = km;
            maxCombi = combi;
            maxDia = dia;
            ban = 0;
        } else if(maxRecorrido < km) {
            maxRecorrido = km;
            maxCombi = combi;
            maxDia = dia;
        }

        if(combi == 'A') {
            totalA += gastos;
            combi = 'B';
        } else {
            system("clear");
            printf("Resultados diarios\n\n");
            totalB += gastos;
            promGastos = totalDia / acuKm;
            acuKm = 0;
            combi = 'A';
            dia  ++;

            printf("El promedio de gastos por km es: %f\n", promGastos);
            printf("Gastos del dia: %f\n", totalDia);
            totalDia = 0;

            printf("Presione s para continuar ....");
            scanf(" %c", &pause);
        }
    }
    system("clear");
    printf("El mayor recorrido es: Recorrido %d Combi %c Dia: %d\n", maxRecorrido, maxCombi, maxDia);
    printf("Total de gastos de A %f\n", totalA);
    printf("Total de gastos de B %f\n",totalB);


    return 0;
}
