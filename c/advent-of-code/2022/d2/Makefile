CC=gcc
FLAGS=-std=c17 -Wall -Wextra -pedantic
FLAGS+=-Werror -I../../../../libchall/c
INPUT=main.c


default:
	$(CC) $(FLAGS) $(INPUT)

check:
	valgrind --leak-check=full ./a.out
