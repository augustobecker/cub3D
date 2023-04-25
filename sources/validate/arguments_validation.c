/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:11:03 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/25 10:00:43 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_arguments_nbr(int argc);
static void	check_arg_extension(char *filename);

void	arguments_validation(int argc, char *const *argv)
{
	int error;

	error = NO_ERROR;
	check_arguments_nbr(argc);
	error = is_file_readable(arg[MAP_ARG])
	if (error)
	{
		print_message_file_is_invalid("The map file");
		error_manager(ERROR_FILE, error, 0);
	}
	check_arg_extension(argv[MAP_ARG]);
}

static void	check_arguments_nbr(int argc)
{
	if (argc != ARGS_NBR)
		error_manager(ERROR_ARG, INCORRET_ARGS_NBR, 0);
}

static void	check_arg_extension(char *file_arg)
{
	size_t	filename_len;

	filename_len = ft_strlen(file_arg);
	if (filename_len < 4)
		error_manager(ERROR_ARG, INVALID_ARG_EXTENSION, 0);
	else if (!ft_strnstr(&file_arg[filename_len - 4], ".cub", 4))
		error_manager(ERROR_ARG, INVALID_ARG_EXTENSION, 0);
}