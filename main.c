#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	char	*stock;
	int		fd;
	int		i;
	t_tetri	*tetri;
	char	**tetri_map;
	int size;

	size = 2;
	if (argc != 2)
	{
		ft_putendl("usage [map]");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	stock = stock_str(fd);
	if (!check(stock))
	{
		ft_putendl("error");
		return (0);
	}
	close(fd);
	tetri = stock_tetri(stock);
	tetri_map = tetri_map_new(tetri_map, size);
	print_map(tetri_map, size);
	return (0);
}
