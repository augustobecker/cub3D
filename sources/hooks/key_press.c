/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:09:17 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/06/05 18:12:19 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_data *data)
{
	if (key == KEY_ESC || key == KEY_Q)
		close_game(data);
	else if (key == KEY_A)
		data->player.move = LEFT;
	else if (key == KEY_D)
		data->player.move = RIGHT;
	else if (key == KEY_W)
		data->player.move = UP;
	else if (key == KEY_S)
		data->player.move = DOWN;
	if (key == KEY_LEFT)
		data->player.turn = LEFT;
	else if (key == KEY_RIGHT)
		data->player.turn =  RIGHT;
	return (0);
}