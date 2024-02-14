#include "key.h"
#include "utils.h"

RsaKey global_key = {0};
SecretData global_sd = {0};

void set_global_key(RsaKey rsa_key)
	{
		global_key = rsa_key;
	}

void set_global_sd(SecretData sd)
	{
		global_sd = sd;
	}	

void set_global_sd_pt(big_int pt)
	{
		global_sd.pt = pt;
	}	

void set_global_sd_ct(big_int ct)
	{
		global_sd.ct = ct;
	}	

