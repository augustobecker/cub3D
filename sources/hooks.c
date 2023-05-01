/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 04:23:15 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/01 20:05:11 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_data *data)
{
	data->rows = 0;
	exit (0);
	return (0);
} 

double normalize_angle(double angle)
{
	if (angle >= (2 * PI))
		angle -= 2 * PI;
	if (angle == 0)
		angle = 2 * PI;
	if (angle < 0)
		angle = 2 * PI + angle;
	return (angle);
}

t_bool	is_a_wall(char **map, int x, int y)
{
	x = x / (TILE_SIZE * MINIMAP_SCALE);
	y = y / (TILE_SIZE * MINIMAP_SCALE);
	return (map[y][x] == '1');
}

void	player_update_position(t_data *data, int player_walk, double rotate_player)
{
	double	new_x;
	double	new_y;

	data->player.rotation_angle += rotate_player;
	data->player.rotation_angle = normalize_angle(data->player.rotation_angle);
	new_x = data->player.x + cos(data->player.rotation_angle) * player_walk;
	new_y = data->player.y + sin(data->player.rotation_angle) * player_walk;
	if (!is_a_wall(data->map, new_x, new_y))
	{
		data->player.x = new_x;
		data->player.y = new_y;
		render_map(data);
	}
}

int	handle_input(int keysym, t_data *data)
{
	int 	player_walk;
	double	player_rotate;

	player_walk = 0;
	player_rotate = 0;
	if (keysym == KEY_Q || keysym == KEY_ESC)
		close_game(data);
	if (keysym == KEY_UP || keysym == KEY_W)
		player_walk = NORTH_DIR * WALK_SPEED;
	if (keysym == KEY_DOWN || keysym == KEY_D)
		player_walk = SOUTH_DIR * WALK_SPEED;
	if (keysym == KEY_LEFT || keysym == KEY_A)
		player_rotate =  WEST_DIR * ROTATION_SPEED;
	if (keysym == KEY_RIGHT || keysym == KEY_S)
		player_rotate =  EAST_DIR * ROTATION_SPEED;
	if ((keysym == KEY_UP || keysym == KEY_W) 
	|| (keysym == KEY_DOWN || keysym == KEY_D)
	|| (keysym == KEY_LEFT || keysym == KEY_A)
	|| (keysym == KEY_RIGHT || keysym == KEY_S))
		player_update_position(data, player_walk, player_rotate);
	return (0);
}