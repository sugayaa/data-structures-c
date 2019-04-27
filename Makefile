listFiles= linkedList, dynamicStack, staticStack, staticQueue
ext		 = .o		
all: clean compile pack

compile: linkedList.c dynamicStack.c staticStack.c staticQueue.c
	gcc -Wall -Wextra -Wpedantic -g linkedList.c
	gcc -Wall -Wextra -Wpedantic -g dynamicStack.c
	gcc -Wall -Wextra -Wpedantic -g staticStack.c
	gcc -Wall -Wextra -Wpedantic -g staticQueue.c
pack: linkedList.o dynamicStack.o staticStack.o staticQueue.o
	gcc -Wall -Wextra -Wpedantic -g linkedList.o -o linkedList
	gcc -Wall -Wextra -Wpedantic -g dynamicStack.o -o dynamicStack
	gcc -Wall -Wextra -Wpedantic -g staticStack.o -o staticStack
	gcc -Wall -Wextra -Wpedantic -g staticQueue.o -o staticQueue

clean:
	rm -f $(listFiles) 2>/dev/null
	rm -f *.o
