/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:30:29 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/20 17:08:59 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_player_starting_pos(char **map);
static void	check_map_char_elements(char **map);

void	map_validation(char **file_content)
{
	check_player_starting_pos(file_content);
	check_map_char_elements(file_content);
	check_is_map_surrounded_by_walls(file_content);
}

static void	check_player_starting_pos(char **map)
{
	int	line;
	int	column;

	line = NUM_OF_ELEM_BEFORE_MAP;
	while (map[line])
	{
		column = 0;
		while (map[line][column])
		{
			if (!ft_strchr("01NSEW ", map[line][column]))
			{
				ft_free_str_array(map);
				error_manager(ERROR_MAP, INVALID_ELEMENT, 0);
			}	
			column++;
		}
		line++;
	}
}

static void	check_map_char_elements(char **map)
{
	int	line;
	int	column;
	int	player_starting_pos;

	line = NUM_OF_ELEM_BEFORE_MAP;
	player_starting_pos = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column])
		{
			if (ft_strchr("NSEW", map[line][column]))
				player_starting_pos++;
			column++;
		}
		line++;
	}
	if (player_starting_pos != 1)
	{
		ft_free_str_array(map);
		if (player_starting_pos > 1)
			error_manager(ERROR_MAP, MULTIPLE_START_POSITION, 0);
		error_manager(ERROR_MAP, MISSING_START_POSITION, 0);
	}
}
