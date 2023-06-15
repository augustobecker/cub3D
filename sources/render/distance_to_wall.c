/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:37:56 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/14 05:11:07 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_distance_wall(t_data *data);
static double	ft_loop_distance(t_data *data);
static double	ft_horizontal_wall(t_data *data);
static double	ft_vertical_wall(t_data *data);
double			ft_distance(double x1, double y1, double x2, double y2);
double			ft_radian_domain(double angle);

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
		return (0);
	else
		return (1);
}


void	ft_distance_wall(t_data *data)
{
	double	dh;
	double	dv;
	double	correction;

	correction = cos(ft_radian_domain(data->player.angle - data->player.ray_ang));
	dh = ft_horizontal_wall(data) * correction;
	dv = ft_vertical_wall(data) * correction;
	if (dv < dh)
	{
		data->player.status = VERTICAL;
		data->player.distance_to_wall = dv;
	}
	else
	{
		data->player.status = HORIZONTAL;
		data->player.distance_to_wall = dh;
	}
}

static double	ft_horizontal_wall(t_data *data)
{
	if (sin(data->player.ray_ang) == 0)
		return (ft_vertical_wall (data));
	if (sin(data->player.ray_ang) > 0)
	{
		data->player.dy = -1 * TILE_SIZE;
		data->player.yo = floor(data->player.y / TILE_SIZE)
			* TILE_SIZE - 0.001;
		data->player.xo = (data->player.y - data->player.yo)
			* cos(data->player.ray_ang) / sin(data->player.ray_ang) + data->player.x;
		data->player.dx = TILE_SIZE
			* cos(data->player.ray_ang) / sin(data->player.ray_ang);
	}
	else
	{
		data->player.dy = TILE_SIZE;
		data->player.yo = floor(data->player.y / TILE_SIZE)
			* TILE_SIZE + TILE_SIZE;
		data->player.xo = (data->player.y - data->player.yo)
			* cos(data->player.ray_ang) / sin(data->player.ray_ang) + data->player.x;
		data->player.dx = -1 * TILE_SIZE
			* cos(data->player.ray_ang) / sin(data->player.ray_ang);
	}
	return (ft_loop_distance(data));
}

static double	ft_vertical_wall(t_data *data)
{
	if (cos(data->player.ray_ang) == 0)
		return (ft_horizontal_wall (data));
	if (cos(data->player.ray_ang) > 0)
	{
		data->player.dx = TILE_SIZE;
		data->player.dy = -1 * tan (data->player.ray_ang) * TILE_SIZE;
		data->player.xo = floor(data->player.x / TILE_SIZE)
			* TILE_SIZE + TILE_SIZE;
		data->player.yo = tan (data->player.ray_ang)
			* (data->player.x - data->player.xo) + data->player.y;
	}
	else
	{
		data->player.dx = -1 * TILE_SIZE;
		data->player.dy = tan (data->player.ray_ang) * TILE_SIZE;
		data->player.xo = floor(data->player.x / TILE_SIZE)
			* TILE_SIZE - 0.001;
		data->player.yo = tan (data->player.ray_ang) * (data->player.x - data->player.xo)
			+ data->player.y;
	}
	return (ft_loop_distance(data));
}

static double	ft_loop_distance(t_data *data)
{
	while (ft_iswall(data->map, data->player.xo, data->player.yo) == 0)
	{
		data->player.yo += data->player.dy;
		data->player.xo += data->player.dx;
	}
	if (ft_iswall(data->map, data->player.xo, data->player.yo) == -1)
		return (MAX);
	return (ft_distance(data->player.x, data->player.y, data->player.xo, data->player.yo));
}

double	ft_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

double	ft_radian_domain(double angle)
{
	if (angle > 2 * PI)
		angle -= 2 * PI;
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}
