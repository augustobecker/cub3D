/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:17:08 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/26 23:31:28 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		        check_for_texture_color(t_data *data, char **content, char txtr);
static char		        *get_texture_color(char **content, char txtr);
static t_error_texture	check_color(char *color_number);

void color_validation(t_data *data, char **file_content)
{
	check_for_element(data, file_content, "F ");
	check_for_element(data, file_content, "C ");
	check_for_texture_color(data, file_content, 'F');
	check_for_texture_color(data, file_content, 'C');
}

static t_error_texture check_color(char *color_number)
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
