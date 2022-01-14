#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "mathp.h"
#include "mod.h"
#include "primo.h"
  
int main(int argc, char** argv) {
    int quant = argc;
    puts("---------------");
    long int* p = calloc(quant - 1, sizeof(long int));
    for (int i = 1; i < quant; i++)
        p[i - 1] = atof(argv[i]);

    quant--;

    for (int i = 0; i < quant; i++)
        printf("p%d = %ld\n", i, p[i]);
    puts("---------------");

    long int N = 1;
    for (int i = 0; i < quant; i++)
        N *= p[i];
    printf("N = %ld\n", N);
    puts("---------------");

    long int fiN = 1;
    for (int i = 0; i < quant; i++)
        fiN *= p[i] - 1;
    printf("fiN = %ld\n", fiN);
    puts("---------------");

    long int e = coprimo(fiN);
    printf("e = %ld\n", e);
    puts("---------------");

    long int d = inverse(e, fiN);
    printf("d = %ld\n", d);
    puts("---------------");

    long int C = mod(potencia(77, e), N);
    printf("C = %ld\n", C);
    puts("---------------");

    long int* dn = calloc(quant, sizeof(long int));

    for (int i = 0; i < quant; i++) {
        dn[i] = mod(d, p[i] - 1);
        printf("D%d = %ld\n", i, dn[i]);
    }
    puts("---------------");

    long int* Mn = calloc(quant, sizeof(long int));

    for (int i = 0; i < quant; i++) {
        Mn[i] = mod(potencia(C, dn[i]), p[i]);
        printf("M%d = %ld\n", i, Mn[i]);
    }
    puts("---------------");

    long int x = 0;
    for (int i = 0; i < quant; i++)
        x += Mn[i] * N / p[i] * inverse(N / p[i], p[i]);
    x = mod(x, N);
    printf("x = %ld\n", x);
    puts("---------------");

    return 0;
}