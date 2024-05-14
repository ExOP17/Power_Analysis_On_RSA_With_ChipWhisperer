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
#include "gmp-6.3.0/gmp.h"

#include "utils/global_variable.h"


// RsaKey global_key = {0};
// SecretData global_sd = {0};

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
    Send `d` to the computer (currently, this return the full key struct, for debug purpose)
    */
    // simpleserial_addcmd('p', 16, get_pt);

    simpleserial_addcmd('g', 0, gen_key);
    simpleserial_addcmd('a', 0, get_d);
    simpleserial_addcmd('e', 0, cmd_encrypt);
    simpleserial_addcmd('d', 0, cmd_decrypt);
    simpleserial_addcmd('s', 8, cmd_set_e);
    // simpleserial_addcmd('s', 16, set_key);
    // simpleserial_addcmd('p', 16, get_pt);

    // look for simpleserial packets
    while(1)
        simpleserial_get();

    return 0;
}