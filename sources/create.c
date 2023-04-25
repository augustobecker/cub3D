/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:19:51 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/25 13:31:00 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*create_data(void)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new){
		printf("create data error\n");
		//error_manager(ERROR_MALLOC, MALLOC_ERROR, 0);
	}
	new->mlx_ptr = NULL;
	new->win_ptr = NULL;
	

	return (new);
}
