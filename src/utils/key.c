#include "key.h"
#include "utils.h"

RsaKey global_key = {0};

void set_global_key(RsaKey rsa_key)
	{
		global_key = rsa_key;
	}
	



