/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:45:48 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/04 21:48:44 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	exists_in_map(char **map, int x, int y)
{
	int	column;
	int	row;

	row = 0;
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

t_bool	is_wall(char **map, int x, int y)
{
	if (!exists_in_map(map, x, y))
		error_manager(ERROR_MAP, NOT_SURROUNDED_BY_WALLS, 0);
	if (map[y][x] == '1')
		return (true);
	return (false);
}
