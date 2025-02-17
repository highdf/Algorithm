.phony:all run

SRC_DIR:=src
BIN_DIR:=bin

SRC_FILE:=$(wildcard $(SRC_DIR)/*.java)
MAIN_CLASS:=Main
MAIN_FILE:=Main.java

all:$(SRC_FILE) $(MAIN_FILE)
	javac -d bin $^

run:
	java -cp $BIN_DIR) $(MAIN_CLASS)
