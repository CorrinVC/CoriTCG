CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++23 -ggdb

BIN		:= bin

SRC		:= src
CARDS   := src/Cards
INPUT   := src/Input
PROFILE := src/Profile
STATES  := src/States
UI      := src/UI

FILES   := $(SRC)/*.cpp $(CARDS)/ExpansionID.cpp $(CARDS)/Expansions/Expansions.cpp $(INPUT)/*.cpp $(PROFILE)/*.cpp $(STATES)/*.cpp $(UI)/*.cpp

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
