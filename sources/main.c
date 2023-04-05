/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/05 13:46:13 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main ( int argc, char **argv )
{
	t_data	*data;

	arguments_validation(argc, argv);
	data = create_data();
	get_cub_file_info(data, argv[MAP_ARG]);
	set_minilibx(data);
	clear_data(data);
	return (0);
}
