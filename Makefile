# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 16:50:31 by thakala           #+#    #+#              #
#    Updated: 2022/01/26 20:02:53 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILLIT_DIR_CONFIG = ../$(shell cat config/fillit_dir.config)

LIBFT_DIR = $(FILLIT_DIR_CONFIG)/libft

FILLIT_DIR = $(FILLIT_DIR_CONFIG)/fillit

FILLIT_FUNCTIONS = \
	pad_short \
	bitarray \
	bitarrset \
	solve

FILLIT_SOURCES := ${FILLIT_FUNCTIONS:=.c}

FILLIT_SOURCES := $(foreach f, $(FILLIT_FUNCTIONS), $(FILLIT_DIR)/$(f).c)

FILLIT_OBJECTS := ${FILLIT_FUNCTIONS:=.o}

SRC_DIR = sources

INC_DIR = includes \
	$(SRC_DIR)/helpers/includes \
	$(FILLIT_DIR) \
	$(LIBFT_DIR)/includes \
	tetriminoes

OBJ_DIR = objects

BIN_DIR = binaries

CC = clang

DBFLAGS = -g -Wall -Wextra -Werror

all: $(FILLIT_FUNCTIONS) | directories
	@echo "all rule called"
	@echo "$^"

#$(FILLIT_FUNCTIONS): $(FILLIT_OBJECTS)
#	@echo "$@ rule called"
#	$(CC) $(DBFLAGS) -c $(SRC_DIR)/mains/$@/main.c \
		-o $(patsubst %, $(OBJ_DIR)/mains/%/main.o, $@) \
		$(foreach i, $(INC_DIR), -I $(i))
#	$(CC) $(DBFLAGS) $(patsubst %, $(OBJ_DIR)/mains/%/main.o, $@) \
		$(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		-o $(BIN_DIR)/$@.out \
		$(SRC_DIR)/helpers/libhelp.a

#$(FILLIT_OBJECTS): $(FILLIT_SOURCES)
#	@echo "$@ rule called"
#	$(CC) $(DBFLAGS) -c $(patsubst %.o, $(FILLIT_DIR)/%.c, $@) \
		-o $(patsubst %, $(OBJ_DIR)/fillit/%, $@) \
		$(foreach i, $(INC_DIR), -I $(i))

directories: | dir-obj-main dir-bin dir-obj
	@echo "Create directories."

dir-obj:
	mkdir -p $(OBJ_DIR)/fillit $(OBJ_DIR)/evaluation

dir-bin:
	mkdir -p $(foreach f, $(FILLIT_FUNCTIONS), $(BIN_DIR)/$(f))
	mkdir -p $(BIN_DIR)/evaluation

dir-obj-main:
	mkdir -p $(foreach main, $(FILLIT_FUNCTIONS), $(OBJ_DIR)/mains/$(main))

info:
	@printf "\e[42mFILLIT_DIR\e[0m: $(FILLIT_DIR)\n"
	@printf "\e[42mFILLIT_FUNCTIONS\e[0m: $(FILLIT_FUNCTIONS)\n"
	@printf "\e[42mFILLIT_SOURCES\e[0m: $(FILLIT_SOURCES)\n"

pad_short: $(FILLIT_DIR)/pad_short.c
	@echo "$@ rule called"
	$(CC) $(DBFLAGS) -c $(patsubst %, $(FILLIT_DIR)/%.c, $@) \
		-o $(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(SRC_DIR)/mains/$@/main.c \
		-o $(OBJ_DIR)/mains/$@/main.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) $(patsubst %, $(OBJ_DIR)/mains/%/main.o, $@) \
		$(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		-o $(BIN_DIR)/$@/$@.out \
		$(SRC_DIR)/helpers/libhelp.a \
		$(LIBFT_DIR)/libft.a

bitarray: $(FILLIT_DIR)/bitarray.c
	@echo "$@ rule called"
	$(CC) $(DBFLAGS) -c $(patsubst %, $(FILLIT_DIR)/%.c, $@) \
		-o $(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/bitarrzero.c \
		-o $(OBJ_DIR)/fillit/bitarrzero.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(SRC_DIR)/mains/$@/main.c \
		-o $(OBJ_DIR)/mains/$@/main.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) $(patsubst %, $(OBJ_DIR)/mains/%/main.o, $@) \
		$(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		$(OBJ_DIR)/fillit/bitarrzero.o \
		-o $(BIN_DIR)/$@/$@.out \
		$(SRC_DIR)/helpers/libhelp.a \
		$(LIBFT_DIR)/libft.a

bitarrset: $(FILLIT_DIR)/bitarrset.c
	@echo "$@ rule called"
	$(CC) $(DBFLAGS) -c $(patsubst %, $(FILLIT_DIR)/%.c, $@) \
		-o $(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/pad_short.c \
		-o $(OBJ_DIR)/fillit/pad_short.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/bitarrzero.c \
		-o $(OBJ_DIR)/fillit/bitarrzero.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/bitarrunset.c \
		-o $(OBJ_DIR)/fillit/bitarrunset.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/split_long.c \
		-o $(OBJ_DIR)/fillit/split_long.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(SRC_DIR)/mains/$@/main.c \
		-o $(OBJ_DIR)/mains/$@/main.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) $(patsubst %, $(OBJ_DIR)/mains/%/main.o, $@) \
		$(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		$(OBJ_DIR)/fillit/pad_short.o \
		$(OBJ_DIR)/fillit/split_long.o \
		$(OBJ_DIR)/fillit/bitarrzero.o \
		$(OBJ_DIR)/fillit/bitarrunset.o \
		-o $(BIN_DIR)/$@/$@.out \
		$(SRC_DIR)/helpers/libhelp.a \
		$(LIBFT_DIR)/libft.a


solve: $(FILLIT_DIR)/solve.c
	@echo "$@ rule called"
	$(CC) $(DBFLAGS) -c $(patsubst %, $(FILLIT_DIR)/%.c, $@) \
		-o $(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/pad_short.c \
		-o $(OBJ_DIR)/fillit/pad_short.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/bitarray.c \
		-o $(OBJ_DIR)/fillit/bitarray.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/bitarrset.c \
		-o $(OBJ_DIR)/fillit/bitarrset.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/bitarrzero.c \
		-o $(OBJ_DIR)/fillit/bitarrzero.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/bitarrunset.c \
		-o $(OBJ_DIR)/fillit/bitarrunset.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/place_alphabet.c \
		-o $(OBJ_DIR)/fillit/place_alphabet.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/split_long.c \
		-o $(OBJ_DIR)/fillit/split_long.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/display_solution_board.c \
		-o $(OBJ_DIR)/fillit/display_solution_board.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(SRC_DIR)/mains/$@/main.c \
		-o $(OBJ_DIR)/mains/$@/main.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) $(patsubst %, $(OBJ_DIR)/mains/%/main.o, $@) \
		$(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		$(OBJ_DIR)/fillit/pad_short.o \
		$(OBJ_DIR)/fillit/bitarray.o \
		$(OBJ_DIR)/fillit/bitarrset.o \
		$(OBJ_DIR)/fillit/bitarrzero.o \
		$(OBJ_DIR)/fillit/bitarrunset.o \
		$(OBJ_DIR)/fillit/place_alphabet.o \
		$(OBJ_DIR)/fillit/split_long.o \
		$(OBJ_DIR)/fillit/display_solution_board.o \
		-o $(BIN_DIR)/$@/$@.out \
		$(SRC_DIR)/helpers/libhelp.a \
		$(LIBFT_DIR)/libft.a

generator: $(SRC_DIR)/evaluation/generator.c
	$(CC) $(DBFLAGS) -c $< \
		-o $(OBJ_DIR)/evaluation/$@.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) $(OBJ_DIR)/evaluation/$@.o \
		$(SRC_DIR)/helpers/libhelp.a \
		-o $(BIN_DIR)/evaluation/$@.out

fillit:	$(FILLIT_DIR)/fillit.c
	@echo "$@ rule called"
	$(CC) $(DBFLAGS) -c $(patsubst %, $(FILLIT_DIR)/%.c, $@) \
		-o $(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/bitarray.c \
		-o $(OBJ_DIR)/fillit/bitarray.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/bitarrset.c \
		-o $(OBJ_DIR)/fillit/bitarrset.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/bitarrunset.c \
		-o $(OBJ_DIR)/fillit/bitarrunset.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/bitarrzero.c \
		-o $(OBJ_DIR)/fillit/bitarrzero.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/display.c \
		-o $(OBJ_DIR)/fillit/display.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/fillit.c \
		-o $(OBJ_DIR)/fillit/fillit.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/get_tetriminoes.c \
		-o $(OBJ_DIR)/fillit/get_tetriminoes.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/pad_short.c \
		-o $(OBJ_DIR)/fillit/pad_short.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/place_alphabet.c \
		-o $(OBJ_DIR)/fillit/place_alphabet.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/solve.c \
		-o $(OBJ_DIR)/fillit/solve.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(FILLIT_DIR)/split_long.c \
		-o $(OBJ_DIR)/fillit/split_long.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) -c $(SRC_DIR)/mains/$@/main.c \
		-o $(OBJ_DIR)/mains/$@/main.o \
		$(foreach i, $(INC_DIR), -I $(i))
	$(CC) $(DBFLAGS) $(patsubst %, $(OBJ_DIR)/mains/%/main.o, $@) \
		$(patsubst %, $(OBJ_DIR)/fillit/%.o, $@) \
		$(OBJ_DIR)/fillit/bitarray.o \
		$(OBJ_DIR)/fillit/bitarrset.o \
		$(OBJ_DIR)/fillit/bitarrunset.o \
		$(OBJ_DIR)/fillit/bitarrzero.o \
		$(OBJ_DIR)/fillit/display.o \
		$(OBJ_DIR)/fillit/fillit.o \
		$(OBJ_DIR)/fillit/get_tetriminoes.o \
		$(OBJ_DIR)/fillit/pad_short.o \
		$(OBJ_DIR)/fillit/place_alphabet.o \
		$(OBJ_DIR)/fillit/solve.o \
		$(OBJ_DIR)/fillit/split_long.o \
		-o $(BIN_DIR)/$@/$@.out \
		$(SRC_DIR)/helpers/libhelp.a \
		$(LIBFT_DIR)/libft.a
