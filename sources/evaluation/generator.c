/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:23:40 by thakala           #+#    #+#             */
/*   Updated: 2022/01/25 11:53:46 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "tetriminoes.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>

#define LEN_TETRIMINO 16U
#define LEN_TETRIMINO_STR 20UL
#define TETRIMINO_STR_ROW_WIDTH 5U
#define CWD "/fillit-testset/binaries/evaluation"
#define OUTPUT_DIR "generated_inputs"

static int	errors(char *message, int output)
{
	printf("%s", message);
	return (output);
}

static char	*filename(const char *format_string, unsigned long file_id)
{
	char	*name;

	name = (char *)malloc(sizeof(char) * \
		(snprintf(NULL, 0, format_string, file_id) + 1));
	sprintf(name, format_string, file_id);
	return (name);
}

static char	*generate_tetrimino(unsigned short tetrimino)
{
	unsigned char	shift;
	unsigned char	char_count;
	unsigned char	height;
	char			*tetrimino_string;

	tetrimino_string = (char *)malloc(sizeof(char) * (LEN_TETRIMINO_STR + 1));
	shift = LEN_TETRIMINO;
	char_count = 0;
	height = 0;
	while (shift--)
	{
		if (tetrimino >> shift & 1)
			tetrimino_string[char_count++] = '#';
		else
			tetrimino_string[char_count++] = '.';
		if (char_count % TETRIMINO_STR_ROW_WIDTH == 4)
		{
			tetrimino_string[char_count++] = '\n';
			height++;
		}
	}
	tetrimino_string[LEN_TETRIMINO_STR] = '\0';
	return (tetrimino_string);
}

static int	generator(unsigned short *tetriminoes)
{
	static unsigned long	file_id = 0;
	char					*name;
	int						fd;
	char					*tetrimino_string;

	name = filename("./"OUTPUT_DIR"/%05lutest.generatedinput", file_id++);
	printf("processing file: %s\n", name);
	fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		printf("ERRNO: FILE OPEN ERROR: %s\n", strerror(errno));
		return (errors("file open error", -1));
	}
	while (*tetriminoes)
	{
		tetrimino_string = generate_tetrimino(*tetriminoes);
		write(fd, tetrimino_string, LEN_TETRIMINO_STR);
		if (*++tetriminoes)
			write(fd, "\n", 1);
		free(tetrimino_string);
	}
	return (0);
}

static void	function_loader_for_debugging(void)
{
	char			*t_2_ascii;

	t_2_ascii = long_to_ascii_binary(T_2);
	free(t_2_ascii);
	display_tetrimino_short(J_1);
}

/*
	if (strstr(strrev(cwd), strrev(CWD)))
	^Will always match starting from the end.
	Add chmod to change directory mode to include executable rights.
*/

int	main(void)
{
	static struct stat	st = {0};
	static char			cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("Current working dir: %s\n", cwd);
		if (strstr(cwd, CWD))
		{
			if (stat(OUTPUT_DIR, &st) == -1)
				mkdir(OUTPUT_DIR, 0755);
		}
		else
		{
			perror("please run inside the cwd of " CWD);
			return (1);
		}
	}
	else
	{
		perror("getcwd() error");
		return (1);
	}
	generator((unsigned short []){O_0, I_1, J_2, L_0, 0});
	function_loader_for_debugging();
	return (0);
}
