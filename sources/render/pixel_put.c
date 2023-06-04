/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:54:28 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/04 22:00:25 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_px_color(t_img *img, int x, int y);

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - BITS_PER_BYTE;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / BITS_PER_BYTE));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - BITS_PER_BYTE - i)) & 0xFF;
		i -= BITS_PER_BYTE;
	}
}

void	img_pixel_put_txtr(t_img *win, t_img *txtr, t_player *player, \
t_ray *ray, int px_y)
{
	int	offset_x;
	int	offset_y;
	int	height;
	int px_x;

	px_x = ray->num_ray;
	if (ray->orientation == HORIZONTAL)
		offset_x = (int) floor(player->x + ray->distance_to_wall * \
		cos(ray->angle)) % TILE_SIZE;
	else
		offset_x = (int) floor(player->y + ray->distance_to_wall * \
		sin(ray->angle)) % TILE_SIZE;
	offset_x = offset_x % txtr->bpp;
	height = wall_height(ray);
	if (height == 0)
		offset_y = 0;
	else
		offset_y = ((txtr->bpp) * (px_y - (RESOLUTION_HEIGHT - height) / 2)) / height;
	img_pix_put(win, px_x, px_y, get_px_color(txtr, offset_x, offset_y));	
}

static int	get_px_color(t_img *img, int x, int y)
{
	char	*byte;

	byte = img->addr + ((y * img->line_len)
			+ (x * img->bpp / BITS_PER_BYTE));
	return (*(unsigned int *)byte);
}
