.PHONY:all run

SRC_DIR:=src
BIN_DIR:=bin

SRC_FILE:=$(wildcard $(SRC_DIR)/*.c)
MAIN_FILE:=main.c

all:$(SRC_FILE) $(MAIN_FILE)
	gcc $^ -o $(BIN_DIR)/out

run:
	@(/home/luky/Algorithm/LEGDS/fun1-2.1/c/bin/out)
