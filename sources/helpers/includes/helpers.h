/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:53:20 by thakala           #+#    #+#             */
/*   Updated: 2022/01/13 11:14:14 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

void	display_tetrimino_short(short tetrimino);
char	*short_to_ascii_binary(unsigned short n);
void	*debug_error(char *message);
#endif