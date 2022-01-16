# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 16:50:31 by thakala           #+#    #+#              #
#    Updated: 2022/01/16 16:29:49 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILLIT_DIR = ../$(shell cat config/fillit_dir.config)

FILLIT_DIR := $(FILLIT_DIR)/fillit

FILLIT_FUNCTIONS = \
	pad_short
#	solve

FILLIT_SOURCES := ${FILLIT_FUNCTIONS:=.c}

FILLIT_SOURCES := $(foreach f, $(FILLIT_FUNCTIONS), $(FILLIT_DIR)/$(f).c)

FILLIT_OBJECTS := ${FILLIT_FUNCTIONS:=.o}

SRC_DIR = sources

INC_DIR = includes \
	$(SRC_DIR)/helpers/includes \
	$(FILLIT_DIR) \
	tetriminoes

OBJ_DIR = objects

BIN_DIR = binaries

CC = clang

DBFLAGS = -g -Wall -Wextra -Werror

all: $(FILLIT_FUNCTIONS)
	@echo "all rule called"
	@echo "$^"

$(FILLIT_FUNCTIONS): $(FILLIT_OBJECTS) | dir-obj-main dir-bin
	@echo "$@ rule called"
	$(CC) $(DBFLAGS) -c $(SRC_DIR)/mains/$@/main.c \
		-o $(patsubst %, $(OBJ_DIR)/mains/%/main.o, $@) \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) $(patsubst %, $(OBJ_DIR)/mains/%/main.o, $@) \
		$(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		-o $(BIN_DIR)/$@.out \
		$(SRC_DIR)/helpers/libhelp.a

$(FILLIT_OBJECTS): $(FILLIT_SOURCES) | dir-obj
	@echo "$@ rule called"
	$(CC) $(DBFLAGS) -c $(patsubst %.o, $(FILLIT_DIR)/%.c, $@) \
		-o $(patsubst %, $(OBJ_DIR)/fillit/%, $@)

dir-obj:
	mkdir -p $(OBJ_DIR)/fillit

dir-bin:
	mkdir -p $(foreach f, $(FILLIT_FUNCTIONS), $(BIN_DIR)/$(f))

dir-obj-main:
	mkdir -p $(foreach main, $(FILLIT_FUNCTIONS), $(OBJ_DIR)/mains/$(main))

info:
	@printf "\e[42mFILLIT_DIR\e[0m: $(FILLIT_DIR)\n"
	@printf "\e[42mFILLIT_FUNCTIONS\e[0m: $(FILLIT_FUNCTIONS)\n"
	@printf "\e[42mFILLIT_SOURCES\e[0m: $(FILLIT_SOURCES)\n"
