tool: $(addprefix src/, helpers.h help.o main.c offset.o list.o override.o)
	gcc -m32 -g -c src/main.c -o src/main.o
	gcc -m32 -g -Wall -o tool $(addprefix src/, help.o main.o list.o offset.o override.o)

src/list.o: src/list.c
	gcc -m32 -g -c src/list.c -o src/list.o

src/offset.o: src/offset.c
	gcc -m32 -g -c src/offset.c -o src/offset.o

src/override.o: src/override.c
	gcc -m32 -g -c src/override.c -o src/override.o

src/help.o: src/help.c
	gcc -m32 -g -c src/help.c -o src/help.o

clean:
	@ rm -rf tool src/*.o


