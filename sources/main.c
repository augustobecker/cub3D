/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/26 04:05:40 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_img(t_data *data);
void set_player_pos(t_data *data);
void define_start_direction(t_data *data, int x, int y);
void get_map_data(t_data *data);
void print_map(t_data *data);

void get_data_info(t_data *data, char **matrix)
{
	int	line;

	line = 0;
	while (matrix[line])
		line++;
	data->lines = line;
}

void	cubfile_validation(t_data *data, char *cubfile_name)
{
	char		*cubfile_content;
	char		**content_matrix;
	
	cubfile_content = read_file(cubfile_name);
	if (!cubfile_content[0])
	{
		free(cubfile_content);
		error_manager(ERROR_TEXTURE, IS_MISSING_ELEM, data);
	}
	content_matrix = ft_split(cubfile_content, '\n');
	free(cubfile_content);
	get_data_info(data, content_matrix);
	texture_validation(data, content_matrix);
}

int main ( int argc, char **argv )
{
	t_data		*data;

	arguments_validation(argc, argv);
	data = create_data();
	cubfile_validation(data, argv[MAP_ARG]);
	get_map_data(data);
	print_map(data);
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

void print_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
			printf("%c", data->map[y][x++]);
		printf("\n");
		y++;
	}
	printf("columns: %d | rows: %d\n", data->columns, data->rows);
}