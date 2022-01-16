/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:45:43 by thakala           #+#    #+#             */
/*   Updated: 2022/01/16 18:45:39 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "helpers.h"
#include "colours.h"
#include "tetriminoes.h"
#include <stdio.h>

static int	ft_test(const unsigned short tetrimino, \
	const unsigned char index, \
	const unsigned char board_size)
{
	printf(GREEN_BG " BOARD_SIZE %hhu" UNCOLOR "\n", board_size);
	printf(GREEN_BG " INDEX %hhu" UNCOLOR "\n", index);
	fflush(stdout);
	printf(BLUE_BG " REFERENCE TETRIMINO" UNCOLOR "\n");
	fflush(stdout);
	printf(CYAN_BG " %s" UNCOLOR "\t" LIGHT_GREEN "%hu" UNCOLOR "\n", \
		short_to_ascii_binary(tetrimino), tetrimino);
	fflush(stdout);
	display_tetrimino_short(tetrimino);
	printf(BLUE_BG " PADDED TETRIMINO" UNCOLOR "\n");
	fflush(stdout);
	display_tetrimino_long(pad_short(tetrimino, index, board_size), board_size);
	printf("\n\n");
	fflush(stdout);
	return (0);
}

static int	ft_test_indices(const unsigned short tetrimino, \
	const unsigned char board_size)
{
	unsigned char	index;
	unsigned short	max_index;

	index = 0;
	max_index = board_size * board_size;
	while (index <= max_index)
		ft_test(tetrimino, index++, board_size);
	return (0);
}

int	main(void)
{
	unsigned char	board_size;

	board_size = 4;
	while (board_size <= 20)
	{
		if (ft_test_indices(I_0, board_size)
			|| ft_test_indices(I_1, board_size)
			|| ft_test_indices(J_0, board_size)
			|| ft_test_indices(J_1, board_size)
			|| ft_test_indices(J_2, board_size)
			|| ft_test_indices(J_3, board_size)
			|| ft_test_indices(L_0, board_size)
			|| ft_test_indices(L_1, board_size)
			|| ft_test_indices(L_2, board_size)
			|| ft_test_indices(L_3, board_size)
			|| ft_test_indices(O_0, board_size)
			|| ft_test_indices(S_0, board_size)
			|| ft_test_indices(S_1, board_size)
			|| ft_test_indices(T_0, board_size)
			|| ft_test_indices(T_1, board_size)
			|| ft_test_indices(T_2, board_size)
			|| ft_test_indices(T_3, board_size)
			|| ft_test_indices(Z_0, board_size)
			|| ft_test_indices(Z_1, board_size))
		{
			return (1);
		}
		board_size++;
	}
	return (0);
}
