# Déclaration des variables
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

# Cibles (targets)
all: transitscan

# Construction de l'exécutable principal
transitscan: src/main.cc src/NEQLI.cc src/FANEQLI.cc
	$(CXX) $(CXXFLAGS) -o transitscan src/main.cc src/NEQLI.cc src/FANEQLI.cc

# Nettoyage des fichiers objets et exécutables
clean:
	rm -f transitscan

