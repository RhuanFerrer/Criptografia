#include "primo.h"

#include <stdio.h>

#include "mathp.h"

long int coprimo(long int num) {
    int out;
    for (out = 2; out < num; out++)
        if (mdc(num, out) == 1)
            break;
    return out;
}

long int mdc(long int num1, long int num2) {
    long int out;
    do {
        out = num1 % num2;
        num1 = num2;
        num2 = out;
    } while (out != 0);
    return num1;
}