.PHONY:all run

SRC_DIR:=Extends
BIN_DIR:=bin

SRC_FILE:=$(wildcard $(SRC_DIR)/*.java)
SUFFIC:=.java
MAINFILE:=Main

all:$(SRC_FILE) $(MAINFILE)$(SUFFIC)
	javac -d $(BIN_DIR) $^

run:
	java -cp bin $(MAINFILE)

clean:
	rm Makrfile
