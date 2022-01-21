/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:32:11 by thakala           #+#    #+#             */
/*   Updated: 2022/01/21 15:54:11 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "helpers.h"
#include "colours.h"
#include "tetriminoes.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_test(unsigned long bitcount)
{
	t_bitarr	*bitarr;

	bitarr = bitarray(bitcount, UPDATE);
	bitarr = bitarray(bitcount, FETCH);
	return (0);
}

static int	ft_test_comb(unsigned long start, unsigned long end)
{
	while (start <= end)
		ft_test(start++);
	return (0);
}

static int	testset_1(void)
{
	t_bitarr	*bitarr;

	bitarr = bitarray(0, FETCH);
	ft_test(1);
	ft_test_comb(63, 65);
	ft_test_comb(127, 129);
	ft_test_comb(191, 193);
	ft_test_comb(255, 257);
	return (0);
}

/*static int	testset_2(void)
{
	bitarray(0, FETCH);
	ft_test_comb(0, 350);
	return (0);
}*/

int	main(void)
{
	testset_1();
	//testset_2();
	return (0);
}
