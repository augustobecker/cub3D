/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:59:07 by acesar-l          #+#    #+#             */
/*   Updated: 2023/04/05 13:36:27 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**read_file(char const *filename);

void get_cub_file_info(t_data *data, char const *cub_filename)
{
	char **file_content;

	file_content = read_file(cub_filename);
	cubfile_validation(file_content);
	error_manager(NOT_CONFIGURED_YET);
	data->map = NULL;
}

static char	**read_file(char const *filename)
{
	char	**content;
	char	*full_content;
	char	*line;
	int		file_fd;
 
	file_fd = open(filename, O_RDONLY);
	if (file_fd == -1)
		error_manager(FILE_DOESNT_EXIST);
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
	content = ft_split(full_content, '\n');
	free(full_content);
	if (!content)
		error_manager(MALLOC_ERROR);
	return (content);
}
