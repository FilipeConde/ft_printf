# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 19:20:11 by fconde-p          #+#    #+#              #
#    Updated: 2025/08/11 20:52:00 by fconde-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define o compilador C
CC = cc

# Unity path
UNITY_SRC_DIR = Unity-2.6.1/src
UNITY_SRC = $(UNITY_SRC_DIR)/unity

# sys path
SRC_DIR = ..

# src files
OBJ = $()

# tests path
TESTS_PATH = .

# generate .o files
%.o: %.c
	$(CC) -c test_$(<) -o $(@)
	$(CC) -c $(SRC_DIR)/$(<) -o $(@)

# all: test_$(*).c $(SRC_DIR)/$(*).c $(UNITY_SRC)
# 	$(CC) $^ -I$(UNITY_SRC_DIR) -o $@


# gera .o da lib Unity
unity.o:
	$(CC) -c $(UNITY_SRC).c -o $(@)

# Regra de padrão dinâmica para compilar e rodar qualquer teste
# test_%: test_$(*).c $(SRC_DIR)/$(*).c $(UNITY_SRC)
test_%: test_$(*).o $(SRC_DIR)/$(*).o unity.o
	$(CC) $^ -I$(UNITY_SRC_DIR) -o $@
	./$@

# Limpeza: remove todos os executáveis de teste na pasta "tests"
clean:
	rm -f test_*
.PHONY: clean