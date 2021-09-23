# list/Makefile
#
# Makefile for list implementation and test file.
#
# Camryn Belcher

list: main.c
	gcc -o main list.c main.c
	
clean:
	rm main