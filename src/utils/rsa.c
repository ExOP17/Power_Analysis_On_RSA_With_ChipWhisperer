#include "utils.h"

typdef struct rsa_key Rsa_Key;
struct rsa_key{
    big_int p;
    big_int q;
    big_int e;
    big_int d;
    big_int n;
    big_int phi;
};

Rsa_key gen_key(){

    srand(2234554345147395);

    big_int p random_number = rand();
    big_int q random_number = rand();

    phi = (p-1)*(q-1);
    n = p*q;
    e = 3;
    d = inverse_mod(e,phi);
    
    return (Rsa_Key) = {p,q,e,d,n,phi};


}

big_int encrypt(big_int m, big_int e, big_int N)
{
    return poow(m, e, N);
}

big_int decrypt(big_int c, big_int d, big_int N)
{
    return poow(c, d, N);
}