/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:19:38 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/06/17 05:47:58 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_data *data)
{
	data->full_img = new_image(data->mlx_ptr, \
	RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
	data->player.ray = 0;
	data->player.ray_ang = normalize_radian_angle(data->player.angle + PI / 6);
	while (data->player.ray < RESOLUTION_WIDTH)
	{
		data->player.ray_ang = normalize_radian_angle(data->player.ray_ang - (PI / 3) / RESOLUTION_WIDTH);
		ft_distance_wall(data);
		ft_drawn(data);
		data->player.ray++;
	}
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->full_img->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->full_img->mlx_img);
	free (data->full_img);
}
