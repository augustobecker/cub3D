/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:37:56 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/13 17:16:27 by acesar-l         ###   ########.fr       */
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

	//correct = cos(normalize_radian_angle(player->angle - ray->angle));
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

	if (sin(ray->angle) == 0)
		return (MAX);
	y_step = TILE_SIZE * -1;
	x_step = TILE_SIZE / tan(ray->angle);
	y_intercept = floor(player->y / TILE_SIZE) * TILE_SIZE - 0.001;
	if (sin(ray->angle) < 0) //sen neg == 180 til 360
	{
		y_intercept += TILE_SIZE;
		y_step = TILE_SIZE;
	}
	x_intercept = player->x + (y_intercept - player->y) / tan(ray->angle);
	if (((cos(ray->angle) < 0) && (x_step > 0)) // ESQUERDA e x_step para direita (+)
		|| ((cos(ray->angle) > 0) && (x_step < 0))) // DIREITA e x_step para esquerda (-)
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
	x_step = -1 * TILE_SIZE;
	x_intercept = floor(player->x / TILE_SIZE) * TILE_SIZE - 0.001;
	if (cos(ray->angle) > 0) // DIREITA // cos neg ESQUERDA (90 - 270) | resto positivo
	{
		x_intercept += TILE_SIZE;
		x_step = TILE_SIZE;
	}
	y_intercept = player->y + (x_intercept - player->x) * tan(ray->angle);
	y_step = TILE_SIZE * tan(ray->angle);
	if (((sin(ray->angle) > 0) && (y_step > 0))  // olhando para cima, e y_step para baixo (+)
		|| ((sin(ray->angle) < 0) && (y_step < 0))) // olhando para baixo, e y_step para cima (-)
		y_step *= -1;
	return (distance_to_wall(data, x_step, y_step, x_intercept, y_intercept));
}

static double	distance_to_wall(t_data *data, \
double x_step, double y_step, double x_intercept, double y_intercept)
{
	double	player_distance_to_wall;
	double	adjacent;
	double	opposite;
	int		retorno;

	//printf("Map breaked the damn thing\n");
	//printf("\t [%f] | [%f] \n", x_intercept, y_intercept);
	//printf("\tmap[%f][%f] = \n", floor(x_intercept / TILE_SIZE), floor(y_intercept / TILE_SIZE));
	retorno = is_wall(data->map, \
	floor(x_intercept / TILE_SIZE), floor(y_intercept / TILE_SIZE));
	if (retorno == 0)
	{
		x_intercept += x_step;
		y_intercept += y_step;
	}
	if (retorno == -1)
		return (MAX);
	adjacent = data->player.x - x_intercept;
	if (adjacent < 0)
		adjacent *= -1;
	opposite = data->player.y - y_intercept;
	if (opposite < 0)
		opposite *= -1;
	player_distance_to_wall = hypot(adjacent, opposite);
	return (player_distance_to_wall);
}
