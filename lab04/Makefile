CXX       := g++
CXX_FLAGS := -std=c++23 -ggdb

BIN			:= bin
SOURCE    	:= src
INCLUDE 	:= include
EXECUTABLE  := main.exe
LIBRARIES   :=


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SOURCE)/*.cpp 
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*