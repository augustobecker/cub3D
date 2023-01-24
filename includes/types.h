/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:16:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/24 21:16:20 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_error
{
	NO_ERROR,
	INCORRET_ARGS_NBR,
	INVALID_FILE_EXTENSION,
	FILE_DOESNT_EXIST,
	FILE_MISS_PERMISSION,
	MALLOC_ERROR
}	t_error;

typedef struct s_data
{
	
}	t_data;

#endif