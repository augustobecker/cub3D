/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:45:48 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/13 16:30:15 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	exists_in_map(char **map, int x, int y)
{
	int	column;
	int	row;

	row = 0;
	if (x < 0 || y < 0)
		return (false);
	while (map[row] && row <= y)
	{
		column = 0;
		while (map[row][column] && column <= x)
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
		return -1;
		//error_manager(ERROR_MAP, NOT_SURROUNDED_BY_WALLS, 0);
	if (map[y][x] == '1')
		return (1);
	return (0);
}
