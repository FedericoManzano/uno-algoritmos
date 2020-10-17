#include <stdio.h>
#include <stdlib.h>

long potencia(long num, int pot) {
    int i;
    long res = 1;
    if(pot == 0)
        return 1;
    if(pot < 0)
        return -1;
    if(pot == 1) 
        return num;
    for(i = 1; i <= pot; i++)
        res *= num;
    return res;
}