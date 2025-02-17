.PHONY:all run

SRC_DIR:=src
BIN_DIR:=bin

SRC_FILE:=$(wildcard $(SRC_DIR)/*.java)

MAIN:=Main
MAIN_FILE:=$(MAIN).java

all:$(SRC_FILE) $(MAIN_FILE)
	javac -d $(BIN_DIR) $^

run:
	java -cp $(BIN_DIR) $(MAIN)
