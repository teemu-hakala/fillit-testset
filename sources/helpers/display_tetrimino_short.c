/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tetrimino_short.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:59:27 by thakala           #+#    #+#             */
/*   Updated: 2022/01/15 11:49:46 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_tetrimino_short(unsigned short n)
{
	char			c;
	unsigned short	d;

	c = 16;
	while (--c >= 0)
	{
		d = n >> c;
		if (d & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (c % 4 == 0)
			write(1, "\n", 1);
	}
	write(1, "\n", 1);
}
