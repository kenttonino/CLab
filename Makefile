ERROR_FLAGS= -Werror -Wfatal-errors -Wpedantic -Wall
THREAD_FLAGS = -pthread

build:
	gcc ${ERROR_FLAGS} ${THREAD_FLAGS} -g -o ./bin/CLab ./src/main.c

debug: build
	gdb ./bin/CLab

run: build
	./bin/CLab
