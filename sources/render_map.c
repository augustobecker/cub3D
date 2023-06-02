/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:10:25 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/02 14:39:26 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void render_rect_player(t_data *data,t_img *img, int x_start, int y_start, int color);

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr+ (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void render_fov(t_data *data)
{
	double line_x;
	double line_y;

	line_x = data->player.x + cos(data->player.rotation_angle) * -7;
	line_y = data->player.y + sin(data->player.rotation_angle) * -7;
	img_pix_put(&data->img, line_x, line_y, RED_PIXEL);
}


void render_player(t_data *data)
{
	render_fov(data);
	//img_pix_put(&data->img, data->player.x, data->player.y, WHITE_PIXEL);
	render_rect_player(data, &data->img, data->player.x, data->player.y, WHITE_PIXEL);
}

void render_rect_player(t_data *data,t_img *img, int x_start, int y_start, int color)
{
	int x;
	int y;

	y = y_start;
	while (y < (y_start + data->player.height))
	{
		printf("Valor de y = %d\nValor total= %f\n", y, (y_start + data->player.height));
		x = x_start;
		while (x < (x_start + data->player.width))
		{
			img_pix_put(img, x, y, color);
			x++;
		}
		y++;
	}
}



void render_rect(t_img *img, int x_start, int y_start, int color)
{
	int x;
	int y;

	y = y_start;
	while (y < y_start + (TILE_SIZE * MINIMAP_SCALE))
	{
		x = x_start;
		while (x < x_start + (TILE_SIZE * MINIMAP_SCALE))
		{
			img_pix_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

void identify_rect(t_data *data, int x, int y)
{
	if ((data->map[y][x] != ' ') && (data->map[y][x] != '1') && (data->map[y][x] != '0') &&
	(data->map[y][x] != 'N') && (data->map[y][x] != 'S') && (data->map[y][x] != 'W') && (data->map[y][x] != 'E'))
		return;
	if (data->map[y][x] == ' ')
		render_rect(&data->img, x * TILE_SIZE * MINIMAP_SCALE , y * TILE_SIZE * MINIMAP_SCALE, BLACK_PIXEL);
	if (data->map[y][x] == '1')
		render_rect(&data->img, x * TILE_SIZE * MINIMAP_SCALE, y * TILE_SIZE * MINIMAP_SCALE, WALL_COLOR);
	if (data->map[y][x] == '0')
		render_rect(&data->img, x * TILE_SIZE * MINIMAP_SCALE, y * TILE_SIZE * MINIMAP_SCALE, FLOOR_COLOR);
	if ((data->map[y][x] == 'N')
	|| (data->map[y][x] == 'S')
	|| (data->map[y][x] == 'W')
	|| (data->map[y][x] == 'E'))
		render_rect(&data->img, x * TILE_SIZE * MINIMAP_SCALE, y * TILE_SIZE * MINIMAP_SCALE, FLOOR_COLOR);
	render_player(data);
}

int render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			identify_rect(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
