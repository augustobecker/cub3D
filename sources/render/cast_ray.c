/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:38:04 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/19 23:25:17 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		cast_ray(t_data *data, t_ray *ray);
static void	set_txtr_to_put(t_data *data, t_ray *ray, int px_y);
static void	img_pixel_put_txtr(t_data *data, t_img *txtr, t_ray *ray, \
int px_y);
static int	get_px_color(t_img *img, int x, int y);
static int	wall_height(t_ray *ray);

void	cast_ray(t_data *data, t_ray *ray)
{
	int	pixel_x;
	int	pixel_y;
	int	height;
	int	start_wall;

	pixel_y = 0;
	pixel_x = ray->num_ray;
	height = wall_height(ray);
	start_wall = floor((RESOLUTION_HEIGHT - height) / 2);
	while (pixel_y < RESOLUTION_HEIGHT)
	{
		if (pixel_y < start_wall)
			img_pix_put(data->full_img, pixel_x, pixel_y, data->ceiling.rbg);
		else if (pixel_y > start_wall + height)
			img_pix_put(data->full_img, pixel_x, pixel_y, data->floor.rbg);
		else
			set_txtr_to_put(data, ray, pixel_y);
		pixel_y++;
	}
}

int	wall_height(t_ray *ray)
{
	double	height;

	if (ray->distance_to_wall == 0)
		return (0);
	height = TILE_SIZE / ray->distance_to_wall * \
	(RESOLUTION_WIDTH / (2 * tan(PI / 6)));
	return (ceil(height));
}

static void	set_txtr_to_put(t_data *data, t_ray *ray, int px_y)
{
	if ((ray->orientation == HORIZONTAL) && (sin(ray->angle) > 0))
		img_pixel_put_txtr(data, data->no_txtr.img, ray, px_y);
	else if (ray->orientation == HORIZONTAL)
		img_pixel_put_txtr(data, data->so_txtr.img, ray, px_y);
	else if ((ray->orientation == VERTICAL)
		&& (cos(ray->angle) > 0))
		img_pixel_put_txtr(data, data->we_txtr.img, ray, px_y);
	else
		img_pixel_put_txtr(data, data->ea_txtr.img, ray, px_y);
}

void	img_pixel_put_txtr(t_data *data, t_img *txtr, t_ray *ray, int px_y)
{
	int	offset_x;
	int	offset_y;
	int	height;
	int	px_x;

	px_x = ray->num_ray;
	if (ray->orientation == HORIZONTAL)
		offset_x = (int) floor(data->player.x + ray->distance_to_wall * \
		cos(ray->angle)) % TILE_SIZE;
	else
		offset_x = (int) floor(data->player.y - ray->distance_to_wall * \
		sin(ray->angle)) % TILE_SIZE;
	offset_x = offset_x % txtr->bpp;
	height = wall_height(ray);
	if (height == 0)
		offset_y = 0;
	else
		offset_y = ((txtr->bpp) * \
		(px_y - (RESOLUTION_HEIGHT - height) / 2)) / height;
	img_pix_put(data->full_img, px_x, px_y, \
	get_px_color(txtr, offset_x, offset_y));
}

static int	get_px_color(t_img *img, int x, int y)
{
	char	*byte;

	byte = img->addr + ((y * img->line_len) + (x * img->bpp / BITS_PER_BYTE));
	return (*(unsigned int *)byte);
}
