#ifndef _UTILS_H_
#define _UTILS_H_

/*
	* TODO : Implenting our own big_int library
*/

// Types definition
typedef uint64_t big_int;

// Prototypes
big_int poow(big_int base, big_int exposant, big_int modulus); // pow(b, e, N) = b^e mod N
big_int inverse_mod(big_int a, big_int n); // inv(a, N) = b with b * a = 1 mod N
big_int encrypt(big_int m, big_int e, big_int N); // c = m^e mod N
big_int decrypt(big_int c, big_int d, big_int N); // m = c^d mod N
void swap(big_int *a, big_int *b); // Swapping two variables




#endif