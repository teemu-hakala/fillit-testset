/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:44:42 by thakala           #+#    #+#             */
/*   Updated: 2022/01/22 13:07:14 by thakala          ###   ########.fr       */
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

static int ft_test(void)
{
	return (0);
}

int	main(void)
{
	ft_test();
	return (0);
}
