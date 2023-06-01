/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:20:15 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/01 23:11:22 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cubfile_validation(t_data *data, char *cubfile_name)
{
	char		*cubfile_content;
	char		**content_matrix;
	
	cubfile_content = read_file(cubfile_name);
	if (!cubfile_content[0])
	{
		free(cubfile_content);
		error_manager(ERROR_TEXTURE, IS_MISSING_ELEM, data);
	}
	//check_map_for_empty_line(data, cubfile_content);
	content_matrix = ft_split(cubfile_content, '\n');
	free(cubfile_content);
	texture_validation(data, content_matrix);
	color_validation(data, content_matrix);
	//map_validation(data, content_matrix);
}
