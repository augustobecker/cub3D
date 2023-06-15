/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:47:12 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/12 23:09:17 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_starting_angle(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'N')
		data->player.angle = 0.5 * PI;
	if (data->map[y][x] == 'S')
		data->player.angle = 1.5 * PI;
	if (data->map[y][x] == 'E')
		data->player.angle = 0;
	if (data->map[y][x] == 'W')
		data->player.angle = PI;
}

void	set_player_starting_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (ft_strchr("NSEW", data->map[y][x]))
			{
				data->player.x = x * TILE_SIZE;
				data->player.y = y * TILE_SIZE;
				set_player_starting_angle(data, x, y);
				data->map[y][x] = '0';
				break ;
			}
			x++;
		}
		y++;
	}
}

void	set_player_info(t_data *data)
{
	data->player.walk_direction = 0;
	data->player.turn_direction = 0;
	data->player.walk_speed = 10;
	data->player.turn_speed = 45 * (PI / 180);
	data->player.turn = 0;
	data->player.move = 0;
	data->player.distance_to_wall = 0;
}

void	set_textures_info(t_data *data, char **cubfile_content)
{
	data->no_txtr.path = get_texture_path(cubfile_content, "NO ");
	if (!data->no_txtr.path)
	{
		ft_free_str_array(cubfile_content);
		error_manager(ERROR_MALLOC, MALLOC_ERROR, data);
	}
	data->so_txtr.path = get_texture_path(cubfile_content, "SO ");
	if (!data->so_txtr.path)
	{
		ft_free_str_array(cubfile_content);
		error_manager(ERROR_MALLOC, MALLOC_ERROR, data);
	}
	data->ea_txtr.path = get_texture_path(cubfile_content, "EA ");
	if (!data->ea_txtr.path)
	{
		ft_free_str_array(cubfile_content);
		error_manager(ERROR_MALLOC, MALLOC_ERROR, data);
	}
	data->we_txtr.path = get_texture_path(cubfile_content, "WE ");
	if (!data->we_txtr.path)
	{
		ft_free_str_array(cubfile_content);
		error_manager(ERROR_MALLOC, MALLOC_ERROR, data);
	}
}

t_data	*setup_data(char **cubfile_content)
{
	t_data	*data;

	data = create_data();
	data->map = ft_copy_str_array(&cubfile_content[NUM_OF_ELEM_BEFORE_MAP]);
	if (!data->map)
		error_manager(ERROR_MALLOC, MALLOC_ERROR, data);
	set_textures_info(data, cubfile_content);
	ft_free_str_array(cubfile_content);
	set_player_starting_position(data);
	set_player_info(data);
	return (data);
}
