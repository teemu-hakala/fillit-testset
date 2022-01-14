/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_short_binary.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:11:03 by thakala           #+#    #+#             */
/*   Updated: 2022/01/14 17:16:55 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <unistd.h>
#define SHORT_BITCOUNT 16

unsigned short	ascii_to_short_binary(const char *str)
{
	unsigned short	result;
	unsigned char	bit_count;

	result = 0;
	bit_count = 0;
	while (bit_count++ < SHORT_BITCOUNT && (*str == '0' || *str == '1'))
	{
		result <<= 1;
		if (*str++ == '1')
			result ^= 1;
	}
	return (result);
}
