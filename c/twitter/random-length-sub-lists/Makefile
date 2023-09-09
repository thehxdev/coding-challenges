CC := gcc
CFLAGS := -std=c17 -Wall -Wextra -pedantic
CFLAGS += -Werror -Wno-unused-result -Wno-unused-variable
CFLAGS += -ggdb -Og
LIBS :=

SRC_DIR := ./src

BIN := a.out
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
O_FILES := $(SRC_FILES:.c=.o)


$(BIN): $(O_FILES)
	$(CC) -o $(BIN) $(O_FILES) $(LIBS)


%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/$*.c


check:
	valgrind --leak-check=full ./$(BIN)


clean:
	rm -rf $(BIN) $(SRC_DIR)/*.o
