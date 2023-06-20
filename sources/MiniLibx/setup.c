/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:25:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/20 17:00:26 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		setup_minilibx(t_data *data);
static void	init_mlx_ptr(t_data *data);
static void	init_mlx_win(t_data *data);

void	setup_minilibx(t_data *data)
{
	init_mlx_ptr(data);
	init_mlx_win(data);
}

static void	init_mlx_ptr(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		error_manager(ERROR_MLX, INIT_ERROR, data);
}

static void	init_mlx_win(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	RESOLUTION_WIDTH, RESOLUTION_HEIGHT, "Cub3D");
	if (data->win_ptr == NULL)
		error_manager(ERROR_MLX, WINDOW_INIT_ERROR, data);
}
