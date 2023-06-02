/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:25:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/02 23:24:58 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx_ptr(t_data *data);
static void	init_mlx_win(t_data *data);
static void	set_img(t_data *data);

void    setup_minilibx(t_data *data)
{
	init_mlx_ptr(data);
	init_mlx_win(data);
	set_img(data);
}

void set_img(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->columns * TILE_SIZE, data->rows * TILE_SIZE);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
}

static void	init_mlx_ptr(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
    {
		printf("Couldn't find mlx pointer. Try it using a VNC.\n");
		exit (0);
    }
}

static void	init_mlx_win(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	data->columns * TILE_SIZE, data->rows * TILE_SIZE, "Cub3D Minimap");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		printf("Couldn't create the Window.\n");
		exit (0);
	}
}
