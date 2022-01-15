# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 16:50:31 by thakala           #+#    #+#              #
#    Updated: 2022/01/15 12:40:59 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILLIT_DIR = ../$(shell cat config/fillit_dir.config)

FILLIT_FUNCTIONS = \
	pad_short

FILLIT_FUNCTIONS := ${FILLIT_FUNCTIONS:=.c}

FILLIT_FUNCTIONS := $(FILLIT_DIR)/fillit

debug:
	@printf "\e[42mFILLIT_DIR\e[0m: $(FILLIT_DIR)\n"
	@printf "\e[42mFILLIT_FUNCTIONS\e[0m: $(FILLIT_FUNCTIONS)\n"
