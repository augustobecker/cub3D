/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:19:51 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 21:55:03 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*create_data(void)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		error_manager(ERROR_MALLOC, MALLOC_ERROR, 0);
	new->mlx_ptr = NULL;
	new->win_ptr = NULL;
	new->no_txtr.img.mlx_img = NULL;
	new->so_txtr.img.mlx_img = NULL;
	new->ea_txtr.img.mlx_img = NULL;
	new->we_txtr.img.mlx_img = NULL;
	return (new);
}
