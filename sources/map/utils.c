/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:45:48 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/17 04:23:06 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_iswall(char **map, double i, double j)
{
	int	x;
	int	y;
	int	line_size;
	int	column_size;

	line_size = -1;
	column_size = 0;
	while (map[++line_size])
	{
		if (column_size < (int)ft_strlen(map[line_size]))
			column_size = ft_strlen(map[line_size]);
	}
	y = (int) floor(i / TILE_SIZE);
	x = (int) floor(j / TILE_SIZE);
	if (x < 0 || y < 0 || x > column_size || y > line_size - 1)
		return (-1);
	if (map[y][x] == '0')
		return (1);
	else
		return (0);
}

static t_bool	exists_in_map(char **map, int x, int y)
{
	int	column;
	int	row;

	row = 0;
	if (x < 0 || y < 0)
		return (false);
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (row == y && column == x)
				return (true);
			column++;
		}
		row++;
	}
	return (false);
}

int	is_wall(char **map, int x, int y)
{
	if (!exists_in_map(map, x, y))
		return (-1);
	if (map[y][x] != '1')
		return (0);
	return (1);
}
