/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:02:01 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/06/19 23:28:05 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hook_setup(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, move_and_turn, data);
	mlx_hook(data->win_ptr, 2, 1, key_press, data);
	mlx_hook(data->win_ptr, 3, 10, key_unpress, data);
	mlx_hook(data->win_ptr, 17, 0, close_game, data);
	mlx_loop(data->mlx_ptr);
}
