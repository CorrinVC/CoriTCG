CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++23 -ggdb

BIN		:= bin

SRC		:= src
INPUT   := src/Input
STATES  := src/States
UI      := src/UI

FILES   := $(SRC)/*.cpp src/Cards/ExpansionID.cpp src/Cards/Expansions/Expansions.cpp $(INPUT)/*.cpp $(STATES)/*.cpp $(UI)/*.cpp

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
