#include "utils.h"
#include "key.h"

// extern RsaKey global_key;
// extern SecretData global_sd;

void show_key(RsaKey rk)
{
    printf("Public key = (%llu, %llu)\n", rk.e, rk.n);
    printf("Private key = (%llu, %llu)\n", rk.d, rk.n);
    printf("(p, q, phi) = (%llu, %llu, %llu)\n", rk.p, rk.q, rk.phi);

    return;
}

big_int encrypt(big_int m, big_int e, big_int N)
{
    return poow(m, e, N);
}

big_int decrypt(big_int c, big_int d, big_int N)
{
    return poow(c, d, N);
}