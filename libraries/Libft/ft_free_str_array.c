/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:27:51 by acesar-l          #+#    #+#             */
/*   Updated: 2022/08/20 09:21:56 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_free_str_array(char **string_array)
{
	char	**temp_ptr;
	
	temp_ptr = string_array;
	while (string_array && *string_array)
		free(*string_array++);
	free(temp_ptr);
}
