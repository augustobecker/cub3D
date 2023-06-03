/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:26:57 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 20:30:18 by acesar-l         ###   ########.fr       */
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

char	*get_texture_path(char **content, char *txtr)
{
	char	*txtr_path;
	int		compare;
	int		i;

	i = 0;
	txtr_path = NULL;
	while (content[i])
	{
		compare = 0;
		while ((content[i][compare]) && (content[i][compare] == txtr[compare]))
		{
			if (txtr[compare + 1] == '\0')
			{
				txtr_path = ft_strtrim(&content[i][compare], " '\"");
				break ;
			}
			compare++;
		}
		i++;
	}
	return (txtr_path);
}
