.PHONY:all run

CC:=gcc
RUN:=./

SRC_DIR:=src
BIN_DIR:=bin

SRC_FILE:=$(wildcard $(SRC_DIR)/*.c)

MAIN_FILE:=main.c
OUT_FILE:=out

all:$(SRC_FILE) $(MAIN_FILE)
	$(CC) $^ -o $(BIN_DIR)/$(OUT_FILE)

run:
	$(RUN)$(BIN_DIR)/$(OUT_FILE)
