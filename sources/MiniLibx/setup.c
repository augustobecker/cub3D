/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:25:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/28 02:55:35 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx_ptr(t_data *data);
static void	init_mlx_win(t_data *data);

void    set_minilibx(t_data *data)
{
	init_mlx_ptr(data);
	init_mlx_win(data);
}

static void	init_mlx_ptr(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
    {
		clear_data(data);
		error_manager(MLX_INIT_ERROR);
    }
}

static void	init_mlx_win(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (data->win_ptr == NULL)
	{
		clear_data(data);
		error_manager(MLX_WINDOW_INIT_ERROR);
	}
}
