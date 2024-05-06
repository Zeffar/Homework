CXX = g++
CXXFLAGS = -std=c++23 -O2

TARGET = Medic

all: $(TARGET)

$(TARGET): Medic.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) Medic.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)