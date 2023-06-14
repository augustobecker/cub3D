/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:38:04 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/13 23:04:47 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			wall_height(t_ray *ray);
static void	set_txtr_to_put(t_data *data, t_player *plr, t_ray *ray, int px_y);

void	cast_ray(t_data *data, t_ray *ray)
{
	int	pixel_x;
	int	pixel_y;
	int	height;
	int	start_wall;

	pixel_x = ray->num_ray;
	pixel_y = 0;
	height = wall_height(ray);
	start_wall = floor((RESOLUTION_HEIGHT - height) / 2);
	//printf("START WALL:\t %d\n", start_wall);
	//printf("HEIGHT: \t%d\n", height);
	//printf("CEILING: \t %d until %d\n", start_wall, start_wall + height);
	while (pixel_y < RESOLUTION_HEIGHT)
	{
		if (pixel_y < start_wall)
			img_pix_put(data->full_img, pixel_x, pixel_y, RED_PIXEL);
		else if (pixel_y > start_wall + height)
			img_pix_put(data->full_img, pixel_x, pixel_y, WHITE_PIXEL);
		else
			img_pix_put(data->full_img, pixel_x, pixel_y, BLUE_PIXEL);
			//set_txtr_to_put(data, &data->player, ray, pixel_y);
		pixel_y++;
	}
}

int	wall_height(t_ray *ray)
{
	double	height;

	if (ray->distance_to_wall == 0)
		return (0);
	height = RESOLUTION_HEIGHT / tan (PI / 60) * TILE_SIZE / ray->distance_to_wall;
	//height = TILE_SIZE / ray->distance_to_wall * (RESOLUTION_WIDTH / (2 * tan (PI / 6)));
	return (ceil(height));
}

static void	set_txtr_to_put(t_data *data, t_player *plr, t_ray *ray, int px_y)
{
	t_img	*win;

	win = data->full_img;
	if ((ray->orientation == HORIZONTAL) && (ray->angle <= PI))
		img_pixel_put_txtr(win, data->no_txtr.img, plr, ray, px_y);
	else if (ray->orientation == HORIZONTAL)
		img_pixel_put_txtr(win, data->so_txtr.img, plr, ray, px_y);
	else if ((ray->orientation == VERTICAL) 
		&& (ray->angle >= PI / 2)
		&& (ray->angle <= 3 * PI / 2))
		img_pixel_put_txtr(win, data->we_txtr.img, plr, ray, px_y);
	else
		img_pixel_put_txtr(win, data->ea_txtr.img, plr, ray, px_y);
}
