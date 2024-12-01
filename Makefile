Déclaration des variables

CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

Cibles (targets)

all: transitscan

Construction de l'exécutable principal

transitscan: src/main.cc src/NEQLI.cc src/FANEQLI.cc src/input.cc include/input.h
$(CXX) $(CXXFLAGS) -o transitscan src/main.cc src/NEQLI.cc src/FANEQLI.cc src/input.cc

Nettoyage des fichiers objets et exécutables

clean:
rm -f transitscan


