#ifndef _GLOBAL_VARIABLE_H_
#define _GLOBAL_VARIABLE_H_

#include "utils.h"


extern RsaKey global_key; 
extern SecretData global_sd;

void set_global_key(RsaKey rsa_key);
void set_global_sd(SecretData sd);
void set_global_sd_pt(big_int pt);
void set_global_sd_ct(big_int ct);



#endif