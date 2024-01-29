#include "utils.h"

big_int encrypt(big_int m, big_int e, big_int N)
{
    return poow(m, e, N);
}

big_int decrypt(big_int c, big_int d, big_int N)
{
    return poow(c, d, N);
}