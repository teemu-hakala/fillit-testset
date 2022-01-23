/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:11:37 by thakala           #+#    #+#             */
/*   Updated: 2022/01/23 17:13:22 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "helpers.h"
#include "colours.h"
#include "tetriminoes.h"
#include <stdlib.h>
#include <stdio.h>

static unsigned long	min_board(unsigned long square_count)
{
	unsigned long	result;

	result = 2;
	while (result * result < square_count)
		result++;
	return (result);
}

static int	ft_test(unsigned short *tetriminoes, unsigned long tetrimino_count)
{
	unsigned long			board_size;
	char					*solution;

	board_size = min_board(tetrimino_count * 4);
	solution = (char *)0;
	while (1)
	{
		bitarray(board_size * board_size, UPDATE);
		solution = solve(tetriminoes, board_size, 0);
		if (solution)
			break ;
		board_size++;
	}
	display_solution_board(solution, board_size);
	return (0);
}

static void	function_loader_for_debugging(void)
{
	char			*t_2_ascii;
	t_bitarr		*bitarr;

	bitarr = (t_bitarr *)ft_memalloc(sizeof(t_bitarr));
	if (!bitarr)
		return ;
	bitarr->arr = (unsigned long *)ft_memalloc(sizeof(unsigned long));
	if (!bitarr->arr)
		return ;
	bitarr->len = 16;
	bitarr->size = 64;
	t_2_ascii = long_to_ascii_binary(T_2);
	free(t_2_ascii);
	display_bitarray(bitarr, 0);
	free(bitarr->arr);
	free(bitarr);
	display_tetrimino_short(J_1);
}


int	main(void)
{
	if (ft_test((unsigned short []){T_2, J_3, L_1, T_0, O_0, S_0, 0}, 6)
		|| ft_test((unsigned short []){O_0, I_1, J_2, L_0, 0}, 4)
		|| ft_test((unsigned short []){I_0, I_1, J_0, J_1, J_2, J_3, L_0, L_1, \
		L_2, L_3, O_0, S_0, S_1, T_0, T_1, T_2, T_3, Z_0, Z_1, 0}, 19))
	{
		return (1);
	}
	printf("function loader for debugging:\n");
	function_loader_for_debugging();
	return (0);
}
