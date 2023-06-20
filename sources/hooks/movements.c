/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:27:49 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/06/20 05:21:10 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_utils(t_data *data);
static void	turn_utils(t_data *data);

int	move_and_turn(t_data *data)
{
	t_player *player;

	player = &data->player;
	if ((player->move) == UP && (!is_wall(data->map,
	(int) floor((player->x + WALK_SPEED * cos(player->angle)) / TILE_SIZE),
	(int) floor((player->y - WALK_SPEED * sin(player->angle)) / TILE_SIZE))))
	{
		player->x += WALK_SPEED * cos(player->angle);
		player->y -= WALK_SPEED * sin(player->angle);
	}
	else if ((player->move == DOWN) && (!is_wall(data->map,
	(int) floor((player->x - WALK_SPEED * cos(player->angle)) / TILE_SIZE),
	(int) floor((player->y + WALK_SPEED * sin(player->angle)) / TILE_SIZE))))
	{
		player->x -= WALK_SPEED * cos(player->angle);
		player->y += WALK_SPEED * sin(player->angle);
	}
	move_utils(data);
	turn_utils(data);
	render(data);
	return (0);
}

static void	move_utils(t_data *data)
{
	t_player *player;

	player = &data->player;
	if ((player->move == RIGHT) && (!is_wall(data->map,
	(int) floor((player->x + WALK_SPEED * sin(player->angle)) / TILE_SIZE),
	(int) floor((player->y + WALK_SPEED * cos(player->angle)) / TILE_SIZE))))
	{
		player->x += WALK_SPEED * sin(player->angle);
		player->y += WALK_SPEED * cos(player->angle);
	}
	else if ((player->move == LEFT) && (!is_wall(data->map,
	(int) floor((player->x - WALK_SPEED * sin(player->angle)) / TILE_SIZE),
	(int) floor((player->y - WALK_SPEED * cos(player->angle)) / TILE_SIZE))))
	{
		player->x -= WALK_SPEED * sin(player->angle);
		player->y -= WALK_SPEED * cos(player->angle);
	}
}

static void	turn_utils(t_data *data)
{
	t_player *player;

	player = &data->player;
	if (player->turn == LEFT)
		player->angle = normalize_radian_angle(player->angle
				+ ROTATION_SPEED);
	if (player->turn == RIGHT)
		player->angle = normalize_radian_angle(player->angle
				- ROTATION_SPEED);
}
