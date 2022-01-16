/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:45:43 by thakala           #+#    #+#             */
/*   Updated: 2022/01/16 15:51:05 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "helpers.h"
#include "tetriminoes.h"
#include <stdio.h>

static unsigned char	set_board_size(const unsigned char size)
{
	static unsigned char	board_size = 2;

	if (size)
		board_size = size;
	return (size);
}

static int	ft_test(const unsigned short tetrimino, \
	const unsigned char index, \
	const unsigned char board_size)
{
	pad_short(tetrimino, index, board_size);
	return (0);
}

static int	ft_test_indices(const unsigned short tetrimino, \
	const unsigned char board_size)
{
	unsigned char	index;
	unsigned char	max_index;

	index = 0;
	max_index = board_size * board_size;
	while (index < max_index)
		ft_test(tetrimino, index++, board_size);
	return (0);
}

int	main(void)
{
	set_board_size(4);
	if (ft_test_indices(I_0, set_board_size(0))
		|| ft_test_indices(I_1, set_board_size(0))
		|| ft_test_indices(J_0, set_board_size(0))
		|| ft_test_indices(J_1, set_board_size(0))
		|| ft_test_indices(J_2, set_board_size(0))
		|| ft_test_indices(J_3, set_board_size(0))
		|| ft_test_indices(L_0, set_board_size(0))
		|| ft_test_indices(L_1, set_board_size(0))
		|| ft_test_indices(L_2, set_board_size(0))
		|| ft_test_indices(L_3, set_board_size(0))
		|| ft_test_indices(O_0, set_board_size(0))
		|| ft_test_indices(S_0, set_board_size(0))
		|| ft_test_indices(S_1, set_board_size(0))
		|| ft_test_indices(T_0, set_board_size(0))
		|| ft_test_indices(T_1, set_board_size(0))
		|| ft_test_indices(T_2, set_board_size(0))
		|| ft_test_indices(T_3, set_board_size(0))
		|| ft_test_indices(Z_0, set_board_size(0))
		|| ft_test_indices(Z_1, set_board_size(0)))
	{
		return (1);
	}
	return (0);
}
