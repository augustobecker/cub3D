/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:14:37 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/24 20:29:57 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "stdio.h"
# include "stdlib.h"

# include "defines.h"
# include "types.h"

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

#endif