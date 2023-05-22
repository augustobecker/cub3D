/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:16:57 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/04/26 04:22:52 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_init(char *map_path, t_data *game)
{
	int		map_fd;
	char	*map_line;
	char	*map_full;
	char	*temp;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		printf("error opening map\n"); // chamar função de erro para sair sair do programa e limpar a memoria
	map_full = ft_strdup("");
	map_line = get_next_line(map_fd);
	while (map_line)
	{
		if (map_line == 0)
			break;
		temp = map_full;
		map_full = ft_strjoin(temp, map_line);
		free(temp);
		free(map_line);
		map_line = get_next_line(map_fd);
	}
	free(map_line);
	close(map_fd);
	game->map = ft_split(map_full, '\n');
	get_map_data(game);
	free(map_full);
}
