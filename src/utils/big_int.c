#include <stdlib.h>
#include <stdint.h>


#define LEN 256
#define BLOCK_SIZE 256

typedef struct u_int_2048
{
    uint8_t value[LEN]; 
} u_int_2048;

u_int_2048 add(u_int_2048 a, u_int_2048 b)
{
    int i;
    u_int_2048 res;
    uint16_t carry = 0; 
    for (i = LEN - 1; i >= 0; i--)
    {
        uint16_t sum = (uint16_t)a.value[i] + (uint16_t)b.value[i] + carry;
        res.value[i] = (uint8_t)(sum % BLOCK_SIZE);
        carry = sum / BLOCK_SIZE; 
    }
    return res;
}


void initialize(u_int_2048 *a)
{
    for (int i = 0; i < LEN; i++)
    {
        a->value[i] = 0;
    }
}

u_int_2048 mul(u_int_2048 a, u_int_2048 b)
{
    u_int_2048 res;
    int i, j;
    uint16_t carry = 0;
    uint16_t tmp;

    initialize(&res);

    for (i = LEN - 1; i >= 0; i--)
    {
        carry = 0;
        u_int_2048 prd;
        initialize(&prd);

        for (j = LEN - 1; j >= 0; j--)
        {
            
            if (j-(LEN-1-i) >0)
            {
                tmp = (uint16_t)(a.value[i]) * (uint16_t)(b.value[j]) + carry;
                prd.value[j-(LEN-1-i)] = tmp % 256;
                carry = tmp / 256;
                if(tmp!= 0)printf("\n%d\n",tmp);
            }
        }

        
        res = add(res, prd);
    }

    return res;
}

