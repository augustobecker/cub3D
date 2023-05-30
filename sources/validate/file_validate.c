/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:40:49 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/22 15:31:04 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_error_file	is_file_readable(char *filename)
{
	if (!filename[0])
		return (FILE_DOESNT_EXIST);
	if (access(filename, F_OK))
		return (FILE_DOESNT_EXIST);
	if (access(filename, R_OK))
		return (FILE_MISS_PERMISSION);
	return (FILE_NO_ERROR);
}

void	print_message_file_is_invalid(char *filename, char *description)
{
	printf(GREY"cub3D: [%s] (%s) is invalid\n"RESET, filename, description);
}
