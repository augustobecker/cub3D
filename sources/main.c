/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/13 21:17:00 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int keysym, t_data *data)
{
	if (keysym == KEY_Q || keysym == KEY_ESC)
		clear_data(data);
	// if (keysym == KEY_W)
	// 	render(data);
	// if (keysym == KEY_D)
	// 	render(data);
	// if (keysym == KEY_A)
	// 	render(data);
	// if (keysym == KEY_S)
	// 	render(data);
	return (0);
}

int close_game(t_data *data)
{
	clear_data(data);
	return (0);
}

int	update_player(t_data *data)
{
	printf("trying to render\n");
	print_player(data, "update player hook");
	render(data);
	return (0);
}

void print_ray(t_ray *ray)
{
	printf("RAY %d INFO\n", ray->num_ray);
	printf("\tangle: %f\n", ray->angle);
	printf("\tangle: %f\n", ray->angle * 180/PI);
	printf("\tdistance to wall: %f\n", ray->distance_to_wall);
	printf("\torientation: ");
	if (ray->orientation == VERTICAL)
		printf("VERTICAL\n");
	else
		printf("HORIZONTAL\n");
	printf("************************\n");
}

void print_player(t_data *data, char *where)
{
	printf("PLAYER INFO %s\n", where);
	printf("\tx: %f | y: %f\n", data->player.x, data->player.y);
	printf("\tangle: %f\n", data->player.angle * 180 / PI);
	printf("\tdistance to wall: %f\n", data->player.distance_to_wall);
	printf("\tturn_direction: %d | walk_direction: %d\n", data->player.turn_direction, data->player.walk_direction);
	printf("\twalk_speed: %f | turn_speed: %f\n", data->player.walk_speed, data->player.turn_speed);
	printf("\tturn: %d | move: %d\n", data->player.turn, data->player.move);
	printf("************************\n");
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**cubfile_content;

	arguments_validation(argc, argv);
	cubfile_content = cubfile_validation(argv[MAP_ARG]);
	data = setup_data(cubfile_content);
	setup_minilibx(data);
	setup_textures(data);
	print_player(data, "MAIN");
	render(data);
	// our	
	mlx_loop_hook(data->mlx_ptr, update_player, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_input, data);
	mlx_hook(data->win_ptr, DestroyNotify, ButtonPressMask, close_game, data);
	mlx_loop(data->mlx_ptr);

	
	//TODO - colocar o hook para fechar janela!
	//TODO Colocar pra setar as novas inforamções na struct
	return (0);
}
