CC		:= g++
C_FLAGS := -std=c++17

BIN		:= bin
SRC		:= src
INCLUDE	:=  -Iinclude
LIB		:= lib

LIBRARIES	:=

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= main.exe
else
EXECUTABLE	:= main
endif

all: $(BIN)/$(EXECUTABLE)

clean:
	$(RM) $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*
	$(CC) $(C_FLAGS) $(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)