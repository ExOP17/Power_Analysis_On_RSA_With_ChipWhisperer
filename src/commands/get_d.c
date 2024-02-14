#include "../utils/utils.h"

extern RsaKey global_key;
extern SecretData global_sd;

uint8_t get_d(uint8_t * pt, uint8_t len)
{
	uint8_t d_as_bytes[8];
	sprintf(d_as_bytes, "%llu", get_value());

    // simpleserial_put('r', 8, d_as_bytes);
    return 0;
}