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

    // tell simpleserial_get to look for 'p' and 'k' packets
    // and to do these two functions when they're received
    simpleserial_addcmd('p', 16, xor_inc);
    simpleserial_addcmd('k', 16, get_key);

    // look for simpleserial packets
    while(1)
        simpleserial_get();
}