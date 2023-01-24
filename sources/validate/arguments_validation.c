/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:11:03 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/24 21:36:08 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_arguments_nbr(int argc);
static void	check_file_exists(char *filename);
static void	check_file_extension(char *filename);
static void	check_file_permissions(char *filename);

void	arguments_validation(int argc, char *const *argv)
{
	check_arguments_nbr(argc);
	check_file_exists(argv[MAP_ARG]);
	check_file_permissions(argv[MAP_ARG]);
	check_file_extension(argv[MAP_ARG]);
}

static void	check_arguments_nbr(int argc)
{
	if (argc != ARGS_NBR)
		error_manager(INCORRET_ARGS_NBR);
}

static void	check_file_exists(char *filename)
{
	if (!filename[0])
		error_manager(FILE_DOESNT_EXIST);
	if (access(filename, F_OK))
		error_manager(FILE_DOESNT_EXIST);
}

static void	check_file_permissions(char *filename)
{
	if (access(filename, R_OK))
		error_manager(FILE_MISS_PERMISSION);
}

static void	check_file_extension(char *filename)
{
	size_t	filename_len;

	filename_len = ft_strlen(filename);
	if (filename_len < 4)
		error_manager(INVALID_FILE_EXTENSION);
	else if (!ft_strnstr(&filename[filename_len - 4], ".cub", 4))
		error_manager(INVALID_FILE_EXTENSION);
}