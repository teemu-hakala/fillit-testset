/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:44:42 by thakala           #+#    #+#             */
/*   Updated: 2022/01/22 17:19:37 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "helpers.h"
#include "colours.h"
#include "tetriminoes.h"
#include <stdlib.h>
#include <stdio.h>

static unsigned long	ceiling_division_ref(unsigned long dividend, \
	unsigned long divisor)
{
	unsigned long	division;
	unsigned long	remnant_truth;

	division = dividend / divisor;
	remnant_truth = !!(dividend % sizeof(unsigned long));
	return (division + remnant_truth);
}

t_bitarr	*bitarray_ref(unsigned long len, unsigned char flags)
{
	static t_bitarr	*bitarr;

	if (!bitarr)
		bitarr = (t_bitarr *)ft_memalloc(sizeof(t_bitarr));
	if (bitarr && ((flags & UPDATE && bitarr->size < len) || !bitarr->arr))
	{
		bitarr->len = len;
		free(bitarr->arr);
		bitarr->size = sizeof(unsigned long) * \
			ceiling_division_ref(len, ULONG_BITCOUNT);
		bitarr->arr = (unsigned long *)malloc(bitarr->size);
		bitarr->size *= BYTE_BITCOUNT;
		if (!bitarr->arr)
		{
			free(bitarr); //optional bitarrdel here
			bitarr = NULL;
			return (NULL);
		}
		bitarrzero(bitarr);
	}
	else if (flags & UPDATE && bitarr->len < len)
		bitarr->len = len;
	return (bitarr);
}

static int	ft_test(unsigned long board_size)
{
	t_bitarr		*bitarr;
	unsigned char	success;
	unsigned long	index;
	unsigned long	tetrilong;


	bitarr = bitarray_ref(board_size * board_size, UPDATE);
	display_bitarray(bitarr, board_size);
	index = 0;
	while (index < board_size * board_size)
	{
		tetrilong = pad_short(Z_0, index, board_size);
		if (tetrilong != (unsigned long)(-1))
		{
			success = bitarrset(bitarr, index, tetrilong);
			if (!success)
				printf("success: %hhu\n", success);
			display_bitarray(bitarr, board_size);
			if (success)
				bitarrunset(bitarr, index, tetrilong);
			display_bitarray(bitarr, board_size);
		}
		index++;
	}
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
	function_loader_for_debugging();
	ft_test(9);
	return (0);
}
