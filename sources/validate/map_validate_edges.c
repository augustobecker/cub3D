/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_edges.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:43:24 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/21 01:06:46 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_is_map_surrounded_by_walls(char **map);
static t_bool	do_horizontal_edges_contain_floor(char **map);
static t_bool	do_vertical_edges_contain_floor(char **map);
static t_bool	is_floor_surrounded_by_empty_space(char **map);

void	check_is_map_surrounded_by_walls(char **map)
{
	if (do_horizontal_edges_contain_floor(&map[NUM_OF_ELEM_BEFORE_MAP]))
	{
		ft_free_str_array(map);
		error_manager(ERROR_MAP, NOT_SURROUNDED_BY_WALLS, 0);
	}
	if (do_vertical_edges_contain_floor(&map[NUM_OF_ELEM_BEFORE_MAP]))
	{
		ft_free_str_array(map);
		error_manager(ERROR_MAP, NOT_SURROUNDED_BY_WALLS, 0);
	}
	if (is_floor_surrounded_by_empty_space(&map[NUM_OF_ELEM_BEFORE_MAP]))
	{
		ft_free_str_array(map);
		error_manager(ERROR_MAP, NOT_SURROUNDED_BY_WALLS, 0);
	}
}

static t_bool	do_horizontal_edges_contain_floor(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (map[y][0] == FLOOR)
			return (true);
		if (map[y][ft_strlen(map[y]) - 1] == FLOOR)
			return (true);
		y++;
	}
	return (false);
}

static t_bool	do_vertical_edges_contain_floor(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y])
		y++;
	while (map[0][x])
	{
		if (map[0][x++] == FLOOR)
			return (true);
	}
	x = 0;
	while (map[y - 1][x])
	{
		if (map[y - 1][x++] == FLOOR)
			return (true);
	}
	return (false);
}

static t_bool	is_floor_surrounded_by_empty_space(char **map)
{
	size_t	columns;
	size_t	x;
	size_t	y;

	y = 1;
	while (map[y + 1])
	{
		x = 1;
		columns = ft_strlen(map[y]) - 1;
		while (x < columns - 1)
		{
			if (map[y][x] == FLOOR)
			{
				if ((x > ft_strlen(map[y - 1])) || (x > ft_strlen(map[y + 1])))
					return (true);
				if ((map[y][x + 1] == EMPTY_SPACE) || (map[y][x - 1] == EMPTY_SPACE)
				|| (map[y + 1][x] == EMPTY_SPACE) || (map[y - 1][x] == EMPTY_SPACE))
					return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}
