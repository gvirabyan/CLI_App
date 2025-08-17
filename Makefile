TARGET = CLI_App 

SRCS = $(wildcard *.cpp)
OBJ = $(SRCS:.cpp=.o)
CXX = g++


$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)
%.o: %.cpp
	$(CXX) -c $< -o $@
clean:
	rm -f $(TARGET) $(OBJ)
