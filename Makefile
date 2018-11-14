# @brief Makefile de la práctica 2 para la asignatura Estructura de Computadores del DGIIM
# @file Makefile
# @author Gonzalo Moreno Soto
# @author Manuel Gachs Ballegeer
# @license GPLv3

#Nombre del proyecto
PROJECT = practica2

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
VPATH = $(SRC):$(OBJ):$(INC)

# Variables de archivos
SOURCES = fechahistorica.cpp cronologia.cpp auxiliares.cpp
OBJECTS = $(SOURCES:.cpp=.o)

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
VTEST = $(DATA)/timeline_worldhistory.txt

# Miscelaneas
COMPILING_MESSAGE = Compilando los archivos:
BOLD = `tput bold`
GREEN = `tput setaf 2`
BLUE = `tput setaf 4`
BLACK = `tput setaf 0`
WHITE_BG = `tput setab 7`
RESET = `tput sgr0`
# Reglas

all: $(PROJECT) help author

$(PROJECT): fechahistorica.o cronologia.o auxiliares.o $(PROJECT).o | bindir
	@echo "${BOLD}Creando el ejecutable final...${RESET}"
	@$(CC) $(FLAGS) -o $(BIN)/$(PROJECT) $?
	@echo "${GREEN}HECHO${RESET}"

$(OBJECTS): %.o: %.cpp %.h | objdir message
	@$(CC) -c -I$(INC) $< -o $@
	@echo "${GREEN}HECHO${RESET}"
	
$(PROJECT).o: $(PROJECT).cpp
	@echo "${BOLD}Creando el objeto del proyecto...${RESET}"
	@$(CC) -I$(INC) -c -o $@ $<
	@echo "${GREEN}HECHO${RESET}"

message:
	@echo $(BOLD)$(COMPILING_MESSAGE)$(RESET) $(OBJECTS)

refresh:
	@echo "Refrescando archivos..."
	@touch $(SRC)/*
	@echo "${GREEN}HECHO${RESET}"

doxy:
	-rm -rf $(DOC)/html $(DOC)/latex
	doxygen $(DOC)/cronologia.doxy
	firefox $(DOC)/html/index.html

zip: $(PROJECT) | zipdir
	-rm -rf $(ZIP)/*
	-rm -rf $(BIN)/*
	-rm -rf $(OBJ)/*
	-rm -rf $(DOC)/html $(DOC)/latex
	-rm -rf *.bgr
	@echo "Creando zip..."
	@zip -r $(ZIP)/$(PROJECT).zip *
	@echo "${GREEN}HECHO${RESET}"

valgrind: $(PROJECT)
	valgrind $(VFLAGS) $(BIN)/$(PROJECT) $(VTEST)

bigtest: $(PROJECT)
	./$(BIN)/$(PROJECT) $(TESTS)

test1: $(PROJECT)
	./$(BIN)/$(PROJECT) $(TEST1)

test2: $(PROJECT)
	./$(BIN)/$(PROJECT) $(TEST2)
	
test3: $(PROJECT)
	./$(BIN)/$(PROJECT) $(TEST3)
	
test4: $(PROJECT)
	./$(BIN)/$(PROJECT) $(TEST4)

objdir:
	@-mkdir -p $(OBJ)

bindir:
	@-mkdir -p $(BIN)

zipdir:
	@-mkdir -p $(ZIP)

help:
	@echo "________________________________________________________________________________"
	@echo "${BOLD}Lista de parámetros posibles:${RESET}"
	@echo "		${WHITE_BG}${BLACK}refresh${RESET}		Permite volver a compilar los archivos sin modificarlos"
	@echo "		${WHITE_BG}${BLACK}doxy${RESET}		Genera la documentación"
	@echo "		${WHITE_BG}${BLACK}zip${RESET}		Genera el zip del proyecto"
	@echo "		${WHITE_BG}${BLACK}valgrind${RESET}	Realiza un test por medio de valgrind"
	@echo "		${WHITE_BG}${BLACK}bigtest${RESET}		Realiza un test que engloba a todos los test del makefile"
	@echo "		${WHITE_BG}${BLACK}infotests${RESET}	Muestra todos los tests posibles"
	@echo "		${WHITE_BG}${BLACK}test<num>${RESET}	Realiza el test <num>"
	@echo "		${WHITE_BG}${BLACK}help${RESET}		Muestra esta ayuda"
	@echo "		${WHITE_BG}${BLACK}author${RESET}		Información sobre el autor de este programa"
	@echo "________________________________________________________________________________"

author:
	@echo "Este es un proyecto realizado por Gonzalo Moreno Soto (${BLUE}https://github.com/delightfulagony${RESET})"
	@echo "y Manuel Gachs Ballegeer (${BLUE}https://github.com/Manuelbelgicano${RESET})" 
	@echo "para la asignatura de Estructura de Datos de la Universidad de Granada"

infotests:
	@echo "________________________________________________________________________________"
	@echo "${BOLD}Lista de tests posibles:${RESET}"
	@echo "		${WHITE_BG}${BLACK}test1${RESET}		Realiza una cronología a partir del archivo timeline_algorithms.txt"
	@echo "		${WHITE_BG}${BLACK}test2${RESET}		Realiza una cronología a partir del archivo timeline_movies.txt"
	@echo "		${WHITE_BG}${BLACK}test3${RESET}		Realiza una cronología a partir del archivo timeline_science.txt"
	@echo "		${WHITE_BG}${BLACK}test4${RESET}		Realiza una cronología a partir del archivo timeline_worldhistory.txt"
	@echo "________________________________________________________________________________"

