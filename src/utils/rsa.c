#include "utils.h"

RsaKey gen_key()
{
    // srand(0);

    // big_int p = rand();
    // big_int q = rand();
    big_int p = 7;
    big_int q = 5;

    big_int phi = (p-1)*(q-1);
    big_int n = p*q;

    big_int e = 0;
    for(big_int i = 3; i < n; i++)
    {
        if (gcd(phi, i) == 1)
        {
            e = i;
            break;
        }
    }

    big_int d = inverse_mod(e,phi);
    
    global_key = (RsaKey){n, e, d, p, q, phi};
    return global_key;
}

void show_key(RsaKey rk)
{
    printf("Public key = (%lu, %lu)\n", rk.e, rk.n);
    printf("Private key = (%lu, %lu)\n", rk.d, rk.n);
    printf("(p, q, phi) = (%lu, %lu, %lu)\n", rk.p, rk.q, rk.phi);

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