#include <stdio.h>
#include "utils/utils.h"

int main(void)
{
	big_int p = 11;
	big_int q = 17;
	big_int N = p * q;

	big_int phi = (p-1) * (q-1);
	big_int e = 7;
	big_int m = 69;
	big_int d = inverse_mod(e, phi);

	big_int c = encrypt(m, e, N);

	printf("All parameters: \n");
	printf("p = %llu ; q = %llu ; N = %llu ; e = %llu ; phi = %llu ; d = %llu\n", p, q, N, e, phi, d);

	printf("Public key : \n");
	printf("(e, N) = (%llu, %llu)\n", e, N);

	printf("Private key : \n");
	printf("(d, N) = (%llu, %llu)\n", d, N);

    printf("We are encrypting m = %llu in c = %llu\n", m, encrypt(m, e, N));

    big_int new_m = decrypt(c, d, N);
    printf("And after decrypting c = %llu we get m = %llu\n", c, new_m);

    printf("Hope this return `1` : %d\n", new_m == m);

	return 0;
}