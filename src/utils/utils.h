#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/*
	* TODO : Implenting our own big_int library
*/

// Types definition
typedef uint64_t big_int;

typedef struct RsaKey RsaKey;
struct RsaKey {
    big_int n;
    big_int e;
    big_int d;
    big_int p;
    big_int q;
    big_int phi;
};

typedef struct SecretData SecretData;
struct SecretData {
    big_int pt;
    big_int ct;
};

// Global variable
// static RsaKey global_key = {0};

// Prototypes
void show_key(RsaKey rk);
big_int gcd(big_int a, big_int b);
RsaKey gen_key();
big_int bytes_to_big_int(int n, uint8_t* v);
big_int poow(big_int base, big_int exposant, big_int modulus); // pow(b, e, N) = b^e mod N
big_int inverse_mod(big_int a, big_int n); // inv(a, N) = b with b * a = 1 mod N
big_int encrypt(big_int m, big_int e, big_int N); // c = m^e mod N
big_int decrypt(big_int c, big_int d, big_int N); // m = c^d mod N
void swap(big_int *a, big_int *b); // Swapping two variables

#endif