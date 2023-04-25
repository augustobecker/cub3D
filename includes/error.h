
#ifndef ERROR_H
# define ERROR_H

typedef enum e_error
{
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
    INCORRET_ARGS_NBR,
	INVALID_ARG_EXTENSION
}   t_error_arg;

typedef enum e_error_malloc
{
    MALLOC_ERROR
}   t_error_malloc;

typedef enum e_error_mlx
{
	INIT_ERROR,
	WINDOW_INIT_ERROR
}	t_error_mlx;

typedef enum e_error_texture
{
    INVALID_DEFINITION,
	IS_MISSING_ELEM,
	MULTIPLE_DEFINITION,
	INVALID_COLOUR
}   t_error_texture;

typedef enum e_error_map
{
	INVALID_ELEMENT,
    MULTIPLE_START_POSITION,
	MISSING_START_POSITION
}   t_error_map;

typedef enum e_error_file
{
    FILE_DOESNT_EXIST,
	FILE_MISS_PERMISSION,
	NOT_CONFIGURED_YET
}   t_error_file;

#endif