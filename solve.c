#include "fillit.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	xy_tetri(t_tetri **tetri, int x, int y)
{
	int	pos_x;
	int pos_y;
	int i;

	i = 0;
	pos_x = 100;
	pos_y = 100;
	while (i < 4)
	{
		printf("tetri->x[%d] is : %d\n", i, (*tetri)->x[i]);
		if((*tetri)->x[i] < pos_x)
			pos_x = (*tetri)->x[i];
		printf("tetri->y[%d] is : %d\n", i, (*tetri)->y[i]);
		if((*tetri)->y[i] < pos_y)
			pos_y = (*tetri)->y[i];
		i++;
	}
	printf("pos_x is : %d\n", pos_x);
	printf("pos_y is : %d\n", pos_y);
	printf("x is : %d\n", x);
	printf("y is : %d\n", y);
	i --;
	while (i >= 0)
	{
		(*tetri)->x[i] = (*tetri)->x[i] - pos_x + x;
		printf("the new position for tetri->x[%d] is : %d\n", i, (*tetri)->x[i]);
		(*tetri)->y[i] = (*tetri)->y[i] - pos_y + y;
		printf("the new position for tetri->y[%d] is : %d\n", i, (*tetri)->y[i]);
		i--;
	}
}

char	**algo(char **tetri_map, t_tetri *tetri, int size)
{
	int		x;
	int		y;
	char	**map;

	if(tetri->next == NULL)
		return (tetri_map);
	map = NULL;
	y = 0;
	printf("Start loop\n");
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			xy_tetri(&tetri, x, y);
			if (check_tetri(tetri_map, tetri, size))
			{
				printf("Check passed\n");
				map  = insert_tetri(tetri_map, tetri, size);
				map = algo(map, tetri->next, size);	
			}
			if (map)
				return (map);
			printf("remove tetri map\n");
			tetri_map = remove_tetri(tetri_map, tetri, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	solve(t_tetri *tetri)
{
	char	**result;
	char	**tetri_map;
	int		size;

	size = 2;
	tetri_map = tetri_map_new(tetri_map, size);
	result = NULL;
	while (!(result = algo(tetri_map, tetri, size)))
	{
		size++;
		printf("size is : %d\n", size);
		ft_memdel((void **)tetri_map);
		tetri_map = tetri_map_new(tetri_map, size);
	}
	ft_putendl("Solved");
	print_map(result, size);
}
