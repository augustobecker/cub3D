/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubfile_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:20:15 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/05 13:46:42 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_any_texture_initial_char(char c);
static void	check_for_number_of_elements(char **content);
static void	check_for_element(char **content, char *elem);

void cubfile_validation(char **file_content)
{
	check_for_number_of_elements(file_content);
	check_for_element(file_content, "NO ");
	check_for_element(file_content, "SO ");
	check_for_element(file_content, "EA ");
	check_for_element(file_content, "WE ");
	check_for_element(file_content, "F ");
	check_for_element(file_content, "C ");
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
		printf("%s\n", content[i]);
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
	compare = 0;
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
