/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:26:57 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/02 22:20:48 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_for_element(char **content, char *elem)
{
	t_bool	found_elem;
	int		compare;
	int		i;

	i = 0;
	found_elem = false;
	while (content[i])
	{
		compare = 0;
		while ((content[i][compare]) && (content[i][compare] == elem[compare]))
		{
			if ((elem[compare + 1] == '\0') && (found_elem))
			{
				ft_free_str_array(content);
				error_manager(ERROR_TEXTURE, MULTIPLE_DEFINITION, 0);
			}
			if (elem[compare + 1] == '\0')
			{
				found_elem = true;
				break;
			}
			compare++;
		}
		i++;
	}
	if (!found_elem)
	{
		ft_free_str_array(content);
		error_manager(ERROR_TEXTURE, IS_MISSING_ELEM, 0);
	}
}
