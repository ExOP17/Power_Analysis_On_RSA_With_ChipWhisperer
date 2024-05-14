#include "../utils/utils.h"
#include "../utils/global_variable.h"

// extern RsaKey global_key;
// extern SecretData global_sd;

uint8_t gen_key(uint8_t * pt, uint8_t len)
{
    // srand(0);

    // big_int p = rand();
    // big_int q = rand();
    // big_int p = 16411;
    // big_int q = 16447;

    // big_int phi = (p-1)*(q-1);
    // big_int n = p*q;

    // big_int e = 0;
    // for(big_int i = 500; i < n; i++)
    // {
    //     if (gcd(phi, i) == 1)
    //     {
    //         e = i;
    //         break;
    //     }
    // }

    // big_int d = inverse_mod(e,phi);
    
    // set_key()

    // 0b11111111111111
    // struct RsaKey : n, e, d, p, q, phi,;
    RsaKey temp = {(big_int)269911717, (big_int)0b1, (big_int)173278623, (big_int)16411, (big_int)16447, (big_int)269878860};
    // RsaKey temp = {n, (big_int)0b11111111111111, d, p, q, phi};
    set_global_key(temp);
    set_global_sd_pt((big_int)0b111111111);

	return 0x00;
}