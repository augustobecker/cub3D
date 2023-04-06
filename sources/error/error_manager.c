/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:26:56 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/06 14:44:54 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	error_message(t_error error);
static void	print_error_msg(char *error_msg);

void	error_manager(t_error error_type)
{
	error_message(error_type);
	exit(error_type);
}

static void	error_message(t_error error)
{
	if (error == NO_ERROR)
		print_error_msg("Bad usage: error_manager");
	else if (error == INCORRET_ARGS_NBR)
		print_error_msg("Incorret number of arguments.\n""usage:\n" \
		"\t./cub3D [a map in format *.cub]");
	else if (error == INVALID_FILE_EXTENSION)
		print_error_msg("Invalid file extension.\n""usage:\n" \
		"\t./cub3D [a map in format *.cub]");
	else if (error == FILE_DOESNT_EXIST)
		print_error_msg("The map file doesn't exist.");
	else if (error == FILE_MISS_PERMISSION)
		print_error_msg("The map file doesn't have read permission.");
	else if (error == MALLOC_ERROR)
		print_error_msg("Malloc error.");
	else if (error == MLX_INIT_ERROR)
		print_error_msg("Couldn't find mlx pointer. Try it using a VNC.");
	else if (error == MLX_WINDOW_INIT_ERROR)
		print_error_msg("Couldn't create the Window.");
	else if (error == TEXTURE_INVALID_DEFINITION)
		print_error_msg("Texture invalid definition.\n" \
		"The valid texture elements are: SO, NO, EA, WE, F and C.\n" \
		"Only empty lines are accepted between the elements, keep an eye out.");
	else if (error == TEXTURE_IS_MISSING_ELEM)
		print_error_msg("Missing textures. \n" \
		"The valid texture elements are: SO, NO, EA, WE, F and C.");
	else if (error == TEXTURE_MULTIPLE_DEFINITION)
		print_error_msg("Texture multiple definition");
	else if (error == TEXTURE_FILE_DOESNT_EXIST)
		print_error_msg("The texture file doesn't exist.");
	else if (error == TEXTURE_FILE_MISS_PERMISSION)
		print_error_msg("The texture file doesn't have read permission.");
	else if (error == NOT_CONFIGURED_YET)
		print_error_msg("This phase wasn`t been congifured yet");
}

static void	print_error_msg(char *error_msg)
{
	printf(GREY"cub3D: %s\n"RESET, error_msg);
}