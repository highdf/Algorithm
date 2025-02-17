.PHONY:all run

SRC_DIR:=src
BIN_DIR:=bin

SRC_FILE:=$(wildcard $(SRC_DIR)/*.c)
MAIN_FILE:=main.c

all:$(MAIN_FILE) $(SRC_FILE)
	gcc $^ -o $(BIN_DIR)/out

run:
	@( ~/Algorithm/LEGDS/fun1-1.1/c/bin/out )
