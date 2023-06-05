/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:19:38 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/06/05 18:14:08 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_data *data);
void	raycasting(t_data *data);

void	render(t_data *data)
{
	data->full_img = malloc(sizeof(t_img));
	data->full_img = new_image(data->mlx_ptr, \
	RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
	raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->full_img->mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->full_img->mlx_img);
	free(data->full_img);
}

void	raycasting(t_data *data)
{
	t_ray	*cur_ray;
	double	radian_diff_between_rays;

	cur_ray = malloc(sizeof(t_ray));
	cur_ray->num_ray = 0;
	cur_ray->angle = normalize_radian_angle(cur_ray->angle + PI / 6);
	radian_diff_between_rays = (PI / 3) / RESOLUTION_WIDTH;
	while (cur_ray->num_ray < RESOLUTION_WIDTH)
	{
		cur_ray->angle = \
		normalize_radian_angle(cur_ray->angle - radian_diff_between_rays);
		cur_ray->distance_to_wall = \
		get_player_distance_to_wall(data, &data->player, cur_ray);
		cast_ray(data, cur_ray);
		cur_ray->num_ray++;
	}
	free(cur_ray);
}

double	normalize_radian_angle(double angle)
{
	if (angle > 2 * PI)
		angle -= 2 * PI;
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}