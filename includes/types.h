/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:16:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/20 03:06:15 by acesar-l         ###   ########.fr       */
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
	double	angle;
	int		num_ray;
	double	distance_to_wall;
	int		orientation;
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

typedef struct s_player
{
	double				x;
	double				y;
	double				angle;
	double				walk_speed;
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
	int		rbg;
	int		r;
	int		g;
	int		b;
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
}	t_data;

typedef struct s_error_info
{
	t_error	type;
	int		code;
}	t_error_info;

typedef struct s_player_collision_rule
{
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;
}	t_player_collision_rule;

#endif