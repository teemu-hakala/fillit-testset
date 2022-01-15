/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:31:25 by thakala           #+#    #+#             */
/*   Updated: 2022/01/15 11:28:52 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "tests.h"
#include <stdio.h>

static int	ft_test(const char *tetrimino, const unsigned long reference)
{
	unsigned long	result;

	printf(CYAN_BG "%s" UNCOLOR "\n", tetrimino);
	result = ascii_to_long_binary(tetrimino);
	if (result == reference)
		printf(LIGHT_GREEN);
	else
	{
		printf(RED_BG);
		printf("ref: %lu\tfct: ", reference);
	}
	fflush(stdout);
	printf("%lu", result);
	printf(UNCOLOR);
	printf("\n");
	return (0);
}

int	main(void)
{
	printf(GREEN_BG "ASCII TO LONG BINARY" UNCOLOR "\n");
	if (ft_test("0", 0)
		|| ft_test("0000000000000000", 0b0000000000000000)
		|| ft_test("0110110000000000", 0b0110110000000000)
		|| ft_test("0111111111111111", 0b0111111111111111)
		|| ft_test("1000000000000000", 0b1000000000000000)
		|| ft_test("1111111111111111", 0b1111111111111111))
	{
		printf("\n");
		return (1);
	}
	printf("^Observe the results in stdout.\n");
	return (0);
}
