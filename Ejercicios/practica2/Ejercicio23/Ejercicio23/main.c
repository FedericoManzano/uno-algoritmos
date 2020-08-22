#include <stdio.h>
#include <stdlib.h>

int main()
{
    int posmen[5] = {0};
    int pos = 0;
    int num;
    int menor;

    printf("Ingrese el numero: ");
    scanf("%d", &num);

    menor = num;
    posmen[pos] = 1;
    pos ++;
    int i;

    for(i = 1; i < 5; i ++) {
        printf("Ingrese el numero: ");
        scanf("%d", &num);
        if(num == menor) {
            posmen[pos] = i + 1;
            pos ++;
        } else if(num < menor) {
            menor = num;
            pos = 0;
            posmen[pos] = i + 1;
            pos ++;
        }
    }

    printf("El menor es: %d \n", menor);

    for(i = 0; i < pos; i ++)
        printf("Pos: %d\n", posmen[i]);

    return 0;
}
