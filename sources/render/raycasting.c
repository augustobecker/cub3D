/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:19:38 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/06/16 22:15:31 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycast(t_data *data)
{
	data->full_img = malloc(sizeof(t_img));
	data->full_img->mlx_img = mlx_new_image(data->mlx_ptr, \
	RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
	data->full_img->addr = mlx_get_data_addr (data->full_img->mlx_img, \
	&data->full_img->bpp, &data->full_img->line_len, &data->full_img->endian);
	data->player.ray = 0;
	data->player.ray_ang = ft_radian_domain(data->player.angle + PI / 6);
	while (data->player.ray < RESOLUTION_WIDTH)
	{
		data->player.ray_ang = ft_radian_domain(data->player.ray_ang - (PI / 3) / RESOLUTION_WIDTH);
		ft_distance_wall(data);
		ft_drawn(data);
		data->player.ray++;
	}
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->full_img->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->full_img->mlx_img);
	free (data->full_img);
}
