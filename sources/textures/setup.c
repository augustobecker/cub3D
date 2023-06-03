/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:34:55 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 21:18:24 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	new_texture(void *mlx, char *path, t_data *data);

void	setup_textures(t_data *data)
{
	data->no_txtr.img = new_texture(data->mlx_ptr, data->no_txtr.path, data);
	data->so_txtr.img = new_texture(data->mlx_ptr, data->so_txtr.path, data);
	data->ea_txtr.img = new_texture(data->mlx_ptr, data->ea_txtr.path, data);
	data->we_txtr.img = new_texture(data->mlx_ptr, data->we_txtr.path, data);
}

t_img	new_texture(void *mlx, char *path, t_data *data)
{
	t_img	texure;

	texure.mlx_img = \
	mlx_xpm_file_to_image(mlx, path, &texure.width, &texure.height);
	if (texure.mlx_img == NULL)
		error_manager(ERROR_TEXTURE, INVALID_FILE_CONTENT, data);
	return (texure);
}
