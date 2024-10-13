CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror
TARGET = load_balancer

SRCS = main.cpp LoadBalancer.cpp WebServer.cpp RequestQueue.cpp Request.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean