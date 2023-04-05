/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:16:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/05 13:36:04 by acesar-l         ###   ########.fr       */
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
	MALLOC_ERROR,
	MLX_INIT_ERROR,
	MLX_WINDOW_INIT_ERROR,
	TEXTURE_INVALID_DEFINITION,
	TEXTURE_IS_MISSING_ELEM,
	TEXTURE_MULTIPLE_DEFINITION,
	NOT_CONFIGURED_YET
}	t_error;

typedef enum e_elem
{
	NO,
	SO,
	EA,
	WE,
	F,
	C
}	t_elem;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
}	t_data;

#endif