#include "cub3d.h"

void get_cub_file_info(t_data *data, char const *cub_filename)
{
	char *file_content;

	file_content = read_file(cub_filename);
}

char *read_file(char const *filename)
{
	char	*full_content;
	char	*line;
	int		file_fd;
 
	file_fd = open(argv, O_RDONLY);
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
	return (full_content);
}
