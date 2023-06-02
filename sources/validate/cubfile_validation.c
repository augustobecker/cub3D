/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:20:15 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/02 22:41:55 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**cubfile_validation(char *cubfile_name)
{
	char		*cubfile_content;
	char		**content_matrix;

	cubfile_content = read_file(cubfile_name);
	if (!cubfile_content[0])
	{
		free(cubfile_content);
		error_manager(ERROR_TEXTURE, IS_MISSING_ELEM, 0);
	}
	//check_map_for_empty_line(cubfile_content);
	content_matrix = ft_split(cubfile_content, '\n');
	free(cubfile_content);
	texture_validation(content_matrix);
	color_validation(content_matrix);
	//map_validation(content_matrix);
	return (content_matrix);
}
