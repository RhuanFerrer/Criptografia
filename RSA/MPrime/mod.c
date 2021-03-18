#include "mod.h"

#include "mathp.h"
#include "primo.h"

long int mod(long int num, long int modu) {
    return resto(num, modu);
}

long int inverse(long int num, long int modu) {
    long int out = 0;
    do {
        out++;
    } while (mod(num * out, modu) != 1);
    return out;
}