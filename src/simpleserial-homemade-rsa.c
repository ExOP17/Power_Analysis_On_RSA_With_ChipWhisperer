#include "hal.h"
#include "simpleserial.h"
#include "utils/utils.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

big_int p = 11;
big_int q = 17;
big_int N = p * q;

big_int phi = (p-1) * (q-1);
big_int e = 7;
big_int m = 78;
big_int d = inverse_mod(e, phi);

int main(void)
{
    // Setup
    platform_init();
    init_uart();
    trigger_setup();
    simpleserial_init();

    // Defining commands
    /*
		1. `set_key` : (big_int p, big_int q, big_int e)
	Set p, q, e and compute N, phi and d

		2. `encrypt` : (big_int m)
	Set m and compute c with c = m^e mod N

		3. `decrypt` : (big_int c) 
	Set c and compute m with m = c^d mod N
    */
    simpleserial_addcmd('p', 16, xor_inc);
    simpleserial_addcmd('k', 16, get_key);

    // look for simpleserial packets
    while(1)
        simpleserial_get();
}