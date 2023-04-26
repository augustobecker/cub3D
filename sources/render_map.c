/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 04:23:52 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/26 04:24:14 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_rect(t_data *data, int x, int y)
{
	printf("%c", data->map[y][x]);
}

int render_map(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			render_rect(data, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
