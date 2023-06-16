/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:24:11 by gnuncio-          #+#    #+#             */
/*   Updated: 2023/06/15 15:37:37 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_map_max_column(char **text);
static int	ft_map_count_line(char **text);
int			ft_line_code(char *line);
char		**ft_read_all_file(const char *path);
static int	ft_file_line_count(const char *path);

char	**ft_get_map(char **text)
{
	char	**map;
	int		i;
	int		j;

	map = ft_calloc (ft_map_count_line (text) + 1, sizeof(char *));
	i = -1;
	j = 0;
	while (text[++i])
	{
		if (ft_line_code(text[i]) == WALL)
		{
			map[j] = ft_calloc(ft_map_max_column(text) + 1, sizeof(char *));
			ft_strlcpy (map[j], text[i], ft_strlen(text[i]) + 1);
			j ++;
		}
	}
	return (map);
}

static int	ft_map_count_line(char **text)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (text[i])
	{
		if (ft_line_code(text[i]) == WALL)
			size ++;
		i ++;
	}
	return (size);
}

static int	ft_map_max_column(char **text)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (text[i])
	{
		if (ft_line_code(text[i]) == WALL)
		{
			if (size < (int)ft_strlen(text[i]))
				size = ft_strlen(text[i]);
		}
		i ++;
	}
	return (size);
}

int	ft_flag_code(char *flag)
{
	if (flag[0] == '1')
		return (WALL);
	if (flag[0] == '\0')
		return (END);
	if (flag[0] == '\n')
		return (NEW_LINE);
	if (ft_strncmp(flag, "C", ft_strlen(flag)) == 0)
		return (C);
	if (ft_strncmp(flag, "F", ft_strlen(flag)) == 0)
		return (F);
	if (ft_strncmp(flag, "NO", ft_strlen(flag)) == 0)
		return (NO);
	if (ft_strncmp(flag, "SO", ft_strlen(flag)) == 0)
		return (SO);
	if (ft_strncmp(flag, "WE", ft_strlen(flag)) == 0)
		return (WE);
	if (ft_strncmp(flag, "EA", ft_strlen(flag)) == 0)
		return (EA);
	return (1);
}

int	ft_line_code(char *line)
{
	char	**split;
	int		status;

	split = ft_split(line, ' ');
	status = ft_flag_code(split[0]);
	ft_free_str_array(split);
	return (status);
}

char	**ft_read_all_file(const char *path)
{
	int		size;
	int		i;
	int		fd;
	char	*line;
	char	**text;

	size = ft_file_line_count(path);
	fd = open (path, O_RDWR);
	if (fd < 1)
		return (NULL);
	text = ft_calloc(sizeof(char *), size + 1);
	if (!text)
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		text[i++] = ft_strdup(line);
		free(line);
	}
	close(fd);
	return (text);
}

static int	ft_file_line_count(const char *path)
{
	int		i;
	int		fd;
	char	*line;

	fd = open (path, O_RDWR);
	if (fd < 0)
		return (0);
	i = -1;
	while (++i > -1)
	{
		line = get_next_line (fd);
		if (line == NULL)
			break ;
		free(line);
	}
	free(line);
	close (fd);
	return (i);
}
