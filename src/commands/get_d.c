#include "../utils/utils.h"
#include "../utils/global_variable.h"

// extern RsaKey global_key;
// extern SecretData global_sd;

uint8_t get_d(uint8_t * pt, uint8_t len)
{

	uint8_t d_as_bytes[64] = {0};
	sprintf(d_as_bytes, "n=%lu e=%lu d=%lu p=%lu q=%lu phi=%lu", global_key.n, global_key.e, global_key.d, global_key.p, global_key.q, global_key.phi);
   	simpleserial_put('r', 64, d_as_bytes);

    return 0x00;
}