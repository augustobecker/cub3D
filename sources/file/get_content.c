/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:59:07 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/25 11:21:52 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_cub_file_info(t_data *data, char const *cub_filename)
{
	char **matriz_file;
	char *file_content;

	file_content = read_file(cub_filename);
	matriz_file = ft_split(file_content, '\n');
	free(file_content);
	//cubfile_validation(matriz_file);
	data->map = matriz_file;
}

static char	*read_file(char const *filename)
{
	char	*full_content;
	char	*line;
	int		file_fd;

	file_fd = open(filename, O_RDONLY);
	if (file_fd == -1)
		error_manager(ERROR_FILE, FILE_MISS_PERMISSION, 0);
	full_content = ft_strdup("");
	while (true)
	{
		line = get_next_line(file_fd);
		if (line == NULL)
			break ;
		full_content = ft_strappend(&full_content, line);
		free(line);
	}
	close(file_fd);
	return (full_content);
}
