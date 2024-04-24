CXX = g++
CXXFLAGS = -std=c++23

all: build

build: task_a.cpp
	$(CXX) $(CXXFLAGS) task_a.cpp -o build
	./build

test: task_a_unfactored.cpp
	$(CXX) $(CXXFLAGS) task_a_unfactored.cpp -o build2
	./build2

clean:
	rm -f build