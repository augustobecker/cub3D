/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:53:50 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/01 20:09:23 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void clear_data(t_data *data)
{
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	else if (data->win_ptr)
		free(data->win_ptr);
	ft_free_ptr(data->map);
	free(data);
}
