#include "mathp.h"

#include <stdio.h>

long int resto(long int num1, long int num2) {
    return num1 - num2 * (num1 / num2);
}

long int potencia(long int num1, long int num2) {
    long int out = 1;
    for (int i = 0; i < num2; i++)
        out *= num1;
    return out;
}