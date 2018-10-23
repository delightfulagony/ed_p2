# @brief Makefile de la práctica 2 para la asignatura Estructura de Computadores del DGIIM
# @file Makefile
# @author Gonzalo Moreno Soto
# @author Manuel Gachs Ballegeer
# @license GPLv3

#Nombre del proyecto
PROJECT = cronologia

# Compilador usado
CC = g++
# Carpetas del proyecto
SRC  = ./src
OBJ  = ./obj
INC  = ./include
BIN  = ./bin
DATA = ./data
DOC  = ./doc
ZIP  = ./zip

# Compiler FLAGS
FLAGS = -Wall -g

# Valgrind FLAGS
VFLAGS = --leak-check=full

## Tests
# Tests a ejecutar con "$make tests"
TESTS = $(DATA)/*.txt

# test1
TEST1 = $(DATA)/timeline_algorithms.txt

# test2
TEST2 = $(DATA)/timeline_movies.txt

# test3
TEST3 = $(DATA)/timeline_science.txt

# test4
TEST4 = $(DATA)/timeline_worldhistory.txt

# test de valgrind
VTEST = $(DATA)/timeline_algorithms.txt

# Dependencias

all: $(PROJECT) help author

$(PROJECT): $(OBJ)/fechaHistorica.o $(OBJ)/cronologia.o $(OBJ)/$(PROJECT).o 
	$(CC) $(FLAGS) -o $(BIN)/$(PROJECT) $?

$(OBJ)/fechaHistorica.o: $(SRC)/fechaHistorica.cpp $(INC)/fechaHistorica.h
	$(CC) -I$(INC) -c -o $@ $<

$(OBJ)/cronologia.o: $(SRC)/cronologia.cpp $(INC)/cronologia.h
	$(CC) -I$(INC) -c -o $@ $<

$(OBJ)/$(PROJECT).o: $(SRC)/$(PROJECT).cpp
	$(CC) -I$(INC) -c -o $@ $<

refresh:
	touch $(SRC)/*

doxy:
	rm -rf $(DOC)/html $(DOC)/latex
	doxygen $(DOC)/$(PROJECT).doxy
	firefox $(DOC)/html/index.html

zip: $(PROJECT)
	rm -rf $(ZIP)/*
	rm -rf $(BIN)/*
	rm -rf $(OBJ)/*
	rm -rf $(DOC)/html $(DOC)/latex
	rm -rf *.bgr
	zip -r $(ZIP)/$(PROJECT).zip *
	
valgrind: $(PROJECT)
	valgrind $(VFLAGS) $(BIN)/$(PROJECT) -c $(VTEST) 

bigtest:
	./$(BIN)/$(PROJECT) $(TESTS)

test1:
	./$(BIN)/$(PROJECT) $(TEST1)

test2:
	./$(BIN)/$(PROJECT) $(TEST2)
	
test3:
	./$(BIN)/$(PROJECT) $(TEST3)
	
test4:
	./$(BIN)/$(PROJECT) $(TEST4)

help:
	@echo "________________________________________________________________________________"
	@echo "Lista de parámetros posibles:"
	@echo "		refresh		Permite volver a compilar los archivos sin modificarlos"
	@echo "		doxy		Genera la documentación"
	@echo "		zip		Genera el zip del proyecto"
	@echo "		valgrind	Realiza un test por medio de valgrind"
	@echo "		bigtest		Realiza un test que engloba a todos los test del makefile"
	@echo "		infotests	Muestra todos los tests posibles"
	@echo "		test<num>	Realiza el test <num>"
	@echo "		help		Muestra esta ayuda"
	@echo "		author		Información sobre el autor de este programa"
	@echo "________________________________________________________________________________"

author:
	@echo "Este es un proyecto realizado por Gonzalo Moreno Soto (https://github.com/delightfulagony)"
	@echo "y Manuel Gachs Ballegeer (https://github.com/Manuelbelgicano)" 
	@echo "para la asignatura de Estructura de Datos de la Universidad de Granada"

infotests:
	@echo "________________________________________________________________________________"
	@echo "Lista de tests posibles:"
	@echo "		test1		Realiza una cronología a partir del archivo timeline_algorithms.txt"
	@echo "		test2		Realiza una cronología a partir del archivo timeline_movies.txt"
	@echo "		test3		Realiza una cronología a partir del archivo timeline_science.txt"
	@echo "		test4		Realiza una cronología a partir del archivo timeline_worldhistory.txt"
	@echo "________________________________________________________________________________"

