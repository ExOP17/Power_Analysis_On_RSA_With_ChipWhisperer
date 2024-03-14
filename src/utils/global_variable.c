#include "global_variable.h"
#include "utils.h"

RsaKey global_key = {0};
SecretData global_sd = {0};
big_int global_bs = 0;

void set_global_key(RsaKey rsa_key)
{
	// global_key.n = rsa_key.n;
	// global_key.e = rsa_key.e;
	// global_key.d = rsa_key.d;
	// global_key.d = rsa_key.d;
	// global_key.p = rsa_key.p;
	// global_key.q = rsa_key.q;
	// global_key.phi = rsa_key.phi;

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

void set_global_bs(big_int bs)
{
	global_bs = bs;
}

