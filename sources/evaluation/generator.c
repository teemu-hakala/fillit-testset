/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:23:40 by thakala           #+#    #+#             */
/*   Updated: 2022/01/24 15:17:15 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminoes.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define LEN_TETRIMINO_STR 20UL
#define TETRIMINO_STR_ROW_WIDTH 5U

static int	errors(char *message, int output)
{
	printf(message);
	return (output);
}

static char	*filename(const char *format_string, unsigned long file_id)
{
	char	*name;

	name = (char *)malloc(sizeof(char) * \
		(snprintf(NULL, 0, format_string, file_id)));
	sprintf(name, format_string, file_id);
}

static char	*generate_tetrimino(unsigned short tetrimino)
{
	unsigned char	shift;
	unsigned char	char_count;
	unsigned char	height;
	char			*tetrimino_string;

	tetrimino_string = (char *)malloc(sizeof(char) * (LEN_TETRIMINO_STR + 1));
	shift = LEN_TETRIMINO_STR;
	while (shift--)
	{
		if (tetrimino >> shift & 1)
			tetrimino_string[char_count++] = '#';
		else
			tetrimino_string[char_count++] = '.';
		if (char_count % TETRIMINO_STR_ROW_WIDTH == 0)
		{
			tetrimino_string[char_count] = '\n';
			height++;
		}
		char_count++;
	}
	tetrimino_string[LEN_TETRIMINO_STR] = '\0';
	return (tetrimino_string);
}

static void	generator(unsigned short *tetriminoes)
{
	static unsigned long	file_id = 0;
	char					*name;
	int						fd;
	char					*tetrimino_string;

	name = filename("test%5lu.generatedinput", file_id++);
	printf("processing file: %s\n", name);
	fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		return (errors("file open error", -1));
	while (*tetriminoes)
	{
		tetrimino_string = generate_tetrimino(tetriminoes++);
		write(fd, tetrimino_string, LEN_TETRIMINO_STR);
		write(1, "\n", 1);
		free(tetrimino_string);
	}
}

int	main(void)
{
	generator((unsigned short []){O_0, I_1, J_2, L_0, 0});
}
