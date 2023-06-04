/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:19:38 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/06/04 00:09:36 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	distance_wall(t_data *data);
static double	vertical_wall(t_data *data);
static double	ft_loop_distance(t_data *data);
int	ft_iswall(char **map, double i, double j);

void	render(t_data *data)
{
	data->player.ray_angle = normalize_radiun_angle(data->player.ray_angle + \
	PI / 6);
	while (data->player.ray < WIN_WIDTH)
	{
		data->player.ray_angle = normalize_radiun_angle(data->player.ray_angle
		- (PI / 3) / WIN_WIDTH);
		distance_wall(data);
		//TODO IMPLEMENTAR DRAW
		data->player.ray++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->full_img->addr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->full_img->addr);
	free(data->full_img);

}


void	distance_wall(t_data *data)
{
	double	dh;
	double	dv;
	double	correction;

	correction = cos(normalize_radiun_angle(data->player.angle - data->player.ray_angle));
	dh = horizontal_wall(data) * correction;
}

static double	horizontal_wall(t_data *data)
{
	if (sin(data->player.ray_angle) == 0)
		return(vertical_wall (data));
	if (sin(data->player.ray_angle) > 0)
	{
		data->player.dy = -1 * TILE_SIZE;
		data->player.yo = floor(data->player.y / TILE_SIZE) * TILE_SIZE - 0.001;
		data->player.xo = (data->player.y - data->player.yo) * cos(data->player.ray_angle) / sin(data->player.ray_angle) + data->player.x;
		data->player.dx = TILE_SIZE * cos(data->player.ray_angle) / sin(data->player.ray_angle);
	}
	else
	{
		data->player.dy = TILE_SIZE;
		data->player.yo = floor(data->player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		data->player.xo = (data->player.y - data->player.yo) * cos(data->player.ray_angle) / sin(data->player.ray_angle) + data->player.x;
		data->player.dx = -1 * TILE_SIZE * cos(data->player.ray_angle) / sin(data->player.ray_angle);
	}
	return(loop_distance(data));
}

static double	vertical_wall(t_data *data)
{
	if (cos(data->player.ray_angle) == 0);
		return(horizontal_wall(data));
	if (cos(data->player.ray_angle) > 0)
	{
		data->player.dx = TILE_SIZE;
		data->player.dy = -1 * tan(data->player.ray_angle) * TILE_SIZE;
		data->player.xo = floor(data->player.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		data->player.yo = tan(data->player.ray_angle) * (data->player.x - data->player.xo) + data->player.y;
	}
	else
	{
		data->player.dx = -1 * TILE_SIZE;
		data->player.dy = tan(data->player.ray_angle) * TILE_SIZE;
		data->player.xo = floor(data->player.x / TILE_SIZE) * TILE_SIZE - 0.001;
		data->player.yo = tan(data->player.ray_angle) * (data->player.x - data->player.xo) + data->player.y;
	}
	return (loop_distance(data));
}

static double	ft_loop_distance(t_data *data)
{
	while (is_wall(data->map, data->player.yo, data->player.xo) == 1)
	{
		data->player.yo += data->player.dy;
		data->player.xo += data->player.dx;
	}
	if (is_wall(data->map, data->player.yo, data->player.xo) == -1)
		return MAX;
	return (distance(data->player.x, data->player.y, data->player.xo, data->player.yo));

}

int	ft_iswall(char **map, double i, double j)
{
	int	x;
	int	y;
	int	line_size;
	int	column_size;

	line_size = -1;
	column_size = 0;
	while (map[++line_size])
	{
		if (column_size < (int)ft_strlen(map[line_size]))
			column_size = ft_strlen(map[line_size]);
	}
	y = (int) floor(i / TILE_SIZE);
	x = (int) floor(j / TILE_SIZE);
	if (x < 0 || y < 0 || x > column_size || y > line_size - 1)
		return (-1);
	if (map[y][x] == '0')
		return (1);
	else
		return (0);
}