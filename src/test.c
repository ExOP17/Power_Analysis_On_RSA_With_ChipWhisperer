/*
	A simple test code to check that our lib is working fine !

	Build and exec : 
	gcc test.c utils/*.c -o prog && ./prog
*/


#include <stdio.h>
#include "utils/utils.h"

RsaKey global_key = {0};
SecretData global_sd = {0};

int main(void)
{
	gen_key();
	show_key(global_key);

	// big_int p = 11;
	// big_int q = 17;
	// big_int N = p * q;

	// big_int phi = (p-1) * (q-1);
	// big_int e = 7;
	// big_int m = 69;
	// big_int d = inverse_mod(e, phi);

	// big_int c = encrypt(m, e, N);

	// printf("**** Running test ****\n\n");

	// printf("All parameters: \n");
	// printf("p = %lu ; q = %lu ; N = %lu ; e = %lu ; phi = %lu ; d = %lu\n\n", p, q, N, e, phi, d);

	// printf("Public key : \n");
	// printf("(e, N) = (%lu, %lu)\n\n", e, N);

	// printf("Private key : \n");
	// printf("(d, N) = (%lu, %lu)\n\n", d, N);

    // printf("We are encrypting m = %lu in c = %lu\n", m, encrypt(m, e, N));

    // big_int new_m = decrypt(c, d, N);
    // printf("And after decrypting c = %lu we get m = %lu\n\n", c, new_m);

    // printf("Hope this return `1` : %d\n", new_m == m);
	// printf("\n**** Ending test ****\n");

	return 0;
}