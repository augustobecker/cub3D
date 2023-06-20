/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:37:56 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/20 03:35:10 by acesar-l         ###   ########.fr       */
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
t_player_collision_rule *player_hit);

double	get_player_distance_to_wall(t_data *data, t_player *player, \
t_ray *ray)
{
	double	horizontal_wall_dist;
	double	vertical_wall_dist;
	double	correct;

	correct = cos(normalize_radian_angle(player->angle - ray->angle));
	horizontal_wall_dist = \
	distance_horizontal_wall(data, player, ray) * correct;
	vertical_wall_dist = \
	distance_vertical_wall(data, player, ray) * correct;
	if (vertical_wall_dist < horizontal_wall_dist)
	{
		ray->orientation = VERTICAL;
		return (vertical_wall_dist);
	}
	ray->orientation = HORIZONTAL;
	return (horizontal_wall_dist);
}

static double	distance_horizontal_wall(t_data *data, t_player *player, \
t_ray *ray)
{
	t_player_collision_rule	player_hit;

	if (sin(ray->angle) == 0)
		return (distance_vertical_wall(data, player, ray));
	if (sin(ray->angle) > 0)
	{
		player_hit.y_step = -1 * TILE_SIZE;
		player_hit.y_intercept = floor(player->y / TILE_SIZE) \
		* TILE_SIZE - 0.001;
		player_hit.x_intercept = (player->y - player_hit.y_intercept) * \
		cos(ray->angle) / sin(ray->angle) + player->x;
		player_hit.x_step = TILE_SIZE * cos(ray->angle) / sin(ray->angle);
	}
	else
	{
		player_hit.y_step = TILE_SIZE;
		player_hit.y_intercept = floor(player->y / TILE_SIZE) * \
		TILE_SIZE + TILE_SIZE;
		player_hit.x_intercept = (player->y - player_hit.y_intercept) * \
		cos(ray->angle) / sin (ray->angle) + player->x;
		player_hit.x_step = -1 * TILE_SIZE * cos(ray->angle) / sin (ray->angle);
	}
	return (distance_to_wall(data, &player_hit));
}

static double	distance_vertical_wall(t_data *data, t_player *player, \
t_ray *ray)
{
	t_player_collision_rule	player_hit;

	if (cos(ray->angle) == 0)
		return (distance_horizontal_wall(data, player, ray));
	if (cos(ray->angle) > 0)
	{
		player_hit.x_step = TILE_SIZE;
		player_hit.y_step = -1 * tan(ray->angle) * TILE_SIZE;
		player_hit.x_intercept = floor(player->x / TILE_SIZE) \
		* TILE_SIZE + TILE_SIZE;
		player_hit.y_intercept = tan(ray->angle) \
		* (player->x - player_hit.x_intercept) + player->y;
	}
	else
	{
		player_hit.x_step = -1 * TILE_SIZE;
		player_hit.y_step = tan(ray->angle) * TILE_SIZE;
		player_hit.x_intercept = \
		floor(player->x / TILE_SIZE) * TILE_SIZE - 0.001;
		player_hit.y_intercept = tan(ray->angle) \
		* (player->x - player_hit.x_intercept) + player->y;
	}
	return (distance_to_wall(data, &player_hit));
}

static double	distance_to_wall(t_data *data, \
t_player_collision_rule *player_hit)
{
	double		player_distance_to_wall;
	t_player	player;

	player = data->player;
	while (!is_wall(data->map, \
	(int) floor(player_hit->x_intercept / TILE_SIZE), \
	(int) floor(player_hit->y_intercept / TILE_SIZE)))
	{
		player_hit->x_intercept += player_hit->x_step;
		player_hit->y_intercept += player_hit->y_step;
	}
	if (is_wall(data->map, \
	(int) floor(player_hit->x_intercept / TILE_SIZE), \
	(int) floor(player_hit->y_intercept / TILE_SIZE)) == -1)
		return (MAX);
	player_distance_to_wall = \
	hypot(player.x - player_hit->x_intercept, \
	player.y - player_hit->y_intercept);
	return (player_distance_to_wall);
}
