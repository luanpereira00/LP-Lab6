# Makefile, separando os diferentes elementos da aplicacao
# como codigo (src), cabecalhos (include), executaveis (build), bibliotecas (lib), etc.
# Cada elemento e alocado em uma pasta especifica, organizando melhor seu codigo fonte.
#
# Algumas variaveis sao usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC=g++ 

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
DAT_DIR=./data
TEST_DIR=./test

# Opcoes de compilacao
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all init clean doxy debug doc 

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: init pilha lista
debug: CFLAGS += -g -O0
debug: pilha lista

init:
	@mkdir -p $(BIN_DIR)/
	@mkdir -p $(OBJ_DIR)/

# Alvo (target) para a construcao do executavel
# Define os arquivos pilha.o, tratarString.o como dependencia
pilha: $(OBJ_DIR)/pilha.o $(OBJ_DIR)/tratarString.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'pilha' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto matrizes.o
# Define os arquivos pilha.cpp, tratarString.cpp, tratarString.h e pilha.h como dependencias.
$(OBJ_DIR)/pilha.o: $(SRC_DIR)/pilha.cpp $(SRC_DIR)/tratarString.cpp $(INC_DIR)/tratarString.h $(INC_DIR)/pilha.h
	$(CC) -c $(CFLAGS) -o $@ $<	

# Alvo (target) para a construcao do objeto matrizes.o
# Define os arquivos tratarString.cpp e tratarString.h como dependencias.
$(OBJ_DIR)/tratarString.o: $(SRC_DIR)/tratarString.cpp $(INC_DIR)/tratarString.h
	$(CC) -c $(CFLAGS) -o $@ $<					

# Alvo (target) para a construcao do executavel
# Define o arquivo lista.o como dependencia
lista: $(OBJ_DIR)/lista.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'lista' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto matrizes.o
# Define os arquivos lista.cpp e lista.h como dependencias.
$(OBJ_DIR)/lista.o: $(SRC_DIR)/lista.cpp $(INC_DIR)/lista.h
	$(CC) -c $(CFLAGS) -o $@ $<	


# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g

doc:
	doxygen

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/* 
	$(RM) $(OBJ_DIR)/*	
	$(RM) $(DOC_DIR)/*	