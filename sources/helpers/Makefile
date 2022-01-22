# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 13:06:52 by thakala           #+#    #+#              #
#    Updated: 2022/01/22 13:01:37 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libhelp.a

FUNCTIONS = \
	ascii_to_long_binary \
	ascii_to_short_binary \
	display_tetrimino_long \
	display_tetrimino_short \
	long_to_ascii_binary \
	short_to_ascii_binary \
	display_bitarray

AUXILIARY_FUNCTIONS = \
	debug_error

AUX_DIR = auxiliary

AUXILIARY_SOURCES = ${AUXILIARY_FUNCTIONS:=.c}

AUXILIARY_OBJECTS = ${AUXILIARY_FUNCTIONS:=.o}

AUXILIARY_SOURCES := $(foreach auxiliary, $(AUXILIARY_SOURCES), $(AUX_DIR)/$(auxiliary))

OBJ_DIR = objects

INC_DIR = includes ../../../fillit-mrozhnov-thakala/fillit/

SRCS = $(foreach src, $(FUNCTIONS), $(addsuffix .c, $(src)))

OBJS = $(foreach obj, $(FUNCTIONS), $(addsuffix .o, $(obj)))

CC = clang

DBFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(AUXILIARY_OBJECTS) | dir-obj
	ar rcs $(NAME) \
		$(foreach o, $(OBJS), $(OBJ_DIR)/$(o)) \
		$(foreach o, $(AUXILIARY_OBJECTS), $(OBJ_DIR)/$(o)) \

$(OBJS): $(SRCS) | dir-obj
	$(CC) $(DBFLAGS) -c $(patsubst %.o, %.c, $@) \
		$(foreach i, $(INC_DIR), -I $(i)) \
		-o $(OBJ_DIR)/$@

$(AUXILIARY_OBJECTS): $(AUXILIARY_SOURCES) | dir-obj
	$(CC) $(DBFLAGS) -c $(patsubst %.o, $(AUX_DIR)/%.c, $@) \
		$(foreach i, $(INC_DIR), -I $(i)) \
		-o $(OBJ_DIR)/$@

dir-obj:
	mkdir -p $(OBJ_DIR)

#clean:
#	/bin/rm -f $(OBJS)

#fclean: clean
#	/bin/rm -f $(NAME)

#re: fclean all



