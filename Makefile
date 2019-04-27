all: compile pack linkedList
	./linkedList
compile: linkedList.c
	gcc -Wall -Wextra -Wpedantic -g linkedList.c
pack: linkedList.o
	gcc -Wall linkedList.o -o linkedList
