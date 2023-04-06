/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:20:15 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/06 17:16:56 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_any_texture_initial_char(char c);
static void		check_for_number_of_elements(char **content);
static void		check_for_element(char **content, char *elem);
static void		check_for_texture_path(char **content, char *txtr);
static char		*get_texture_path(char **content, char *txtr);
static void		check_for_texture_colour(char **content, char txtr);
static char		*get_texture_colour(char **content, char txtr);

void cubfile_validation(char **file_content)
{
	check_for_number_of_elements(file_content);
	check_for_element(file_content, "NO ");
	check_for_element(file_content, "SO ");
	check_for_element(file_content, "EA ");
	check_for_element(file_content, "WE ");
	check_for_element(file_content, "F ");
	check_for_element(file_content, "C ");
	check_for_texture_path(file_content, "NO ");
	check_for_texture_path(file_content, "SO ");
	check_for_texture_path(file_content, "EA ");
	check_for_texture_path(file_content, "WE ");
	check_for_texture_colour(file_content, 'F');
	check_for_texture_colour(file_content, 'C');
}

static void check_for_number_of_elements(char **content)
{
	int i;
	int elems;

	i = 0;
	elems = 0;
	while (content[i] && elems < NUM_OF_ELEM_BEFORE_MAP)
	{
		if (!is_any_texture_initial_char(content[i][0]))
			error_manager(TEXTURE_INVALID_DEFINITION);
		else
			elems++;
		i++;
	}
	if (elems < NUM_OF_ELEM_BEFORE_MAP)
		error_manager(TEXTURE_IS_MISSING_ELEM);
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

static void	check_for_element(char **content, char *elem)
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
				error_manager(TEXTURE_MULTIPLE_DEFINITION);
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
		error_manager(TEXTURE_IS_MISSING_ELEM);
}

static void		check_for_texture_path(char **content, char *txtr)
{
	char *txtr_path;

	txtr_path = get_texture_path(content, txtr);
	if (!txtr_path)
		error_manager(MALLOC_ERROR);
	if (!txtr_path[0])
		error_manager(TEXTURE_FILE_DOESNT_EXIST);
	if (access(txtr_path, F_OK))
		error_manager(TEXTURE_FILE_DOESNT_EXIST);
	if (access(txtr_path, R_OK))
		error_manager(TEXTURE_FILE_MISS_PERMISSION);
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

static void check_colour(char *colour_number)
{
	int	num;
	int	num_len;

	if (!colour_number[0])
		error_manager(TEXTURE_COLOUR_INVALID);
	num_len = ft_strlen(colour_number);
	if (num_len > 3)
		error_manager(TEXTURE_COLOUR_INVALID);
	num = ft_atoi(colour_number);
	if (num == 0 && num_len != 1)
		error_manager(TEXTURE_COLOUR_INVALID);
	if (num < 0 || num > 255)
		error_manager(TEXTURE_COLOUR_INVALID);
}

static void	check_for_texture_colour(char **content, char txtr)
{
	char	*colour;
	char	**rgb_colours;

	colour = get_texture_colour(content, txtr);
	if (!colour)
		error_manager(MALLOC_ERROR);
	if (ft_strlen(colour) > MAX_RGB_LENGTH)
		error_manager(TEXTURE_COLOUR_INVALID);
	rgb_colours = ft_split(colour, ',');
	if (!rgb_colours)
		error_manager(MALLOC_ERROR);
	check_colour(rgb_colours[RED_RGB]);
	check_colour(rgb_colours[GREEN_RGB]);
	check_colour(rgb_colours[BLUE_RGB]);
}

static char	*get_texture_colour(char **content, char txtr)
{
	char	*colour;
	int		i;

	i = 0;
	colour = NULL;
	while (content[i])
	{
		while (!content[i][0])
			i++;
		if (content[i][0] == txtr && content[i][1] == ' ')
			colour = ft_strtrim(&content[i][1], " '\"[]()");
		i++;
	}
	return (colour);
}
