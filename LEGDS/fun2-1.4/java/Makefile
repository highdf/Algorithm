.PHONY:all run

CC:=javac
RUN:=java

SRC_DIR:=src
BIN_DIR:=bin

SRC_FILE:=$(wildcard $(SRC_DIR)/*.java)

MAIN:=Main
MAIN_FILE:=Main.java

all:$(SRC_FILE) $(MAIN_FILE)
	$(CC) -d $(BIN_DIR) $^

run:
	$(RUN) -cp $(BIN_DIR) $(MAIN)
