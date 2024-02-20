#include "utils.h"
#include "global_variable.h"

// extern RsaKey global_key;
// extern SecretData global_sd;

big_int bytes_to_big_int(int n, uint8_t* v)
{
    int p = 0; 
    int res = 0;
    for(int i = n-1; i>=0;i--)
    {
        res += v[i] * poow(256,p,10000);
        p++;
    }
    return res; 
}

big_int poow(big_int base, big_int exposant, big_int modulus)
{ 
    // base %= modulus;
    big_int inutilus = 0xabcd;
    big_int res = 1;
    // exposant %= modulus;


    while(exposant > 0)
    {
        if(exposant & 1)
        {
            res = (res * base) % modulus;

            inutilus = inutilus * 17 + 1;
            inutilus = inutilus * 17 + 1;
            inutilus = inutilus * 17 + 1;
            inutilus = inutilus * 17 + 1;
            // inutilus = inutilus * 17 + 1;
            // inutilus = inutilus * 17 + 1;
            // inutilus = inutilus * 17 + 1;
            // inutilus = inutilus * 17 + 1;
            // inutilus = inutilus * 17 + 1;
            // inutilus = inutilus * 17 + 1;
            // inutilus = inutilus * 17 + 1;
            // inutilus = inutilus * 17 + 1;
            // inutilus = inutilus * 17 + 1;
        }
        
        base = (base * base) % modulus;
        exposant >>= 1;
        // break;
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

// Taken from https://www.geeksforgeeks.org/gcd-in-c/
big_int gcd(big_int a, big_int b) 
{ 
    // Find Minimum of a and b 
    big_int result = ((a < b) ? a : b); 
    while (result > 0) { 
        // Check if both a and b are divisible by result 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    } 
    // return gcd of a nd b 
    return result; 
} 

void swap(big_int *a, big_int *b)
{
    *a = *b ^ *a;
    *b = *b ^ *a;
    *a = *b ^ *a;

    return;
}