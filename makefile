# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 14:15:59 by j.fox             #+#    #+#              #
#    Updated: 2026/02/14 11:15:18 by jfox             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECT_DIR ?= ./object_files
SRC_DIR = ./src
INC_DIR = ./header

SER_NAME = server
SER_SRC = server.c
SER_OBJ = $(SER_SRC:%.c=$(OBJECT_DIR)/%.o)

CLI_NAME = client
CLI_SRC = client.c
CLI_OBJ= $(CLI_SRC:%.c=$(OBJECT_DIR)/%.o)

CC = cc
CFLAGS += -Wall -Wextra -Werror -g -I$(INC_DIR) -MMD -MP

TOOLS = libft.a

all: $(SER_NAME) $(CLI_NAME) ping_make

# ---------- Build objects ---------
$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJECT_DIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

# ---------- Build server ----------
$(SER_NAME): $(TOOLS) $(SER_OBJ)
	@$(CC) $(CFLAGS) -o $(SER_NAME) $(SER_OBJ) $(TOOLS)
	@echo "\033[32m----------The server executable and object files have been made---------\033[0m"

# ---------- Build client ----------
$(CLI_NAME): $(TOOLS) $(CLI_OBJ)
	@$(CC) $(CFLAGS) -o $(CLI_NAME) $(CLI_OBJ) $(TOOLS)
	@echo "\033[32m----------The client executable and object files have been made---------\033[0m"

# -------- Utility library ---------
$(TOOLS):
	@$(MAKE) -C libft

clean:
	@rm -rf $(OBJECT_DIR)
	@echo "\033[33m--The server, client and libft Object_Files were removed successfully---\033[0m"

fclean: clean
	@rm -f $(SER_NAME) $(CLI_NAME)
	@echo "\033[33m-------------The executables have been removed successfully-------------\033[0m"
	@$(MAKE) fclean -C libft
	@echo "\033[33m"
	@echo "=============================CLEAN COMPLETE============================="
	@echo "\033[0m"

re: ping_re fclean all

ping_make:
	@echo "\033[32m"
	@echo "=============================MAKE COMPLETE=============================="
	@echo "\033[0m"

ping_re:
	@echo "\033[31m"
	@echo "=======================REBUILDING THE EXECUTABLES======================="
	@echo "\033[0m"


.PHONY: all clean fclean re tools ping_make ping_re

-include $(SER_OBJ:.o=.d)
-include $(CLI_OBJ:.o=.d)
