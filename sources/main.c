/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/16 22:08:49 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int keysym, t_data *data)
{
	if (keysym == KEY_Q || keysym == KEY_ESC)
		clear_data(data);
	else if (keysym == KEY_W)
		data->player.move = UP;
	else if (keysym == KEY_D)
		data->player.move = RIGHT;
	else if (keysym == KEY_A)
		data->player.move = LEFT;
	else if (keysym == KEY_S)
		data->player.move = DOWN;
	else if (keysym == KEY_LEFT)
		data->player.turn = LEFT;
	else if (keysym == KEY_RIGHT)
		data->player.turn = RIGHT;
	return (0);
}

int ft_key_unpressed(int keysym, t_data *data)
{
	if (keysym == KEY_W)
		data->player.move = STOP;
	else if (keysym == KEY_D)
		data->player.move = STOP;
	else if (keysym == KEY_A)
		data->player.move = STOP;
	else if (keysym == KEY_S)
		data->player.move = STOP;
	else if (keysym == KEY_LEFT)
		data->player.turn = STOP;
	else if (keysym == KEY_RIGHT)
		data->player.turn = STOP;
	return (0);
}

int close_game(t_data *data)
{
	clear_data(data);
	return (0);
}

int	update_player(t_data *data)
{
	ft_raycast(data);
	return (0);
}

void	print_map(char **map)
{
	int i;
	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
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
	printf("\tPlayer angle: %f\n", data->player.angle * 180 / PI);
	printf("\tRAY %d\n", data->player.ray);
	printf("\tRay angle: %f\n", data->player.ray_ang * 180 / PI);
	printf("\tdistance to wall: %f\n", data->player.distance_to_wall);
	printf("\tturn_direction: %d | walk_direction: %d\n", data->player.turn_direction, data->player.walk_direction);
	printf("\twalk_speed: %f | turn_speed: %f\n", data->player.walk_speed, data->player.turn_speed);
	printf("\tturn: %d | move: %d\n", data->player.turn, data->player.move);
	printf("************************\n");
}

void	hook_window(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, ft_move_and_turn, data);
	mlx_hook(data->win_ptr, 2, 1 , handle_input, data);
	mlx_hook(data->win_ptr, 3, 10, ft_key_unpressed, data);
	mlx_hook(data->win_ptr, 17, 0, close_game, data);
	mlx_loop(data->mlx_ptr);
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
	//print_map(data->map);
	//close_game(data);
	ft_raycast(data);
	hook_window(data);
	return (0);
}
