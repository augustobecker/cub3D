/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/02 23:48:46 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int  handle_no_event(void);
void print_map(t_data *data);

int main ( int argc, char **argv )
{
	t_data		*data;
	char		**cubfile_content;

	arguments_validation(argc, argv);
	cubfile_content = cubfile_validation(argv[MAP_ARG]);
	data = setup_data(cubfile_content);
	setup_minilibx(data);
	print_map(data);

	// X na janela
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, close_game, data);

	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_input, data);

	// Renderizar imagem (com exposure para mesmo sendo sobreposta reprintar)
	//mlx_hook(data->win_ptr, Expose, ExposureMask, , data);

	// quando no acontecer nenhum evento
	mlx_loop_hook(data->win_ptr, &handle_no_event, data);

	//mlx_hook(data->win_ptr, Expose, ExposureMask, render_map, data);

	//desenhar quando a tela for sobreposta
	//mlx_expose_hook(game->win_ptr, &ft_redraw, game);

	mlx_loop(data->mlx_ptr);

	//clear_data(data);
	return (0);
}


void print_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			printf("%c", data->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int	handle_no_event(void)
{
	return (0);
}