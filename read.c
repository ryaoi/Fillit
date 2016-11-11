/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:58:01 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/09 13:42:48 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "fillit.h"
#include <stdlib.h>

int		count_tetri(char *str)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			result++;
		i++;
	}
	return (result / 4);
}

void	set_tetri(t_tetri **tmp, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			printf("tmp->x[%d] is : %d\n", j, (*tmp)->x[j]);
			printf("tmp->y[%d] is : %d\n", j, (*tmp)->y[j]);
			j++;
		}
		i++;
	}
}

t_tetri	*stock_tetri(char *str)
{
	int 	c_tetri;
	int 	add21;
	char	c;
	t_tetri *stock;
	t_tetri *tmp;

	add21 = 0;
	c = 'A';
	c_tetri = count_tetri(str);
	if (!(stock = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	tmp = stock;
	while (c_tetri > 0)
	{
		tmp->c = c;
		set_tetri(&tmp, ft_strsub(str, 0 + add21, 20));
		if (!(tmp->next = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		tmp = tmp->next;
		c_tetri--;
		c++;
		add21 += 21;
	}
	tmp->next = NULL;
	return (stock);
}

char	*stock_str(int	fd)
{
	int		f;
	int		i;
	char	c;
	char	*str;

	i = 0;
	str = NULL;
	f = read(fd, &c, 1);
	if (f < 0)
		return (NULL);
	if (f == 1)
	{
		str = (char *)malloc(sizeof(char) * 512);
		while (f != '\0')
		{
			str[i] = c;
			i++;
			f = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	return (str);
}

int		main(int argc, char **argv)
{
	char	*stock;
	int		fd;
	int		i;
	t_tetri	*tetri;

	if (argc != 2)
	{
		ft_putendl("usage [map]");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	stock = stock_str(fd);
	if (!check_str(stock))
	{
		ft_putendl("error");
		return (0);
	}
	printf("%s", stock);
	tetri = stock_tetri(stock);
	close(fd);
	solve(tetri);
	return (0);
}
