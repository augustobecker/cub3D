/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:25:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 23:05:22 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx_ptr(t_data *data);
static void	init_mlx_win(t_data *data);
static void	set_img(t_data *data);

void	setup_minilibx(t_data *data)
{
	init_mlx_ptr(data);
	init_mlx_win(data);
	set_img(data);
}

void	set_full_img(t_data *data)
{
	data->full_img.mlx_img = mlx_new_image(data->mlx_ptr, \
	RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
	data->full_img.addr = mlx_get_data_addr(data->full_img.mlx_img, \
	&data->full_img.bpp, &data->full_img.line_len, &data->full_img.endian);
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
