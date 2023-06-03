/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:53:50 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 21:16:20 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_data(t_data *data)
{
	if (data->map)
		ft_free_str_array(data->map);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->no_txtr.path)
		free(data->no_txtr.path);
	if (data->so_txtr.path)
		free(data->so_txtr.path);
	if (data->ea_txtr.path)
		free(data->ea_txtr.path);
	if (data->we_txtr.path)
		free(data->we_txtr.path);
	free(data);
}
