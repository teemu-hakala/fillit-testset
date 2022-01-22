/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:45:43 by thakala           #+#    #+#             */
/*   Updated: 2022/01/22 11:41:58 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "helpers.h"
#include "colours.h"
#include "tetriminoes.h"
#include <stdlib.h>
#include <stdio.h>

/*static unsigned char	redundancy_check_ref(unsigned long tetrilong, \
	unsigned char shift_modulus)
{
	unsigned long	checker;

	checker = tetrilong;
	return ((checker >> shift_modulus) << shift_modulus == tetrilong);
}*/

static unsigned char	redundancy_check_board(unsigned long tetrilong, \
	unsigned long index, unsigned long board_size)
{
	unsigned long	checker;
	long			shift;
	long			index_modulus;
	long			board_modulus;

	index_modulus = index % 64;
	board_modulus = board_size * board_size % 64;
	checker = tetrilong;
	if (index_modulus > board_modulus)
	{
		shift = index_modulus - board_modulus;
		return (((checker >> shift) << shift) == tetrilong);
	}
	else if (index >= 64 && index_modulus + 64 > board_modulus)
	{
		shift = index_modulus + 64 - board_modulus;
		return (((checker >> shift) << shift) == tetrilong);
	}
	return (1);
}

unsigned long	pad_short_ref(unsigned short tetrimino, unsigned short index, \
	unsigned char board_size)
{
	unsigned char	t;
	unsigned char	tetrimino_line;
	unsigned long	tetrilong;
	unsigned char	padding;

	t = 16;
	tetrilong = 0;
	if (board_size > 4 && board_size <= 20)
	{
		padding = board_size - 4;
		while (t)
		{
			tetrilong <<= 4;
			t -= 4;
			tetrimino_line = (tetrimino >> t) & 0b1111;
			tetrilong = (tetrilong ^ tetrimino_line) << padding;
		}
		return (tetrilong << (64 - board_size * 4 % 64));
	}
	else if (board_size == 4)
		return ((((unsigned long)tetrimino) << 48) >> index % board_size);
	else
		return ((unsigned long)(-1));
}

static int	ft_test(const unsigned short tetrimino, \
	const unsigned short index, \
	const unsigned char board_size)
{
	unsigned long	tetrilong;

	printf(GREEN_BG " BOARD_SIZE %hhu" UNCOLOR "\n", board_size);
	printf(GREEN_BG " INDEX %hu" UNCOLOR "\n", index);
	fflush(stdout);
	printf(BLUE_BG " REFERENCE TETRIMINO" UNCOLOR "\n");
	fflush(stdout);
	printf(CYAN_BG " %s" UNCOLOR "\t" LIGHT_GREEN "%hu" UNCOLOR "\n", \
		short_to_ascii_binary(tetrimino), tetrimino);
	fflush(stdout);
	display_tetrimino_short(tetrimino);
	printf(BLUE_BG " PADDED TETRIMINO" UNCOLOR "\n");
	fflush(stdout);
	tetrilong = pad_short(tetrimino, index, board_size);
	if (tetrilong == (unsigned long)(-1) ||
		!redundancy_check_board(tetrilong, index, board_size))
	{
		printf(RED_BG " PIECE DOESN'T FIT ON THE BOARD" UNCOLOR "\n");
		fflush(stdout);
		display_tetrimino_long(~((unsigned long)pad_short_ref(tetrimino, \
			index, board_size) >> index % 64), board_size);
	}
	else
	{
		printf(GREEN_BG " PIECE FITS ON THE BOARD" UNCOLOR "\n");
		display_tetrimino_long(tetrilong >> index % 64, board_size);
	}
	printf("\n\n");
	fflush(stdout);
	return (0);
}

static int	ft_test_indices(const unsigned short tetrimino, \
	const unsigned short board_size)
{
	unsigned short	index;
	unsigned short	max_index;

	index = 0;
	max_index = board_size * board_size;
	while (index < max_index)
		ft_test(tetrimino, index++, board_size);
	return (0);
}

static void	function_loader_for_debugging(void)
{
	char			*t_2_ascii;

	t_2_ascii = long_to_ascii_binary(T_2);
	free(t_2_ascii);
}

int	main(void)
{
	unsigned short	board_size;

	function_loader_for_debugging();
	board_size = 9; // 5, 4, 14
	while (board_size <= 20)
	{
		if (/*ft_test_indices(I_0, board_size)
			||*/ ft_test_indices(I_1, board_size)
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
