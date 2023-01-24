/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:11:03 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/24 20:24:34 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_arguments_nbr(int argc);
static void	check_file_extension(char *filename);

void	arguments_validation(int argc, char *const *argv)
{
	check_arguments_nbr(argc);
	check_file_extension(argv[MAP_ARG]);
}

static void	check_arguments_nbr(int argc)
{
	if (argc != ARGS_NBR)
		error_manager(INCORRET_ARGS_NBR);
}

static void	check_file_extension(char *filename)
{
	if (!filename[0])
		error_manager(INVALID_FILE_EXTENSION);
}