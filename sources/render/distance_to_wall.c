/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:37:56 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/14 05:00:27 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double			get_player_distance_to_wall(t_data *data, t_player *player, \
t_ray *ray);
static double	distance_horizontal_wall(t_data *data, t_player *player, \
t_ray *ray);
static double	distance_vertical_wall(t_data *data, t_player *player, \
t_ray *ray);
static double	distance_to_wall(t_data *data, \
double x_step, double y_step, double x_intercept, double y_intercept);

double	get_player_distance_to_wall(t_data *data, t_player *player, t_ray *ray)
{
	double	horizontal_wall_dist;
	double	vertical_wall_dist;
	double	correct;

	correct = cos(normalize_radian_angle(player->angle - ray->angle));
	horizontal_wall_dist = distance_horizontal_wall(data, player, ray) * correct;
	vertical_wall_dist = distance_vertical_wall(data, player, ray) * correct;
	if (horizontal_wall_dist < vertical_wall_dist)
	{
		ray->orientation = HORIZONTAL;
		return (horizontal_wall_dist);
	}
	ray->orientation = VERTICAL;
	return (vertical_wall_dist);
}

static double	distance_horizontal_wall(t_data *data, t_player *player, \
t_ray *ray)
{
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;

	// seno == 0 nunca vai encontrar uma parede horizontal
	if (sin(ray->angle) == 0)
		return (MAX);
	y_intercept = floor(player->y / TILE_SIZE) * TILE_SIZE - 0.001;
	if (ray->angle > PI) // facing UP
		y_intercept += TILE_SIZE;
	x_intercept = player->x + (y_intercept - player->y) / tan(ray->angle);
	y_step = TILE_SIZE;
	if (ray->angle > PI) // facing UP
		y_step *= -1;
	x_step = TILE_SIZE / tan(ray->angle);
	if ((ray->angle > PI / 2) && (ray->angle < 3 * PI / 2) && (x_step > 0))
		x_step *= -1;
	if (((ray->angle < PI / 2) || (ray->angle > 3 * PI / 2)) && (x_step < 0))
		x_step *= -1;
	return (distance_to_wall(data, x_step, y_step, x_intercept, y_intercept));
}

static double	distance_vertical_wall(t_data *data, t_player *player, \
t_ray *ray)
{	
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;

	if (cos(ray->angle) == 0)
		return (MAX);
	x_intercept = floor(player->x / TILE_SIZE) * TILE_SIZE - 0.001;
	if ((ray->angle < PI / 2) || (ray->angle > 3 * PI / 2)) // facing right
		x_intercept += TILE_SIZE;
	x_step = TILE_SIZE;
	y_intercept = player->y + (x_intercept - player->x) * tan(ray->angle);
	if ((ray->angle > PI / 2) && (ray->angle < 3 * PI / 2)) // facing left
		x_step *= -1;
	y_step = TILE_SIZE * tan(ray->angle);
	if ((ray->angle < PI) && (y_step > 0)) // facinf up
		y_step *= -1;
	if ((ray->angle > PI) && (y_step < 0)) // facinf down
		y_step *= -1;
	return (distance_to_wall(data, x_step, y_step, x_intercept, y_intercept));
}

static double	distance_to_wall(t_data *data, \
double x_step, double y_step, double x_intercept, double y_intercept)
{
	double	player_distance_to_wall;
	double	adjacent;
	double	opposite;
	double	hit_wall_x;
	double	hit_wall_y;

	hit_wall_x = x_intercept;
	hit_wall_y = y_intercept;
	while (!is_wall(data->map, \
	floor(hit_wall_x / TILE_SIZE), floor(hit_wall_y / TILE_SIZE)))
	{
		hit_wall_x += x_step;
		hit_wall_y += y_step;
	}
	if (is_wall(data->map, \
	floor(hit_wall_x / TILE_SIZE), floor(hit_wall_y / TILE_SIZE)) == -1)
		return (MAX);
	adjacent = hit_wall_x - data->player.x;
	opposite = hit_wall_y - data->player.y;
	player_distance_to_wall = hypot(adjacent, opposite);
	return (player_distance_to_wall);
}
