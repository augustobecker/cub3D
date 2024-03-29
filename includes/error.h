/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:07:34 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/04 16:37:48 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_error
{
	NOT_AN_ERROR,
	ERROR_MALLOC,
	ERROR_FILE,
	ERROR_ARG,
	ERROR_MLX,
	ERROR_TEXTURE,
	ERROR_MAP,
	NOT_CONFIGURED_YET
}	t_error;

typedef enum e_error_arg
{
	ARGS_NO_ERROR,
	INCORRET_ARGS_NBR,
	INVALID_ARG_EXTENSION
}	t_error_arg;

typedef enum e_error_malloc
{
	MALLOC_NO_ERROR,
	MALLOC_ERROR
}	t_error_malloc;

typedef enum e_error_mlx
{
	MLX_NO_ERROR,
	INIT_ERROR,
	WINDOW_INIT_ERROR
}	t_error_mlx;

typedef enum e_error_texture
{
	TXTR_NO_ERROR,
	INVALID_DEFINITION,
	IS_MISSING_ELEM,
	MULTIPLE_DEFINITION,
	INVALID_COLOR,
	INVALID_FILE_CONTENT
}	t_error_texture;

typedef enum e_error_map
{
	MAP_NO_ERROR,
	INVALID_ELEMENT,
	MULTIPLE_START_POSITION,
	MISSING_START_POSITION,
	EMPTY_LINE,
	NOT_SURROUNDED_BY_WALLS
}	t_error_map;

typedef enum e_error_file
{
	FILE_NO_ERROR,
	FILE_DOESNT_EXIST,
	FILE_MISS_PERMISSION,
	FILE_FAILED_TO_OPEN
}	t_error_file;

#endif