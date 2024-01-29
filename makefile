test:
	gcc -Wall -Wextra src/test.c src/utils/*.c -o prog

zip:
	zip -r Releases/GameSourceCode-$(shell date +"%d_%m_%Y".zip) *
