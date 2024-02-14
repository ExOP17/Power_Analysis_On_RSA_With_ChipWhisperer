#include "key.h"
#include "utils.h"

RsaKey global_key = {0};

void set_key(big_int d)
	{
		global_key.d = d;
	}
	



