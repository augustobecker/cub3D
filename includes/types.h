/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:16:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 05:50:27 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "error.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef enum s_vertical_dir
{
	NORTH,
	SOUTH
}	t_vertical_dir;

typedef enum s_horizontal_dir
{
	EAST,
	WEST
}	t_horizontal_dir;

typedef struct s_player
{
	double				x;
	double				y;
	double				width;
	double				height;
	double				rotation_angle;
	int					turn_direction;
	int					walk_direction;
	double				walk_speed;
	double				turn_speed;
	t_vertical_dir		vertical_dir;
	t_horizontal_dir	horizontal_dir;
}	t_player;

typedef struct s_txtr
{
	char	*path;
}	t_txtr;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				columns;
	int				rows;
	int				lines;
	t_img			img;
	t_player		player;
	t_img			floor;
	t_img			wall;
	t_txtr			no_txtr;
	t_txtr			so_txtr;
	t_txtr			ea_txtr;
	t_txtr			we_txtr;
}	t_data;

typedef struct s_error_info
{
	t_error	type;
	int		code;
}	t_error_info;

#endif