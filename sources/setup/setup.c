/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:47:12 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/02 18:14:02 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_img(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->columns * TILE_SIZE, data->rows * TILE_SIZE);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
}

void define_start_direction(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'N')
	{
		data->player.vertical_dir = NORTH;
		data->player.rotation_angle = 0.5 * PI; // 90
	}
	if (data->map[y][x] == 'S')
	{
		data->player.vertical_dir = SOUTH;
		data->player.rotation_angle = 1.5 * PI; // 270
	}
	if (data->map[y][x] == 'E')
	{
		data->player.horizontal_dir = EAST;
		data->player.rotation_angle = 0; // 0 || 360
	}
	if (data->map[y][x] == 'W')
	{
		data->player.horizontal_dir = WEST;
		data->player.rotation_angle = PI; // 180
	}
}

void set_player_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
				if ((data->map[y][x] == 'N')
				|| (data->map[y][x] == 'S')
				|| (data->map[y][x] == 'W')
				|| (data->map[y][x] == 'E'))
				{
					data->player.x = x;
					data->player.y = y;
					define_start_direction(data, x, y);
				}
			x++;
		}
		y++;
	}
	data->player.x *= TILE_SIZE * MINIMAP_SCALE;
	data->player.y *= TILE_SIZE * MINIMAP_SCALE;
	data->player.x += TILE_SIZE * MINIMAP_SCALE / 2;
	data->player.y += TILE_SIZE * MINIMAP_SCALE / 2;
}

void set_player(t_data *data){
	data->player.height = 3;
	data->player.width = 3;
	data->player.walk_direction = 0;
	data->player.turn_direction = 0;
	data->player.walkSpeed = 100;
	data->player.turnSpeed = 45 * (PI / 180);
}

void get_map_data(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
			x++;
		y++;
	}
	data->columns = x;
	data->rows = y;
}

void init_all(t_data *data)
{
	set_minilibx(data);
	set_img(data);
	set_player_pos(data);
	set_player(data);
}


t_data *setup_data(char **cubfile_content)
{
	t_data	*data;

	data = create_data();
	data->map = ft_copy_str_array(&cubfile_content[NUM_OF_ELEM_BEFORE_MAP]);
	if (!data->map)
		error_manager(ERROR_MALLOC, MALLOC_ERROR, data);
	ft_free_str_array(cubfile_content);
	get_map_data(data);
	init_all(data);
	return (data);
}