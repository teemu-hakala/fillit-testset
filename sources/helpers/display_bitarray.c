/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bitarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:40:16 by thakala           #+#    #+#             */
/*   Updated: 2022/01/22 14:30:47 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

void	display_bitarray(t_bitarr *bitarr, unsigned long board_size)
{
	unsigned long	c;
	unsigned long	bitcount;
	unsigned long	n;
	unsigned long	height;
	unsigned char	first;

	c = 0;
	bitcount = 0;
	height = 0;
	while (bitcount < bitarr->size)
	{
		first = 1;
		while (bitcount % ULONG_BITCOUNT || first)
		{
			n = bitarr->arr[c] >> (ULONG_BITCOUNT - bitcount % ULONG_BITCOUNT);
			first = 0;
			if (n & 1)
				write(1, "1", 1);
			else
				write(1, "0", 1);
			if (height < board_size && bitcount % board_size == board_size - 1)
			{
				write(1, "\n", 1);
				height++;
			}
			bitcount++;
		}
		c++;
	}
	write(1, "\n\n", 2);
}
