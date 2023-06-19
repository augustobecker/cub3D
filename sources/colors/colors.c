/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 01:43:11 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/06/19 12:12:52 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	set_color(char *line, int *r, int *g, int *b)
// {
// 	char	*tmp;
// 	char	**split;
// 	char	*clear;

// 	clear = ft_strtrim (line, " \n");
// 	tmp = ft_strchr (clear, ' ');
// 	split = ft_split (tmp, ',');
// 	*r = ft_atoi (split[0]);
// 	*g = ft_atoi (split[1]);
// 	*b = ft_atoi (split[2]);
// 	ft_free_str_array(split);
// 	free(clear);
// }

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

void	get_rgb(t_data *data, char **content, char txtr)
{
	char	*color;
	char	**rgb_colors;

	color = get_texture_color(content, txtr);
	rgb_colors = ft_split(color, ',');
	if (txtr == 'F')
	{
		data->floor.r = ft_atoi(rgb_colors[0]);
		data->floor.g = ft_atoi(rgb_colors[1]);
		data->floor.b = ft_atoi(rgb_colors[2]);
	}
	else
	{
		data->ceiling.r = ft_atoi(rgb_colors[0]);
		data->ceiling.g = ft_atoi(rgb_colors[1]);
		data->ceiling.b = ft_atoi(rgb_colors[2]);
	}
	free(color);
	ft_free_str_array(rgb_colors);
}

void	rgb_to_hex(t_data *data)
{
	data->floor.rbg = (data->floor.r << 16 | data->floor.g << 8
			| data->floor.b);
	data->ceiling.rbg = (data->ceiling.r << 16 | data->ceiling.g << 8
			| data->ceiling.b);
}

void	setup_colors(t_data *data, char **content)
{
	get_rgb(data, content, 'F');
	get_rgb(data, content, 'C');
	rgb_to_hex(data);
}
