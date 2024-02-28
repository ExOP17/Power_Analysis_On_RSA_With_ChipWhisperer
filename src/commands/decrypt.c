#include "../utils/utils.h"
#include "../utils/global_variable.h"
#include <inttypes.h>
// extern RsaKey global_key;
// extern SecretData global_sd;

uint8_t cmd_decrypt(uint8_t * pt, uint8_t len)
{
    trigger_high();
    big_int res = decrypt(global_sd.ct, global_key.d, global_key.n);
    trigger_low();

	uint8_t d_as_bytes[64] = {0};
    sprintf(d_as_bytes, "pt=%lu", res);

    set_global_sd_ct(res);
   	simpleserial_put('r', 64, d_as_bytes);

	// https://chipwhisperer.readthedocs.io/en/latest/simpleserial.html
    return 0;
}