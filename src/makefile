# what the final build file will be called
TARGET = simpleserial-homemade-rsa
# our C firmware file
SRC += simpleserial-homemade-rsa.c
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