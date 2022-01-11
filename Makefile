# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 16:50:31 by thakala           #+#    #+#              #
#    Updated: 2022/01/10 16:58:14 by thakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILLIT_DIR = ../$(shell cat config/fillit_dir.config)

debug:
	@printf "\e[42mFILLIT_DIR\e[0m: $(FILLIT_DIR)\n"
