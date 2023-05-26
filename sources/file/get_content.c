/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:59:07 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/24 21:30:38 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_file(char const *filename);

void get_cub_file_info(t_data *data, char const *cub_filename)
{
	char **matrix_content;
	char *file_content;
	int i;
	int endline;

	endline = 0;
	i = 0;
	file_content = read_file(cub_filename);
	if (!file_content[0])
		error_manager(ERROR_TEXTURE, IS_MISSING_ELEM, data);
	matrix_content = ft_split(file_content, '\n');
	//cubfile_validation(matrix_content);
	while (file_content[i] && endline < 6)
	{
		if (file_content[i] == '\n' && file_content[i + 1] != '\n')
			endline++;
		i++;
	}
	i++;
	data->map = ft_split(&file_content[i], '\n');
	free(file_content);
}

char	*read_file(char const *filename)
{
	char	*full_content;
	char	*line;
	int		file_fd;

	file_fd = open(filename, O_RDONLY);
	if (file_fd == -1)
		error_manager(ERROR_FILE, FILE_FAILED_TO_OPEN, 0);
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
