/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/18 09:03:16 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_img(t_data *data);
void set_player_pos(t_data *data);
void define_start_direction(t_data *data, int x, int y);

int main ( int argc, char **argv )
{
	t_data		*data;
	argc = (int) argc;
	argv = (char **) argv;

	//arguments_validation(argc, argv);
	data = create_data();
	map_init(argv[1], data);
	//get_cub_file_info(data, argv[MAP_ARG]);
	set_minilibx(data);
	set_img(data);
	set_player_pos(data);
	// Tecla Pressionada
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_input, data);

	// X na janela
	mlx_hook(data->win_ptr, DestroyNotify, ButtonPressMask, close_game, data);

	// Renderizar imagem (com exposure para mesmo sendo sobreposta reprintar)
	mlx_hook(data->win_ptr, Expose, ExposureMask, render_map, data);

	mlx_loop(data->mlx_ptr);

	clear_data(data);

	return (0);
}

void set_img(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->columns * TILE_SIZE, data->rows * TILE_SIZE);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
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