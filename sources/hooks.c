/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 04:23:15 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/27 12:13:23 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_data *data)
{
	data->rows = 0;
	exit (0);
	return (0);
}

void player_move(t_data *data, int new_x, int new_y)
{
	img_pix_put(&data->img, data->player.x, data->player.y, FLOOR_COLOR);
	data->player.x = new_x;
	data->player.y = new_y;
	img_pix_put(&data->img, data->player.x, data->player.y, WHITE_PIXEL);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	
}

int	handle_input(int keysym, t_data *data)
{
	int x;
	int y;

	x = data->player.x;
	y = data->player.y;
	if (keysym == KEY_UP || keysym == KEY_W)
		player_move(data, x, --y);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		player_move(data, --x, y);
	if (keysym == KEY_RIGHT || keysym == KEY_S)
		player_move(data, ++x, y);
	if (keysym == KEY_DOWN || keysym == KEY_D)
		player_move(data, x, ++y);
	if (keysym == KEY_Q || keysym == KEY_ESC)
		close_game(data);
	return (0);
}
