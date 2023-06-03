/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:53:50 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 21:47:12 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_images(t_data *data)
{
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	/*
	if (data->no_txtr)
		mlx_destroy_image(data->mlx_ptr, data->no_txtr.img.mlx_img);
	if (data->so_txtr)
		mlx_destroy_image(data->mlx_ptr, data->so_txtr.img.mlx_img);
	if (data->ea_txtr)
		mlx_destroy_image(data->mlx_ptr, data->ea_txtr.img.mlx_img);
	if (data->we_txtr)
		mlx_destroy_image(data->mlx_ptr, data->we_txtr.img.mlx_img);
	*/
}

void	clear_data(t_data *data)
{
	if (data->map)
		ft_free_str_array(data->map);
	free_images(data);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->no_txtr.path)
		free(data->no_txtr.path);
	if (data->so_txtr.path)
		free(data->so_txtr.path);
	if (data->ea_txtr.path)
		free(data->ea_txtr.path);
	if (data->we_txtr.path)
		free(data->we_txtr.path);
	free(data);
}
