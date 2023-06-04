/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:34:55 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/04 22:16:00 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*new_texture(void *mlx, char *path, t_data *data);

void	setup_textures(t_data *data)
{
	data->no_txtr.img = new_texture(data->mlx_ptr, data->no_txtr.path, data);
	data->so_txtr.img = new_texture(data->mlx_ptr, data->so_txtr.path, data);
	data->ea_txtr.img = new_texture(data->mlx_ptr, data->ea_txtr.path, data);
	data->we_txtr.img = new_texture(data->mlx_ptr, data->we_txtr.path, data);
}

t_img	*new_image(void *mlx_ptr, int width, int height)
{
	t_img	*img;
	
	img = malloc(sizeof(t_img));
	img->mlx_img = mlx_new_image(mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->mlx_img, \
	&img->bpp, &img->line_len, &img->endian);
	return (img);
}

static t_img	*new_texture(void *mlx, char *path, t_data *data)
{
	t_img	*texure;

	texure = malloc(sizeof(t_img));
	texure->mlx_img = \
	mlx_xpm_file_to_image(mlx, path, &texure->width, &texure->height);
	if (!texure->mlx_img)
	{
		free(texure);
		error_manager(ERROR_TEXTURE, INVALID_FILE_CONTENT, data);
	}
	texure->addr = mlx_get_data_addr(texure->mlx_img, &texure->bpp, \
	&texure->line_len, &texure->endian);
	return (texure);
}
