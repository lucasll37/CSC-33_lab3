.PHONY: clean build run help
.DEFAULT_GOAL := help

# Diretório dos arquivos de origem
SRC_DIR = ./src

# Diretório de executáveis
SRC_EXE = ./build

# Lista de arquivos de origem
SOURCE = $(SRC_DIR)/main.cpp $(SRC_DIR)/mergesort.cpp $(SRC_DIR)/mergesort_sequential.cpp

# Nome do executável
EXECUTABLE = $(SRC_EXE)/main.exe

# Comando de compilação
CC = g++

# Opções do compilador
CFLAGS = -Wall -Wextra -std=c++17 -O3 -pthread

# Comando para limpar os arquivos compilados
RM = rm -rf

clear: ## Clean all generated build files in the project.
	$(RM) ./build/*

build: ## Build all targets in the project.
	rm -rf ./build/*
	$(CC) $(CFLAGS) $(SOURCE) -o $(EXECUTABLE)

run: ## Run the project.
	$(EXECUTABLE)

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
