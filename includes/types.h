/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:16:31 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/01 20:10:33 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

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
	double				rotation_angle;
	t_vertical_dir		vertical_dir;
	t_horizontal_dir	horizontal_dir;
}	t_player;


typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				columns;
	int				rows;
	t_img			img;
	t_player		player;
}	t_data;

#endif