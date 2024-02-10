# Define the compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Define the executable name
TARGET = Pizza

# Define the source files and object files
SRCS = main.cpp total.cpp neapolitan.cpp newyork.cpp flammkuchen.cpp sicilian.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
    rm -f $(OBJS) $(TARGET)