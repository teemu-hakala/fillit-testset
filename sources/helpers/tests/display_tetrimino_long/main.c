/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:40:16 by thakala           #+#    #+#             */
/*   Updated: 2022/01/15 12:26:36 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "tests.h"
#include <stdio.h>

static unsigned short	set_board_size(unsigned short setter)
{
	static unsigned short	size;

	if (setter)
		size = setter;
	return (size);
}

static int	ft_test(unsigned long tetrimino)
{
	printf(CYAN_BG "%21lu" UNCOLOR "\n", tetrimino);
	printf(LIGHT_GREEN);
	fflush(stdout);
	display_tetrimino_long(tetrimino, set_board_size(0));
	printf(UNCOLOR);
	printf("\n");
	return (0);
}

int	main(void)
{
	printf(GREEN_BG "DISPLAY TETRIMINO LONG" UNCOLOR "\n");
	set_board_size(6);
	if (ft_test(0)
		|| ft_test((long)(-1))
		|| ft_test((unsigned long)(-1))
		|| ft_test((1L << 63) >> 63)
		|| ft_test((1UL << 63) >> 63)
		|| ft_test(27648UL << 48))
	{
		printf("\n");
		return (1);
	}
	printf("^Observe the results in stdout.\n");
	return (0);
}
