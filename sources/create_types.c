/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:19:51 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/27 23:23:42 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*create_data(void)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		error_manager(MALLOC_ERROR);
	return (new);
}
