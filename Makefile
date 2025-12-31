#
#       makefile for Ohm Engine
#       by Jaidev Bormann
#


#	much love ChatGPT
#	I have no clue how Makefile works (kind of)


CC      = gcc
CFLAGS  = -Wall -Wextra -mconsole -std=c11 -g
LDFLAGS = -luser32 -lgdi32 -lkernel32


SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin


SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
EXEC = $(BIN_DIR)/ohm_engine


all: $(EXEC)


$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LDFLAGS)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


run:
	./$(BIN_DIR)/ohm_engine


clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/ohm_engine


.PHONY: all clean

