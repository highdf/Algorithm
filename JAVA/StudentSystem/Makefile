.PHONY:run all

SRC_DIR:=src
BIN_DIR:=bin

SOURCE:=$(wildcard src/core/*.java)
SUFFIX:=.java
MAIN:=Main

PACK:=core
CLASS:=$(PACK).$(MAIN)

all: $(SOURCE) $(SRC_DIR)/$(MAIN)$(SUFFIX)
	javac -d bin -sourcepath src $^

run:
	java -cp bin $(MAIN)

clean:
