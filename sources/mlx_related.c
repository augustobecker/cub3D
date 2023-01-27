/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_related.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:25:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/27 23:35:16 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
    {
        free(data);
		error_manager(MLX_INIT_ERROR);
    }
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
        free(data);
		error_manager(MLX_WINDOW_INIT_ERROR);
	}
}
