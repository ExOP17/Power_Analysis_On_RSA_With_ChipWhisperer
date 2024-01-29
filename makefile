test:
	gcc -Wall -Wextra src/test.c src/utils/*.c -o prog

# what the final build file will be called
TARGET = simpleserial-homemade-rsa
# our C firmware file
SRC += simpleserial-homemade-rsa
# Use simpleserial 2
SS_VER = SS_VER_2_1
# No crypto required
CRYPTO_TARGET = NONE
# Choosing platform
PLATFORM = CW308_STM32F3

# Path of the firmware folder
FIRMWAREPATH = ~/Documents/Ecole/ENSIBS/PEI-2/ProjetPluri/le_tool_chipwhisperer/chipwhisperer/hardware/victims/firmware

# include other required build files
include $(FIRMWAREPATH)/simpleserial/Makefile.simpleserial
include $(FIRMWAREPATH)/Makefile.inc
