#include "../utils/utils.h"
#include "../utils/key.h"

// extern RsaKey global_key;
// extern SecretData global_sd;

uint8_t get_d(uint8_t * pt, uint8_t len)
{

	set_key(10);
	short int test = 50;

	if(global_key.d == (big_int)10)
	{
		uint8_t d_as_bytes[60];
		// sprintf(d_as_bytes, "d", test);
// 
		sprintf(d_as_bytes, "d=%lu\n", global_key.d);
		// d=5

    	simpleserial_put('r', 60, d_as_bytes);
	} else {
		char a[8] = "aaaaaaaa";
    	simpleserial_put('r', 8, a);
	}

	// big_int a = 36;

	// sprintf(d_as_bytes, "%llu", a);

    // simpleserial_put('r', 8, d_as_bytes);
    return 0;
}