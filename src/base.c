#include "hal.h"
#include "simpleserial.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t d = 3;
uint64_t n = 0x61d9abf2;
uint64_t c = 0x5f4a3dc8;

uint8_t rsa_set_d(uint8_t * pt, uint8_t len) {
    d = *(uint64_t*)pt;
    // char num[32];
    // sprintf(num, "d=%llx\n", d);
    // simpleserial_put('r', 32, num);
    return 0;
}
uint8_t rsa_decrypt(uint8_t * pt, uint8_t len) {
    trigger_high();

    uint64_t res = 1;
    uint64_t base = c;
    uint64_t exp = d;
    uint16_t dummy = 0xabcd;

    while (exp) {
        if (exp & 1) {
            res = (res * base) % n;
            
            // dummy operations
            // to simulate the fact
            // that general multiplication
            // is slower than squaring
            // (in optimized bigints)
            // see https://stackoverflow.com/questions/1377430/why-is-squaring-a-number-faster-than-multiplying-two-random-numbers
            dummy = dummy * 17 + 1;
            dummy = dummy * 17 + 1;
            dummy = dummy * 17 + 1;
            dummy = dummy * 17 + 1;
            
        }
        base = (base * base) % n;
        
        exp >>= 1;
    }

    trigger_low();
    return dummy;
}

int main(void)
{
    platform_init();
    init_uart();
    trigger_setup();

    simpleserial_init();
    simpleserial_addcmd('k', 8,  rsa_set_d);
    simpleserial_addcmd('d', 0, rsa_decrypt);

    while(1) {
        simpleserial_get();
    }
}