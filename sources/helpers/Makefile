# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 13:06:52 by thakala           #+#    #+#              #
#    Updated: 2022/01/16 13:25:18 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libhelp.a

FUNCTIONS = \
	ascii_to_long_binary \
	ascii_to_short_binary \
	display_tetrimino_long \
	display_tetrimino_short \
	long_to_ascii_binary \
	short_to_ascii_binary

INCLUDES_DIR = includes

SRCS = $(foreach src, $(FUNCTIONS), $(addsuffix .c, $(src)))

OBJS = $(foreach obj, $(FUNCTIONS), $(addsuffix .o, $(obj)))

CC = clang

DBFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(DBFLAGS) -c $(patsubst %.o, %.c, $@) \
		-I$(INCLUDES_DIR)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all



