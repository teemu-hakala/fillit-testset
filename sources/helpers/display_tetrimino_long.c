/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tetrimino_long.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:38:51 by thakala           #+#    #+#             */
/*   Updated: 2022/01/15 12:19:30 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_tetrimino_long(unsigned long n, unsigned short board_size)
{
	short			c;
	unsigned long	d;
	unsigned short	height;
	unsigned short	index;

	c = 64;
	height = 0;
	index = 0;
	while (--c >= 0)
	{
		d = n >> c;
		if (d & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (height < board_size && ++index % board_size == 0)
		{
			write(1, "\n", 1);
			height++;
		}
	}
	write(1, "\n", 1);
}
