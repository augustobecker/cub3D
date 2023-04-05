/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:14:37 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/05 13:47:09 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "stdio.h"
# include "stdlib.h"

# include "defines.h"
# include "types.h"

# include "libft.h"

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

#include <fcntl.h>

/**
 * @brief Validate the arguments that were entered on the command line.
 * 
 * @param argc How many arguments were entered on the command line.
 * @param argv The arguments that were entered on the command line.
 * 
 * @return Nothing. In case there's an error, the function handles it.
*/
void	arguments_validation(int argc, char *const *argv);

/**
 * @brief Prints an error message and exit the program.
 * 
 * @param error_type enum that defines the error.
 *
 * @return Nothing. It exits the program.
*/
void	error_manager(t_error error_type);

/**
 * @brief Allocate memory for a data type called t_data.
 *
 * @return The allocated memory, all set to NULL in case of pointer, and 0
 * in case of integers.
*/
t_data  *create_data(void);

/**
 * @brief Free all the memory allocated for a t_data pointer and its content.
 * 
 * @param data the data to be freed.
*/
void	clear_data(t_data *data);

/**
 * @brief Init MiniLibx Graphics Library, pointers, windowns and etc.
 * 
 * @param data struct data to store the minilix 
 * pointers returned from the init process.
*/
void    set_minilibx(t_data *data);

void get_cub_file_info(t_data *data, char const *cub_filename);

/**
 * @brief Validate the elements that were written on the cubfile passed.
 * 
 * @param file_content A matrix with the .cub content
 * 
 * @return Nothing. In case there's an error, the function handles it.
*/
void cubfile_validation(char **file_content);

#endif