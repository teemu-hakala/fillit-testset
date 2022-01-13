/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:38:08 by thakala           #+#    #+#             */
/*   Updated: 2022/01/13 15:12:56 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "tests.h"
#include <stdio.h>

static int	ft_test(unsigned short tetrimino)
{
	printf(CYAN_BG "%7hu" UNCOLOR "\n", tetrimino);
	printf(LIGHT_GREEN);
	fflush(stdout);
	display_tetrimino_short(tetrimino);
	printf(UNCOLOR);
	printf("\n");
	return (0);
}

int	main(void)
{
	printf(GREEN_BG "DISPLAY TETRIMINO SHORT" UNCOLOR "\n");
	if (ft_test(0)
		|| ft_test(0b1000000000000000 >> 1)
		|| ft_test(0b10100000000000000000000000000000 >> 17)
		|| ft_test((short)(-1))
		|| ft_test(((1U << 31) >> 31))
		|| ft_test((0b00000000000000000000000000000001 << 31) >> 31)
		|| ft_test((0b00000000000000000000000000000001U << 31) >> 31)
		|| ft_test(0b1111111111111111 >> 2)
		|| ft_test(0b0110110000000000)
		|| ft_test(0b1111111111111111)
		|| ft_test(65535))
	{
		printf("\n");
		return (1);
	}
	printf("^Observe the results in stdout.\n");
	return (0);
}
