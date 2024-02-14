// Chipwhisperer things
#include "hal.h"
#include "simpleserial.h"

// Our thingss
#include "utils/utils.h"

// Libc things
#include <stdio.h>
#include <string.h>
#include <stdint.h> 
#include <stdlib.h>
#include <math.h>

// RsaKey global_key;

int main(void)
{
    // Setup
    platform_init();
    init_uart();
    trigger_setup();
    simpleserial_init();

    // Init a global variable with a key

    // Defining commands
    /*
		1. `gen_key` : (big_int p, big_int q, big_int e)
	Set p, q, e and compute N, phi and d

		2. `encrypt` : (big_int m)
	Set m and compute c with c = m^e mod N
    We need to trigger the capture trace to retrieve `e`

		3. `decrypt` : (big_int c) 
	Set c and compute m with m = c^d mod N
    We need to trigger the capture trace to retrieve `d`

        4. `get_d` : (big_int c) 
    Send `d` to the computer
    */
    simpleserial_addcmd('p', 16, get_pt);
    simpleserial_addcmd('g', 16, RSA_gen_key);
    // simpleserial_addcmd('s', 16, set_key);
    // simpleserial_addcmd('p', 16, get_pt);

    // simpleserial_addcmd('e', 16, TODO);
    // simpleserial_addcmd('d', 16, TODO);

    // look for simpleserial packets
    while(1)
        simpleserial_get();

    return 0;
}