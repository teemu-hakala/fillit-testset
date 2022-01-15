/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_to_ascii_binary.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:25:13 by thakala           #+#    #+#             */
/*   Updated: 2022/01/15 11:26:38 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <unistd.h>
#include <stdlib.h>
#define LONG_BITCOUNT 64

char	*long_to_ascii_binary(unsigned long n)
{
	unsigned char	c;
	unsigned long	d;
	char			*result;

	c = 0;
	result = (char *)malloc(sizeof(char) * (LONG_BITCOUNT + 1));
	if (!result)
		return (debug_error("long_to_ascii_binary malloc error"));
	while (c++ < LONG_BITCOUNT)
	{
		d = n >> (LONG_BITCOUNT - c);
		if (d & 1)
			result[c - 1] = '1';
		else
			result[c - 1] = '0';
	}
	result[c - 1] = '\0';
	return (result);
}
