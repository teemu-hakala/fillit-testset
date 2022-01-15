/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_long_binary.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:32:55 by thakala           #+#    #+#             */
/*   Updated: 2022/01/15 11:30:06 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <unistd.h>
#define LONG_BITCOUNT 64

unsigned long	ascii_to_long_binary(const char *str)
{
	unsigned short	result;
	unsigned char	bit_count;

	result = 0;
	bit_count = 0;
	while (bit_count++ < LONG_BITCOUNT && (*str == '0' || *str == '1'))
	{
		result <<= 1;
		if (*str++ == '1')
			result ^= 1;
	}
	return (result);
}
