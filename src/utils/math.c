#include "utils.h"

big_int poow(big_int base, big_int exposant, big_int modulus)
{ 
    base %= modulus;
    exposant %= modulus;

    big_int res = 1;

    while(exposant > 0)
    {
        if(exposant & 1)
        {
            res = (res * base) % modulus;
        }
        
        base = (base * base) % modulus;
        exposant >>= 1;
    }
    
    return res;
}

big_int inverse_mod(big_int a, big_int n)
{
    if (a < n)
        swap(&a, &n);
    
    big_int new_a = a, new_n = n;

    big_int u  = 1, v  = 0;
    big_int uu = 0, vv = 1;

    big_int old_n = 0, q  = 0;
    big_int old_u, old_v;

    while (n != 0)
    {
        q = a / n;

        old_n = n;
        n = a - q*n;
        a = old_n;

        old_u = u, old_v = v;
        u = uu, v = vv;
        uu = old_u - q*uu, vv = old_v - q*vv;
    }
    
    if(new_a == a)
    {
        return (u % new_n);
    } else {
        return (v % new_a);
    }
}

void swap(big_int *a, big_int *b)
{
    *a = *b ^ *a;
    *b = *b ^ *a;
    *a = *b ^ *a;

    return;
}