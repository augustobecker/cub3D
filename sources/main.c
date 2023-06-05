/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/05 18:14:34 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_player(t_data *data);

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**cubfile_content;

	arguments_validation(argc, argv);
	cubfile_content = cubfile_validation(argv[MAP_ARG]);
	data = setup_data(cubfile_content);
	setup_minilibx(data);
	setup_textures(data);
	print_player(data);
	render(data);
	mlx_loop(data->mlx_ptr);
	//TODO - colocar o hook para fechar janela!
	//TODO Colocar pra setar as novas inforamções na struct
	return (0);
}

void print_player(t_data *data)
{

	printf("VALORES DE PLAYER\n");
	printf("player.x = %f\n", data->player.x);
	printf("player.y = %f\n", data->player.y);
	printf("player.angle = %f\n", data->player.angle);
	printf("player.distance_to_wall = %f\n", data->player.distance_to_wall);
	printf("player.turn_direction = %d\n", data->player.turn_direction);
	printf("player.walk_direction = %d\n", data->player.walk_direction);
	printf("player.walk_speed = %f\n", data->player.walk_speed);
	printf("player.turn_speef = %f\n", data->player.turn_speed);
	printf("player.turn = %d\n", data->player.turn);
	printf("player.move = %d\n", data->player.move);
}