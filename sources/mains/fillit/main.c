/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:56:53 by thakala           #+#    #+#             */
/*   Updated: 2022/01/26 19:58:00 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "helpers.h"

static void	function_loader_for_debugging(void)
{
	char			*t_2_ascii;

	t_2_ascii = long_to_ascii_binary(T_2);
	free(t_2_ascii);
}

int	main(int argc, char **argv)
{
	int				fd;
	uint8_t			count;
	static t_tetri	tetriminoes[27];

	function_loader_for_debugging();
	if (argc != 2)
		return ((int)errors ("usage: Insert 1 argument after ./fillit\n", -1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return ((int)errors ("open_error\n", 2));
	tetrimino_reference_init();
	count = 0;
	if (get_tetriminoes(fd, tetriminoes, &count) <= 0)
		return ((int)errors ("error\n", -1));
	if (close (fd) == -1)
		return ((int)errors ("close_error\n", 2));
	return (fillit(tetriminoes, count));
}
