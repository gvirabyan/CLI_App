TARGET = CLI_App

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

CXX = g++
CXXFLAGS = -I$(INC_DIR)

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ_DIR)/*.o

