/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:53:50 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/17 23:14:30 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->no_txtr.img->mlx_img);
	free(data->no_txtr.path);
	free(data->no_txtr.img);
	mlx_destroy_image(data->mlx_ptr, data->so_txtr.img->mlx_img);
	free(data->so_txtr.path);
	free(data->so_txtr.img);
	mlx_destroy_image(data->mlx_ptr, data->ea_txtr.img->mlx_img);
	free(data->ea_txtr.path);
	free(data->ea_txtr.img);
	mlx_destroy_image(data->mlx_ptr, data->we_txtr.img->mlx_img);
	free(data->we_txtr.path);
	free(data->we_txtr.img);
}

void	clear_data(t_data *data)
{
	if (data->map)
		ft_free_str_array(data->map);
	destroy_images(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
	exit(0);
}

int close_game(t_data *data)
{
	clear_data(data);
	return (0);
}
