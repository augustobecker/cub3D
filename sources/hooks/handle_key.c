/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:09:17 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/06/21 00:37:35 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keysym, t_data *data)
{
	if (keysym == KEY_Q || keysym == KEY_ESC)
		close_game(data);
	else if (keysym == KEY_W)
		data->player.move = UP;
	else if (keysym == KEY_D)
		data->player.move = RIGHT;
	else if (keysym == KEY_A)
		data->player.move = LEFT;
	else if (keysym == KEY_S)
		data->player.move = DOWN;
	else if (keysym == KEY_LEFT)
		data->player.turn = LEFT;
	else if (keysym == KEY_RIGHT)
		data->player.turn = RIGHT;
	return (0);
}

int	key_unpress(int keysym, t_data *data)
{
	if (keysym == KEY_W)
		data->player.move = STOP;
	else if (keysym == KEY_D)
		data->player.move = STOP;
	else if (keysym == KEY_A)
		data->player.move = STOP;
	else if (keysym == KEY_S)
		data->player.move = STOP;
	else if (keysym == KEY_LEFT)
		data->player.turn = STOP;
	else if (keysym == KEY_RIGHT)
		data->player.turn = STOP;
	return (0);
}
