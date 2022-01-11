# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 19:38:42 by thakala           #+#    #+#              #
#    Updated: 2022/01/11 14:28:15 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNCTIONS = \
	display_tetrimino_short

SOURCES = ${FUNCTIONS:=.c}

SRC_DIR = ..

INC_DIR = \
	$(SRC_DIR)/includes \
	./includes

INCLUDES = $(shell find $(INC_DIR) -type f -name *.h)

BIN_DIR = bin

CC = clang

CFLAGS = -g -Wall -Wextra -Werror

all: $(FUNCTIONS)
	@echo "all rule: $<"

$(FUNCTIONS): $(SOURCES)
	@echo "FUNCTIONS rule: $@"

$(SOURCES): $(INCLUDES) | dir
	@echo "SOURCES rule: $(patsubst %.c, $(BIN_DIR)/$(strip $(patsubst %.c, %, $@))/%.out, $@)"
	@echo "SOURCES rule: $(patsubst %.c, %, $@)/main.c"
	$(CC) $(CFLAGS) ../$@ $(patsubst %.c, %, $@)/main.c \
		$(foreach inc_dir, $(INC_DIR), -I$(inc_dir)) \
		-o $(patsubst %.c, $(BIN_DIR)/$(strip $(patsubst %.c, %, $@))/%.out, $@)

dir:
	mkdir -p $(foreach function, $(FUNCTIONS), $(BIN_DIR)/$(function))

run: all
	$(foreach binary, $(shell find $(BIN_DIR) -type f -name *.out -maxdepth 2), ./$(binary);)

debug:
	@echo "list of SOURCES: $(SOURCES)"
