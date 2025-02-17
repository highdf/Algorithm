.PHONY:all run

SRC_DIR:=src
BIN_DIR:=bin

SRC_FILE:=$(wildcard $(SRC_DIR)/.java)
MAIN_CLASS:=Main
SUFFIX:=.java
MAIN_FILE:=$(MAIN_CLASS)$(SUFFIX)

all:$(SRC_FILE) $(MAIN_FILE)
	javac -d bin $^

run:
	java -cp $(BIN_DIR) $(MAIN_CLASS)
