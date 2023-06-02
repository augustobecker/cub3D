/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/02 14:51:02 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_img(t_data *data);
void set_player_pos(t_data *data);
void define_start_direction(t_data *data, int x, int y);
void get_map_data(t_data *data);
void print_map(t_data *data);
void set_player(t_data *data);
int  handle_no_event(void);
void init_all(t_data *data);

int main ( int argc, char **argv )
{
	t_data		*data;

	arguments_validation(argc, argv);
	data = create_data();
	//cubfile_validation(data, argv[MAP_ARG]);
	map_init(argv[1], data);
	init_all(data);
	render_map(data);

	// Tecla Pressionada
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_input, data);

	// X na janela
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, close_game, data);

	// Renderizar imagem (com exposure para mesmo sendo sobreposta reprintar)
	//mlx_hook(data->win_ptr, Expose, ExposureMask, , data);

	// quando no acontecer nenhum evento
	mlx_loop_hook(data->win_ptr, &handle_no_event, data);

	//mlx_hook(data->win_ptr, Expose, ExposureMask, render_map, data);

	//desenhar quando a tela for sobreposta
	//mlx_expose_hook(game->win_ptr, &ft_redraw, game);

	mlx_loop(data->mlx_ptr);

	//setup()
	clear_data(data);

	return (0);
}

void init_all(t_data *data){
	set_minilibx(data);
	data->wall.mlx_img = mlx_new_image(data->mlx_ptr, 32, 32);
	set_img(data);
	set_player_pos(data);
	set_player(data);
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


void set_player(t_data *data){
	data->player.height = 3;
	data->player.width = 3;
	data->player.walk_direction = 0;
	data->player.turn_direction = 0;
	data->player.walkSpeed = 100;
	data->player.turnSpeed = 45 * (PI / 180);
}

int	handle_no_event(void)
{
	return (0);
}