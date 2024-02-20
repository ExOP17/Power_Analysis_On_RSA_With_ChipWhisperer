#ifndef _BIG_INT_H_
#define _BIG_INT_H_

#define LEN 256
#define BLOCK_SIZE 256

typedef struct u_int_2048
{
    uint8_t value[LEN]; 
} u_int_2048;

u_int_2048 add(u_int_2048 a, u_int_2048 b);
void initialize(u_int_2048 *a);
u_int_2048 mul(u_int_2048 a, u_int_2048 b);

#endif