# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 19:38:42 by thakala           #+#    #+#              #
#    Updated: 2022/01/23 13:36:50 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNCTIONS = \
	display_tetrimino_short \
	short_to_ascii_binary \
	ascii_to_short_binary \
	long_to_ascii_binary \
	ascii_to_long_binary \
	display_tetrimino_long

SRC_DIR = ..

SOURCES = ${FUNCTIONS:=.c}

AUXILIARY_FUNCTIONS = \
	debug_error

AUX_DIR = ../auxiliary

AUXILIARY_SOURCES = ${AUXILIARY_FUNCTIONS:=.c}

AUXILIARY_SOURCES := $(foreach auxiliary, $(AUXILIARY_SOURCES), $(AUX_DIR)/$(auxiliary))

INC_DIR = \
	$(SRC_DIR)/includes \
	./includes \
	../../../../fillit-mrozhnov-thakala/fillit/

INCLUDES = $(shell find $(INC_DIR) -type f -name *.h)

BIN_DIR = bin

CC = clang

CFLAGS = -g -Wall -Wextra -Werror

all: $(FUNCTIONS)
	@echo "all rule: $<"

$(FUNCTIONS): $(SOURCES)
	@echo "FUNCTIONS rule: $@"
	./$(BIN_DIR)/$@/$@.out

$(SOURCES): $(INCLUDES) | dir
	@echo "SOURCES rule: $(patsubst %.c, $(BIN_DIR)/$(strip $(patsubst %.c, %, $@))/%.out, $@)"
	@echo "SOURCES rule: $(patsubst %.c, %, $@)/main.c"
	$(CC) $(CFLAGS) $(SRC_DIR)/$@ $(patsubst %.c, %, $@)/main.c \
		$(AUXILIARY_SOURCES) \
		$(foreach inc_dir, $(INC_DIR), -I$(inc_dir)) \
		-o $(patsubst %.c, $(BIN_DIR)/$(strip $(patsubst %.c, %, $@))/%.out, $@)

dir:
	mkdir -p $(foreach function, $(FUNCTIONS), $(BIN_DIR)/$(function))

#change to the non-wildcard solution (generate binaries list)
run: all
	$(foreach binary, $(shell find $(BIN_DIR) -type f -name *.out -maxdepth 2), ./$(binary);)

debug:
	@echo "list of SOURCES: $(SOURCES)"
