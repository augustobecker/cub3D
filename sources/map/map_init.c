/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:16:57 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/04/25 13:34:02 by gnuncio-         ###   ########.fr       */
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
		printf("%s\n", map_full);
		free(temp);
		free(map_line);
		map_line = get_next_line(map_fd);
	}
	free(map_line);
	close(map_fd);
	printf("Cheguei aqui\n");
	game->map = ft_strdup(map_full);
	free(map_full);
}