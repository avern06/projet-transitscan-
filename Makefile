CXX = g++
CXXFLAGS = -Wall -std=c++11

all: transitscan

transitscan: src/main.cc src/NEQLI.cc src/FANEQLI.cc
    $(CXX) $(CXXFLAGS) -o transitscan src/main.cc src/NEQLI.cc src/FANEQLI.cc
clean:
    rm -f transitscan

