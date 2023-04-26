/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 04:23:15 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/26 04:23:29 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_data *data)
{
	data->rows = 0;
	exit (0);
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == KEY_Q || keysym == KEY_ESC)
		close_game(data);
	return (0);
}
