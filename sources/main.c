/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/19 12:13:16 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hook_window(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, ft_move_and_turn, data);
	mlx_hook(data->win_ptr, 2, 1, key_press, data);
	mlx_hook(data->win_ptr, 3, 10, key_unpress, data);
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
	render(data);
	hook_window(data);
	return (0);
}
