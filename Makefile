CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin

SRC		:= src
STATES  := src/States
UI      := src/UI
INPUT   := src/Input
CARDS 	:= src/Cards

FILES   := $(SRC)/*.cpp $(STATES)/*.cpp $(UI)/*.cpp $(INPUT)/*.cpp $(CARDS)/*.cpp

INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXECUTABLE	:= coriTCG


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)
 
$(BIN)/$(EXECUTABLE): $(FILES)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
