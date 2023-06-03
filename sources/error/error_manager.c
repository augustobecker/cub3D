/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:26:56 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 20:19:09 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	message_error_arg(t_error_arg error_code);
void	message_error_malloc(t_error_malloc error_code);
void	message_error_file(t_error_file error_code);

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
		clear_data(data);
	exit(0);
}

void	message_error_arg(t_error_arg error_code)
{
	if (error_code == INCORRET_ARGS_NBR)
		print_error_msg("Incorret number of arguments.\n""usage:\n" \
		"\t./cub3D [a map in format *.cub]");
	if (error_code == INVALID_ARG_EXTENSION)
		print_error_msg("Invalid file extension.\n""usage:\n" \
		"\t./cub3D [a map in format *.cub]");
}

void	message_error_malloc(t_error_malloc error_code)
{
	if (error_code == MALLOC_ERROR)
		print_error_msg("Malloc error.");
}

void	message_error_file(t_error_file error_code)
{
	if (error_code == FILE_DOESNT_EXIST)
		print_error_msg("The file doesn't exist.");
	if (error_code == FILE_MISS_PERMISSION)
		print_error_msg("The file doesn't have read permission.");
	if (error_code == FILE_FAILED_TO_OPEN)
		print_error_msg("The file failed to open.");
}
