/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:40:49 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/25 01:13:08 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_error_file	check_file(char *filename)
{
	if (!filename[0])
		return (FILE_DOESNT_EXIST);
	if (access(filename, F_OK))
		return (FILE_DOESNT_EXIST);
    if (access(filename, R_OK))
		return (FILE_MISS_PERMISSION);
	return (NO_ERROR);
}
