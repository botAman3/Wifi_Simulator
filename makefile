# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iheader  # Include header folder for headers
DEBUG_FLAGS = -g -O0
OPT_FLAGS = -O3

# Directories
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = .

# Sources and objects
SOURCES = $(SRC_DIR)/main.cpp $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Binary names
DEBUG_BIN = $(BIN_DIR)/wifi_sim_debug
OPT_BIN = $(BIN_DIR)/wifi_sim_opt

# Targets
all: $(DEBUG_BIN) $(OPT_BIN)

# Debug build
$(DEBUG_BIN): $(OBJECTS)
	$(CXX) $(DEBUG_FLAGS) -o $@ $^

# Optimized build
$(OPT_BIN): $(OBJECTS)
	$(CXX) $(OPT_FLAGS) -o $@ $^

# Object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(DEBUG_BIN) $(OPT_BIN) $(EXECUTABLE)