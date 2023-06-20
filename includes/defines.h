/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:17:04 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/20 05:36:36 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define NO_ERROR					0

# define RESOLUTION_WIDTH			640
# define RESOLUTION_HEIGHT			400

# define HORIZONTAL					1
# define VERTICAL					2

# define WHITE_PIXEL        		0xFFFFFF
# define BLUE_PIXEL         		0x0000FF
# define RED_PIXEL          		0xFF0000
# define BLACK_PIXEL        		0x000000

# define FLOOR_COLOR				0x0B2631
# define WALL_COLOR					0x2DAADE

# define ROTATION_SPEED				0.03745
# define WALK_SPEED					8

# define NORTH_DIR					-1
# define SOUTH_DIR					1
# define EAST_DIR					1
# define WEST_DIR					-1

# define KEY_W						119
# define KEY_A						97
# define KEY_S						115
# define KEY_D						100

# define KEY_LEFT  					65361
# define KEY_RIGHT 					65363

# define KEY_Q						113
# define KEY_ESC  					65307

# define STOP						0

# define EXEC_ARG                   0
# define MAP_ARG                   	1
# define ARGS_NBR                   2

# define WIN_WIDTH                  800
# define WIN_HEIGHT                 400

# define NUM_OF_ELEM_BEFORE_MAP     6

# define MIN_RGB_LENGTH             5
# define MAX_RGB_LENGTH             11

# define RED_RGB                    0
# define GREEN_RGB                  1
# define BLUE_RGB                   2

# define TILE_SIZE                  32

# define MINI_TILE_SIZE				32

# define BITS_PER_BYTE				8

# define PI                         3.14159265358979323846

# define FOV_ANGLE                  1.04719755119659774614

# define WALL_STRIP_WIDTH           1

# define MAX						32767

# define UP							1
# define DOWN						2
# define LEFT						3
# define RIGHT						4

# define WALL						'1'
# define EMPTY_SPACE				' '
# define FLOOR						'0'

# define BLACK				        "\033[0;30m"
# define RED				        "\033[0;31m"
# define GREEN				        "\033[0;32m"
# define YELLOW				        "\033[0;33m"
# define BLUE			    	    "\033[0;34m"
# define PURPLE				        "\033[0;35m"
# define CYAN				        "\033[0;36m"
# define WHITE				        "\033[0;37m"
# define GREY				        "\033[0;90m"
# define RESET				        "\033[0m"

#endif