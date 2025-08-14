TARGET = CLI_App 
SRCS = main.cpp Widget.cpp Button.cpp Table.cpp Text.cpp Window.cpp CommandExecutor.cpp
CXX = g++

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
