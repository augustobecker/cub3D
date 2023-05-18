/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:53:50 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/18 08:51:33 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_string_array(char **free_me)
{
	char	**free_me_too;

	free_me_too = free_me;
	while (free_me && *free_me)
		free(*free_me++);
	free(free_me_too);
}

void clear_data(t_data *data)
{
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	else if (data->win_ptr)
		free(data->win_ptr);
	ft_free_string_array(data->map);
	free(data);
}
