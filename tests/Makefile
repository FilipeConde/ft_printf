# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 19:20:11 by fconde-p          #+#    #+#              #
#    Updated: 2025/08/13 22:30:16 by fconde-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define o compilador C e as flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# file paths
SRC_DIR = ..
UNITY_SRC_DIR = ./Unity-2.6.1/src
UNITY_O = $(UNITY_SRC_DIR)/unity.c

%:
	$(CC) test_$(*).c $(SRC_DIR)/$(*).c $(UNITY_O) -I../*.h
	./a.out

clean:
	rm -f a.out
.PHONY: clean