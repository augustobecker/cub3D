/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:16:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/05 16:26:02 by gnuncio-         ###   ########.fr       */
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

typedef struct s_ray
{
	int		angle;
	int		num_ray;
	double	distance_to_wall;
	double	orientation;
}	t_ray;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
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
	double				angle;
	double				distance_to_wall;
	int					turn_direction;
	int					walk_direction;
	double				walk_speed;
	double				turn_speed;
	int					turn;
	int					move;
}	t_player;

typedef struct s_txtr
{
	char	*path;
	t_img	*img;
}	t_txtr;

typedef struct s_color
{
	int		*rbg;
}	t_color;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	t_player		player;
	t_img			*full_img;
	t_txtr			no_txtr;
	t_txtr			so_txtr;
	t_txtr			ea_txtr;
	t_txtr			we_txtr;
	t_color			ceiling;
	t_color			floor;
	int		fr;
	int		fg;
	int		fb;
	int		cr;
	int		cg;
	int		cb;
}	t_data;

typedef struct s_error_info
{
	t_error	type;
	int		code;
}	t_error_info;

#endif