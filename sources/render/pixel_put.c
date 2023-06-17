/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:54:28 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/17 04:15:40 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_drawn(t_data *data);
void			ft_choice_wall(t_data *data, int i);
void			ft_drawn_wall(t_data *data, t_img *image, int i);
int				ft_mlx_pixel_get(t_img *txtr, int x, int y);
void			ft_mlx_pixel_put(t_img *txtr, int x, int y, int color);
int				ft_size_wall(t_data *data);

void	ft_drawn(t_data *data)
{
	int	i;
	int	size;
	int	start_wall;

	size = ft_size_wall (data);
	start_wall = floor ((RESOLUTION_HEIGHT - size) / 2);
	i = 0;
	while (i < RESOLUTION_HEIGHT)
	{
		if (i < start_wall)
			ft_mlx_pixel_put(data->full_img, data->player.ray, i,
				BLUE_PIXEL);
		else if (i > start_wall + size)
			ft_mlx_pixel_put (data->full_img, data->player.ray, i,
				WHITE_PIXEL);
		else
			ft_choice_wall (data, i);
		i++;
	}
}

void	ft_choice_wall(t_data *data, int i)
{
	if (data->player.ray_ang > PI && data->player.status == HORIZONTAL)
		ft_drawn_wall (data, data->so_txtr.img, i);
	else if (data->player.ray_ang < PI && data->player.status == HORIZONTAL)
		ft_drawn_wall (data, data->no_txtr.img, i);
	else if (data->player.ray_ang > PI / 2 && data->player.ray_ang < 3 * PI / 2)
		ft_drawn_wall (data, data->we_txtr.img, i);
	else
		ft_drawn_wall (data, data->ea_txtr.img, i);
}

void	ft_drawn_wall(t_data *data, t_img *image, int i)
{
	int	offset_x;
	int	offset_y;
	int	size;

	if (data->player.status == HORIZONTAL)
		offset_x = (int)floor (data->player.x + data->player.distance_to_wall
				* cos(data->player.ray_ang)) % TILE_SIZE;
	else
		offset_x = (int) floor(data->player.y - data->player.distance_to_wall
				* sin(data->player.ray_ang)) % TILE_SIZE;
	offset_x = offset_x % image->bpp;
	size = ft_size_wall(data);
	if (size == 0)
		offset_y = 0;
	else
		offset_y = ((image->bpp) * (i - (RESOLUTION_HEIGHT - size) / 2))
			/size;
	ft_mlx_pixel_put(data->full_img, data->player.ray, i, ft_mlx_pixel_get(image,
			offset_x, offset_y));
}

int	ft_mlx_pixel_get(t_img *txtr, int x, int y)
{
	char	*byte;

	byte = txtr->addr + ((y * txtr->line_len)
			+ (x * txtr->bpp / 8));
	return (*(unsigned int *)byte);
}

void	ft_mlx_pixel_put(t_img *txtr, int x, int y, int color)
{
	char	*tmp;

	tmp = txtr->addr + (y * txtr->line_len + x * (txtr->bpp / 8));
	*(unsigned int *) tmp = color;
}

int	ft_size_wall(t_data *data)
{
	double	tmp;

	if (data->player.distance_to_wall == 0)
		return (0);
	tmp = TILE_SIZE / data->player.distance_to_wall * (RESOLUTION_WIDTH / (2 * tan (PI / 6)));
	return (ceil(tmp));
}