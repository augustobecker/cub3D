/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:17:04 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/26 04:19:49 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307

# define EXEC_ARG                   0
# define MAP_ARG                   	1
# define ARGS_NBR                   2

# define WIN_WIDTH                  800
# define WIN_HEIGHT                 400

# define NUM_OF_ELEM_BEFORE_MAP     6

# define MAX_RGB_LENGTH             11

# define RED_RGB                    0
# define GREEN_RGB                  1
# define BLUE_RGB                   2

# define TILE_SIZE                  32

# define PI                         3.14

# define FOV_ANGLE                  60 * (PI / 180)

# define WALL_STRIP_WIDTH           1

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