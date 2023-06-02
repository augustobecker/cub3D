/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:17:08 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/02 22:42:12 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_error_texture	check_color(char *color_number)
{
	int	num;
	int	num_len;

	if (!color_number[0])
		return (INVALID_COLOR);
	num_len = ft_strlen(color_number);
	if (num_len > 3)
		return (INVALID_COLOR);
	num = ft_atoi(color_number);
	if (num == 0 && num_len != 1)
		return (INVALID_COLOR);
	if (num < 0 || num > 255)
		return (INVALID_COLOR);
	return (TXTR_NO_ERROR);
}

t_bool	are_there_three_colors(char *color)
{
	int	i;
	int	color_counter;

	i = 0;
	color_counter = 1;
	if (color[i] == ',')
		return (false);
	while(color[i])
	{
		if (!ft_isdigit(color[i]))
			return (false);
		while (ft_isdigit(color[i]))
			i++;
		if (color[i] == ',')
		{
			color_counter++;
			if (color_counter > 3)
				return (false);
			i++;
		}
	}
	return (true);
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

static void	check_for_texture_color(char **content, char txtr)
{
	char	*color;
	char	**rgb_colors;

	color = get_texture_color(content, txtr);
	if (!color)
	{
		free(color);
		ft_free_str_array(content);
		error_manager(ERROR_MALLOC, MALLOC_ERROR, 0);
	}
	if (ft_strlen(color) > MAX_RGB_LENGTH || ft_strlen(color) < MIN_RGB_LENGTH)
	{
		free(color);
		ft_free_str_array(content);
		error_manager(ERROR_TEXTURE, INVALID_COLOR, 0);
	}
	if (!are_there_three_colors(color))
	{
		free(color);
		ft_free_str_array(content);
		error_manager(ERROR_TEXTURE, INVALID_COLOR, 0);
	}
	rgb_colors = ft_split(color, ',');
	if (!rgb_colors)
	{
		free(color);
		ft_free_str_array(content);
		ft_free_str_array(rgb_colors);
		error_manager(ERROR_MALLOC, MALLOC_ERROR, 0);
	}
	if (check_color(rgb_colors[RED_RGB]))
	{
		free(color);
		ft_free_str_array(content);
		ft_free_str_array(rgb_colors);
		error_manager(ERROR_TEXTURE, INVALID_COLOR, 0);
	}
	if (check_color(rgb_colors[GREEN_RGB]))
	{
		free(color);
		ft_free_str_array(content);
		ft_free_str_array(rgb_colors);
		error_manager(ERROR_TEXTURE, INVALID_COLOR, 0);
	}
	if (check_color(rgb_colors[BLUE_RGB]))
	{
		free(color);
		ft_free_str_array(content);
		ft_free_str_array(rgb_colors);
		error_manager(ERROR_TEXTURE, INVALID_COLOR, 0);
	}
	ft_free_str_array(rgb_colors);
}

void	color_validation(char **file_content)
{
	check_for_element(file_content, "F ");
	check_for_element(file_content, "C ");
	check_for_texture_color(file_content, 'F');
	check_for_texture_color(file_content, 'C');
}
