#include "../utils/utils.h"
#include "../utils/key.h"


// extern RsaKey global_key;
// extern SecretData global_sd;

uint8_t gen_key(uint8_t * pt, uint8_t len)
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
    
    // set_key()
    // global_key = (RsaKey){n, e, d, p, q, phi};
    return 0x00;
}