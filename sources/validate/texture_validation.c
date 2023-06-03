/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:08:04 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 20:32:00 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_any_texture_initial_char(char c)
{
	if ((c == 'N')
		|| (c == 'S')
		|| (c == 'E')
		|| (c == 'W')
		|| (c == 'F')
		|| (c == 'C')
		|| (c == 0))
		return (true);
	return (false);
}

static void	check_for_number_of_elements(char **content)
{
	int	i;
	int	elems;

	i = 0;
	elems = 0;
	while (content[i] && elems < NUM_OF_ELEM_BEFORE_MAP)
	{
		if (!is_any_texture_initial_char(content[i][0]))
		{
			ft_free_str_array(content);
			error_manager(ERROR_TEXTURE, INVALID_DEFINITION, 0);
		}
		else
			elems++;
		i++;
	}
	if (elems < NUM_OF_ELEM_BEFORE_MAP)
	{
		ft_free_str_array(content);
		error_manager(ERROR_TEXTURE, IS_MISSING_ELEM, 0);
	}
}

static void	check_for_texture_path(char **content, char *txtr)
{
	char	*txtr_path;
	int		error;

	error = FILE_NO_ERROR;
	txtr_path = get_texture_path(content, txtr);
	if (!txtr_path)
	{
		free(txtr_path);
		ft_free_str_array(content);
		error_manager(ERROR_MALLOC, MALLOC_ERROR, 0);
	}
	error = is_file_readable(txtr_path);
	if (error)
	{
		printf(GREY"cub3D: [%s] (Texture %sfile) is invalid\n"\
		RESET, txtr_path, txtr);
		free(txtr_path);
		ft_free_str_array(content);
		error_manager(ERROR_FILE, error, 0);
	}
	free(txtr_path);
}

void	texture_validation(char **file_content)
{
	check_for_number_of_elements(file_content);
	check_for_element(file_content, "NO ");
	check_for_element(file_content, "SO ");
	check_for_element(file_content, "EA ");
	check_for_element(file_content, "WE ");
	check_for_texture_path(file_content, "NO ");
	check_for_texture_path(file_content, "SO ");
	check_for_texture_path(file_content, "EA ");
	check_for_texture_path(file_content, "WE ");
}
