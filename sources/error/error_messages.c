/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:17:29 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 06:29:53 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error_msg(char *error_msg);
void	message_error_texture(t_error_texture error_code);
void	message_error_map(t_error_map error_code);
void	message_error_mlx(t_error_mlx error_code);

void	print_error_msg(char *error_msg)
{
	printf(GREY"cub3D: %s\n"RESET, error_msg);
}

void	message_error_texture(t_error_texture error_code)
{
	if (error_code == INVALID_DEFINITION)
		print_error_msg("Texture invalid definition.\n" \
		"The valid texture elements are: SO, NO, EA, WE, F and C.\n" \
		"Only empty lines are accepted between the elements.");
	if (error_code == IS_MISSING_ELEM)
		print_error_msg("Missing textures. \n" \
		"The valid texture elements are: SO, NO, EA, WE, F and C.");
	if (error_code == MULTIPLE_DEFINITION)
		print_error_msg("Texture multiple definition");
	if (error_code == INVALID_COLOR)
		print_error_msg("The texture color is invalid.\n" \
		"The valid colours follow this pattern: [0-255],[0-255],[0-255].\n" \
		"Here's an example: 125,12,125");
}

void	message_error_map(t_error_map error_code)
{
	if (error_code == INVALID_ELEMENT)
		print_error_msg("Map invalid parameter. \n" \
		"The valid parameters are 1, 0, N, S, E and W.");
	if (error_code == MULTIPLE_START_POSITION)
		print_error_msg("Multiple definition of player starting " \
		"position on map. \n" \
		"The parameter for starting positions is N, S, E or W. " \
		"It is defined only once");
	if (error_code == MISSING_START_POSITION)
		print_error_msg("Missing definition of player starting " \
		"position on map. \n" \
		"The parameter for starting positions is N, S, E or W. " \
		"It is defined only once");
	if (error_code == EMPTY_LINE)
		print_error_msg("Invalid Map. There is a blank line in the " \
		"middle of the content.");
}

void	message_error_mlx(t_error_mlx error_code)
{
	if (error_code == INIT_ERROR)
		print_error_msg("Couldn't find mlx pointer. Try it using a VNC.");
	if (error_code == WINDOW_INIT_ERROR)
		print_error_msg("Couldn't create the Window.");
}
