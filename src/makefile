# what the final build file will be called
TARGET = simpleserial-homemade-rsa
# our C firmware file
SRC += simpleserial-homemade-rsa.c
SRC += utils/math.c
SRC += utils/rsa.c
SRC += utils/global_variable.c
SRC += commands/encrypt.c
SRC += commands/decrypt.c
SRC += commands/gen_key.c
SRC += commands/get_d.c
# SRC += utils/*.c
# SRC += commands/*.c
# Use simpleserial 1
SS_VER = SS_VER_1_1
# No crypto required
CRYPTO_TARGET = NONE
# Choosing platform
PLATFORM = CW303

# Path of the firmware folder
# You need to change this variable according to your firmware path
FIRMWAREPATH = ../../chipwhisperer/hardware/victims/firmware

# include other required build files
include $(FIRMWAREPATH)/simpleserial/Makefile.simpleserial
include $(FIRMWAREPATH)/Makefile.inc