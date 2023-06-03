/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 20:36:35 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		handle_no_event(void);
void	print_map(t_data *data);

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**cubfile_content;

	arguments_validation(argc, argv);
	cubfile_content = cubfile_validation(argv[MAP_ARG]);
	data = setup_data(cubfile_content);
	setup_minilibx(data);
	setup_textures(data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, close_game, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_input, data);
	mlx_loop_hook(data->win_ptr, &handle_no_event, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	handle_no_event(void)
{
	return (0);
}
