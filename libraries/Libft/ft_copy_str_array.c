/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:24:56 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 00:00:07 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	str_array_len(char **str_array);

char	**ft_copy_str_array(char **str_array)
{
	char	**new_str_array;
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	length = str_array_len(str_array);
	if (!length)
		return (NULL);
	new_str_array = ft_calloc(length + 1, sizeof(char *));
	if (new_str_array == NULL)
		return (NULL);
	while (i < length)
	{
		new_str_array[i] = ft_strdup(str_array[i]);
		if (!new_str_array[i])
		{
			ft_free_str_array(new_str_array);
			return (NULL);
		}
		i++;
	}
	new_str_array[i] = NULL;
	return (new_str_array);
}

static size_t	str_array_len(char **str_array)
{
	size_t	length;

	length = 0;
	if (!str_array)
		return (0);
	while (*str_array)
	{
		length++;
		str_array++;
	}
	return (length);
}
