/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/25 13:32:05 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main ( int argc, char **argv )
{
	t_data		*data;
	argc = (int) argc;
	argv = (char **) argv;

	//arguments_validation(argc, argv);
	data = create_data();
	map_init(argv[1], data);
	printf("MAP:\n%s", data->map);

	//get_cub_file_info(data, argv[MAP_ARG]);

	//set_minilibx(data);
	clear_data(data);
	return (0);
}
