/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:26:56 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/25 10:08:28 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_error_msg(char *error_msg);

static void message_error_arg(t_error_arg error_code);
static void message_error_malloc(t_error_malloc error_code);
static void message_error_file(t_error_file error_code);

static void message_error_texture(t_error_texture error_code);
static void message_error_map(t_error_map error_code);
static void message_error_mlx(t_error_mlx error_code);

void	error_manager(t_error error_type, int error_code, t_data *data)
{
	if (error_type == ERROR_ARG)
		message_error_arg(error_code);
	if (error_type == ERROR_MALLOC)
		message_error_malloc(error_code);
	if (error_type == ERROR_FILE)
		message_error_file(error_code);
	if (error_type == ERROR_MLX)
		message_error_mlx(error_code);
	if (error_type == ERROR_TEXTURE)
		message_error_texture(error_code);
	if (error_type == ERROR_MAP)
		message_error_map(error_code);
	if (data)
		free(data);
	exit(0);
}

static void	print_error_msg(char *error_msg)
{
	printf(GREY"cub3D: %s\n"RESET, error_msg);
}

static void message_error_arg(t_error_arg error_code)
{
	if (error_code == INCORRET_ARGS_NBR)
		print_error_msg("Incorret number of arguments.\n""usage:\n" \
		"\t./cub3D [a map in format *.cub]");
	if (error_code == INVALID_ARG_EXTENSION)
		print_error_msg("Invalid file extension.\n""usage:\n" \
		"\t./cub3D [a map in format *.cub]");
}

static void message_error_malloc(t_error_malloc error_code)
{
	if (error_code == MALLOC_ERROR)
		print_error_msg("Malloc error.");
}

static void message_error_file(t_error_file error_code)
{
	if (error_code == FILE_DOESNT_EXIST)
		print_error_msg("The map file doesn't exist.");
	if (error_code == FILE_MISS_PERMISSION)
		print_error_msg("The map file doesn't have read permission.");	
}

static void message_error_texture(t_error_texture error_code)
{
	if (error_code == INVALID_DEFINITION)
		print_error_msg("Texture invalid definition.\n" \
		"The valid texture elements are: SO, NO, EA, WE, F and C.\n" \
		"Only empty lines are accepted between the elements, keep an eye out.");
	if (error_code == IS_MISSING_ELEM)
		print_error_msg("Missing textures. \n" \
		"The valid texture elements are: SO, NO, EA, WE, F and C.");
	if (error_code == MULTIPLE_DEFINITION)
		print_error_msg("Texture multiple definition");
	if (error_code == INVALID_COLOUR)
		print_error_msg("The texture colour is invalid.\n" \
		"The valid colours follow this pattern: [0-255],[0-255],[0-255].\n" \
		"Here's an example: 125,12,125");
}

static void message_error_map(t_error_map error_code)
{
	if (error_code == INVALID_ELEMENT)
		print_error_msg("Map invalid parameter. \n" \
		"The valid parameters are 1, 0, N, S, E and W.");
	if (error_code == MULTIPLE_START_POSITION)
		print_error_msg("Multiple definition of player starting position on map. \n" \
		"The parameter for starting positions is N, S, E or W. It is defined only once");
	if (error_code == MISSING_START_POSITION)
		print_error_msg("Missing definition of player starting position on map. \n" \
		"The parameter for starting positions is N, S, E or W. It is defined only once");
} 

static void message_error_mlx(t_error_mlx error_code)
{
	if (error_code == INIT_ERROR)
		print_error_msg("Couldn't find mlx pointer. Try it using a VNC.");
	if (error_code == WINDOW_INIT_ERROR)
		print_error_msg("Couldn't create the Window.");
}
