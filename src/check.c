/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:16:29 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/12 16:29:18 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		check_link(char *stock, int j)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i + j < 20 + j)
	{
		if (stock[i + j] == '#')
		{
			if ((i + j + 1) < (20 + j) && stock[i + j + 1] == '#')
				count++;
			if ((i + j - 1) >= (0 + j) && stock[i + j - 1] == '#')
				count++;
			if ((i + j + 5) < (20 + j) && stock[i + j + 5] == '#')
				count++;
			if ((i + j - 5) >= (0 + j) && stock[i + j - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		count_valid_char(char *stock, int j)
{
	int dash;
	int dot;
	int newline;
	int i;

	i = 0;
	dash = 0;
	dot = 0;
	newline = 0;
	while (i + j < 20 + j && stock[i + j] != '\0')
	{
		if (stock[i + j] == '#')
			dash++;
		if (stock[i + j] == '.')
			dot++;
		if (stock[i + j] == '\n')
			newline++;
		i++;
	}
	if (dash == 4 && dot == 12 && newline == 4)
		return (1);
	return (0);
}

int		check_str(char *stock)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (stock[i + j] != '\0')
	{
		if (!(check_link(stock, j) && count_valid_char(stock, j)))
			return (0);
		i = 19;
		if (stock[i + j] == '\n' && stock[i + j + 1] == '\0')
			return (1);
		if (stock[i + j] == '\n' && stock[i + j + 1] == '\n'
				&& (stock[i + j + 2] == '.' || stock[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}

int		check_tetri(char **map, t_tetri *tetri, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetri->y[i] < size && tetri->x[i] < size &&
				map[tetri->y[i]][tetri->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
