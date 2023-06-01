/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:08:04 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/01 23:20:36 by acesar-l         ###   ########.fr       */
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

void	check_for_number_of_elements(t_data *data, char **content)
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
			error_manager(ERROR_TEXTURE, INVALID_DEFINITION, data);
		}
		else
			elems++;
		i++;
	}
	if (elems < NUM_OF_ELEM_BEFORE_MAP)
	{
		ft_free_str_array(content);
		error_manager(ERROR_TEXTURE, IS_MISSING_ELEM, data);
	}
}

static char	*get_texture_path(char **content, char *txtr)
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

static void	check_for_texture_path(t_data *data, char **content, char *txtr)
{
	char	*txtr_path;
	int		error;

	error = FILE_NO_ERROR;
	txtr_path = get_texture_path(content, txtr);
	if (!txtr_path)
	{
		free(txtr_path);
		ft_free_str_array(content);
		error_manager(ERROR_MALLOC, MALLOC_ERROR, data);
	}
	error = is_file_readable(txtr_path);
	if (error)
	{
		printf(GREY"cub3D: [%s] (Texture %sfile) is invalid\n"\
		RESET, txtr_path, txtr);
		free(txtr_path);
		ft_free_str_array(content);
		error_manager(ERROR_FILE, error, data);
	}
	free(txtr_path);
}

void	texture_validation(t_data *data, char **file_content)
{
	check_for_number_of_elements(data, file_content);
	check_for_element(data, file_content, "NO ");
	check_for_element(data, file_content, "SO ");
	check_for_element(data, file_content, "EA ");
	check_for_element(data, file_content, "WE ");
	check_for_texture_path(data, file_content, "NO ");
	check_for_texture_path(data, file_content, "SO ");
	check_for_texture_path(data, file_content, "EA ");
	check_for_texture_path(data, file_content, "WE ");
}
