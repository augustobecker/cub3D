/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 02:01:14 by acesar-l          #+#    #+#             */
/*   Updated: 2023/05/23 02:04:00 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_matrix_free(char **ptr, int num_elem)
{
	int	elem;

	elem = 0;
	while (elem < num_elem)
		free(ptr[elem++]);
	free(ptr);
}