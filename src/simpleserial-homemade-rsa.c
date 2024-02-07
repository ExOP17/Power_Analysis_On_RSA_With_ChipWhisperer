// Chipwhisperer things
#include "hal.h"
#include "simpleserial.h"

// Our thingss
#include "utils/utils.h"

// Libc tthingsh
#include <stdio.h>
#include <string.h>
#include <stdint.h> 
#include <stdlib.h>
#include <math.h>

const big_int p = 11;
const big_int q = 17;
const big_int N = p * q;

const data_test[16] = {0x11, 0x22, 0x33, 0x11, 0x22, 0x33, 0x11, 0x22, 0x33, 0x11, 0x22, 0x33, 0x11, 0x22, 0x33, 0x11};

big_int d = 0;
big_int phi = (p-1) * (q-1);
big_int e = 7;
big_int m = 78;
d = inverse_mod(e, phi);
big_int d = 5;

big_int key;

big_int bytes_to_big_int(int n,uint8_t* v)
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
// uint8_t set_key(uint8_t cmd, uint8_t scmd, uint8_t dlen, uint8_t* data)
// {
//     simpleserial_put('r', 16, data_test);
//     // d = *(big_int*) data;

//     // char debug_string[15];
//     // sprintf(debug_string, "pipicacaprout\n");
//     // simpleserial_put('r', 15, debug_string);

//     return 1;
// }

uint8_t get_pt(uint8_t* pt, uint8_t len)
{
    /**********************************
    * Start user-specific code here. */
    trigger_high();
    key = pt;
    //16 hex bytes held in 'pt' were sent
    //from the computer. Store your response
    //back into 'pt', which will send 16 bytes
    //back to computer. Can ignore of course if
    //not needed

    trigger_low();
    /* End user-specific code here. *
    ********************************/
    simpleserial_put('r', 16, key);
    return 0x00;
}
uint8_t RSA_gen_key(uint8_t* pt,uint8_t len)
{
    Rsa_key = gen_key();
    return 0x00;
}

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