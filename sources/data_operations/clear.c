/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:53:50 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/15 12:30:26 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_images(t_data *data)
{
	if (data->no_txtr.img)
		mlx_destroy_image(data->mlx_ptr, data->no_txtr.img->mlx_img);
	if (data->no_txtr.path)
		free(data->no_txtr.path);
	if (data->so_txtr.img)
		mlx_destroy_image(data->mlx_ptr, data->so_txtr.img->mlx_img);
	if (data->so_txtr.path)
		free(data->so_txtr.path);
	if (data->ea_txtr.img)
		mlx_destroy_image(data->mlx_ptr, data->ea_txtr.img->mlx_img);
	if (data->ea_txtr.path)
		free(data->ea_txtr.path);
	if (data->we_txtr.img)
		mlx_destroy_image(data->mlx_ptr, data->we_txtr.img->mlx_img);
	if (data->we_txtr.path)
		free(data->we_txtr.path);
}

void	clear_data(t_data *data)
{
	if (data->map)
		ft_free_str_array(data->map);
	free_images(data);
	free(data->no_txtr.img);
	free(data->so_txtr.img);
	free(data->ea_txtr.img);
	free(data->we_txtr.img);
	mlx_clear_window(data->mlx_ptr,data->win_ptr);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
}
