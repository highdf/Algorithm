.PHONY:all run

CC:=gcc

SRC_DIR:=src
BIN_DIR:=bin

SRC_FILE:=$(wildcard $(SRC_DIR)/*.c)

MAIN_FILE:=main.c
TARGET:=out

all:$(SRC_FILE) $(MAIN_FILE)
	$(CC) $^ -o $(BIN_DIR)/$(TARGET)

run:
	$(BIN_DIR)/$(TARGET)
