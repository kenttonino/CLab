ERROR_FLAGS= -Werror -Wfatal-errors -Wpedantic -Wall

build:
	gcc ${ERROR_FLAGS} -g -o ./bin/CLab ./src/main.c

debug: build
	gdb ./bin/CLab

run: build
	./bin/CLab
