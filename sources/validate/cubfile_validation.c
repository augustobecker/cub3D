/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:20:15 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/26 04:10:20 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_any_texture_initial_char(char c);
void			check_for_number_of_elements(t_data *data, char **content);
static void		check_for_element(t_data *data, char **content, char *elem);
static void		check_for_texture_path(t_data *data, char **content, char *txtr);
static char		*get_texture_path(char **content, char *txtr);
static void		check_for_texture_color(t_data *data, char **content, char txtr);
static char		*get_texture_color(char **content, char txtr);
t_error_texture	check_color(char *color_number);

void texture_validation(t_data *data, char **file_content)
{
	check_for_number_of_elements(data, file_content);
	check_for_element(data, file_content, "NO ");
	check_for_element(data, file_content, "SO ");
	check_for_element(data, file_content, "EA ");
	check_for_element(data, file_content, "WE ");
	check_for_element(data, file_content, "F ");
	check_for_element(data, file_content, "C ");
	check_for_texture_path(data, file_content, "NO ");
	check_for_texture_path(data, file_content, "SO ");
	check_for_texture_path(data, file_content, "EA ");
	check_for_texture_path(data, file_content, "WE ");
	check_for_texture_color(data, file_content, 'F');
	check_for_texture_color(data, file_content, 'C');
	//map_validation(data, file_content);
}

void check_for_number_of_elements(t_data *data, char **content)
{
	int i;
	int elems;

	i = 0;
	elems = 0;
	while (content[i] && elems < NUM_OF_ELEM_BEFORE_MAP)
	{
		if (!is_any_texture_initial_char(content[i][0]))
		{
			ft_matrix_free(content, data->lines);
			error_manager(ERROR_TEXTURE, INVALID_DEFINITION, data);
		}
		else
			elems++;
		i++;
	}
	if (elems < NUM_OF_ELEM_BEFORE_MAP)
	{
		ft_matrix_free(content, data->lines);
		error_manager(ERROR_TEXTURE, IS_MISSING_ELEM, data);
	}
}

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

static void	check_for_element(t_data *data, char **content, char *elem)
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
				ft_matrix_free(content, data->lines);
				error_manager(ERROR_TEXTURE, MULTIPLE_DEFINITION, data);
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
		ft_matrix_free(content, data->lines);
		error_manager(ERROR_TEXTURE, IS_MISSING_ELEM, data);
	}
}

static void		check_for_texture_path(t_data *data, char **content, char *txtr)
{
	char			*txtr_path;
	int				error;

	error = FILE_NO_ERROR;
	txtr_path = get_texture_path(content, txtr);
	if (!txtr_path)
	{
		free(txtr_path);
		ft_matrix_free(content, data->lines);
		error_manager(ERROR_MALLOC, MALLOC_ERROR, data);
	}
	error = is_file_readable(txtr_path);
	if (error)
	{
		printf(GREY"cub3D: [%s] (Texture %sfile) is invalid\n"RESET, txtr_path, txtr);
		ft_matrix_free(content, data->lines);
		free(txtr_path);
		error_manager(ERROR_FILE, error, data);
	}
	free(txtr_path);
}

static char *get_texture_path(char **content, char *txtr)
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
				break;
			}
			compare++;
		}
		i++;
	}
	return (txtr_path);
}

t_error_texture check_color(char *color_number)
{
	int	num;
	int	num_len;

	if (!color_number[0])
		return (INVALID_COLOR);
	num_len = ft_strlen(color_number);
	if (num_len != 3)
		return (INVALID_COLOR);
	num = ft_atoi(color_number);
	if (num == 0 && num_len != 1)
		return (INVALID_COLOR);
	if (num < 0 || num > 255)
		return (INVALID_COLOR);
	return (TXTR_NO_ERROR);
}

static void	check_for_texture_color(t_data *data, char **content, char txtr)
{
	char	*color;
	char	**rgb_colors;

	color = get_texture_color(content, txtr);
	if (!color)
	{
		free(color);
		ft_matrix_free(content, data->lines);
		error_manager(ERROR_MALLOC, MALLOC_ERROR, data);
	}
	if (ft_strlen(color) > MAX_RGB_LENGTH)
	{
		free(color);
		ft_matrix_free(content, data->lines);
		error_manager(ERROR_TEXTURE, INVALID_COLOR, data);
	}
	if (ft_count_occurrences(color, ',') != 3)
	{
		free(color);
		ft_matrix_free(content, data->lines);
		error_manager(ERROR_TEXTURE, INVALID_COLOR, data);
	}
	rgb_colors = ft_split(color, ',');
	if (!rgb_colors)
	{
		free(color);
		ft_matrix_free(content, data->lines);
		ft_matrix_free(rgb_colors, 2);
		error_manager(ERROR_MALLOC, MALLOC_ERROR, data);
	}
	if (!check_color(rgb_colors[RED_RGB]))
	{
		free(color);
		ft_matrix_free(content, data->lines);
		ft_matrix_free(rgb_colors, 2);
		error_manager(ERROR_TEXTURE, INVALID_COLOR, data);
	}
	if (!check_color(rgb_colors[GREEN_RGB]))
	{
		free(color);
		ft_matrix_free(content, data->lines);
		ft_matrix_free(rgb_colors, 2);
		error_manager(ERROR_TEXTURE, INVALID_COLOR, data);
	}
	if (!check_color(rgb_colors[BLUE_RGB]))
	{
		free(color);
		ft_matrix_free(content, data->lines);
		ft_matrix_free(rgb_colors, 2);
		error_manager(ERROR_TEXTURE, INVALID_COLOR, data);
	}
}

static char	*get_texture_color(char **content, char txtr)
{
	char	*color;
	int		i;

	i = 0;
	color = NULL;
	while (content[i])
	{
		while (!content[i][0])
			i++;
		if (content[i][0] == txtr && content[i][1] == ' ')
			color = ft_strtrim(&content[i][1], " '\"[]()");
		i++;
	}
	return (color);
}
