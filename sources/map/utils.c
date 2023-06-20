/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:45:48 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/20 17:00:06 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				is_wall(char **map, int x, int y);
static t_bool	exists_in_map(char **map, int x, int y);

int	is_wall(char **map, int x, int y)
{
	if (!exists_in_map(map, x, y))
		return (-1);
	if (map[y][x] != '1')
		return (0);
	return (1);
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
