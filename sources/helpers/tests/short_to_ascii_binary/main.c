/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:09:58 by thakala           #+#    #+#             */
/*   Updated: 2022/01/13 11:11:18 by thakala          ###   ########.fr       */
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
	printf("%s", short_to_ascii_binary(tetrimino));
	printf(UNCOLOR);
	printf("\n");
	return (0);
}

int	main(void)
{
	printf(GREEN_BG "SHORT TO ASCII BINARY" UNCOLOR "\n");
	if (ft_test(0)
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
