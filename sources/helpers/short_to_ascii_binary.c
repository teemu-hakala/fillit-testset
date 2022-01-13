/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_to_ascii_binary.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:54:06 by thakala           #+#    #+#             */
/*   Updated: 2022/01/13 11:13:36 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <unistd.h>
#include <stdlib.h>
#define SHORT_BITCOUNT 16

char	*short_to_ascii_binary(unsigned short n)
{
	unsigned char	c;
	unsigned short	d;
	char			*result;

	c = 0;
	result = (char *)malloc(sizeof(char) * (SHORT_BITCOUNT + 1));
	if (!result)
		return (debug_error("short_to_ascii_binary malloc error"));
	while (c++ < SHORT_BITCOUNT)
	{
		d = n >> (SHORT_BITCOUNT - c);
		if (d & 1)
			result[c - 1] = '1';
		else
			result[c - 1] = '0';
	}
	result[c - 1] = '\0';
	return (result);
}
