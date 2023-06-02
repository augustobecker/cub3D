/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:26:57 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 00:59:56 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_for_element(char **content, char *elem)
{
	t_bool	found_elem;
	int		i;

	i = 0;
	found_elem = false;
	while (content[i])
	{
		if (!ft_strncmp(content[i], elem, ft_strlen(elem)))
		{
			if (found_elem)
			{
				ft_free_str_array(content);
				error_manager(ERROR_TEXTURE, MULTIPLE_DEFINITION, 0);
			}
			else
				found_elem = true;
		}
		i++;
	}
	if (!found_elem)
	{
		ft_free_str_array(content);
		error_manager(ERROR_TEXTURE, IS_MISSING_ELEM, 0);
	}
}
