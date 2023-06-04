/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:59:07 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/26 23:33:02 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
