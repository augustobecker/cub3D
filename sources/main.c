/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:09:00 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/02 22:46:33 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int  handle_no_event(void);

int main ( int argc, char **argv )
{
	t_data		*data;
	char		**cubfile_content;

	arguments_validation(argc, argv);
	cubfile_content = cubfile_validation(argv[MAP_ARG]);
	data = setup_data(cubfile_content);

	// Tecla Pressionada
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_input, data);

	// X na janela
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, close_game, data);

	// Renderizar imagem (com exposure para mesmo sendo sobreposta reprintar)
	//mlx_hook(data->win_ptr, Expose, ExposureMask, , data);

	// quando no acontecer nenhum evento
	mlx_loop_hook(data->win_ptr, &handle_no_event, data);

	//mlx_hook(data->win_ptr, Expose, ExposureMask, render_map, data);

	//desenhar quando a tela for sobreposta
	//mlx_expose_hook(game->win_ptr, &ft_redraw, game);

	mlx_loop(data->mlx_ptr);

	//setup()
	clear_data(data);

	return (0);
}

int	handle_no_event(void)
{
	return (0);
}