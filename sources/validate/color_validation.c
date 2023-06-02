/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 01:31:40 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 01:35:22 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_validation(char **file_content)
{
	check_for_element(file_content, "F ");
	check_for_element(file_content, "C ");
	check_for_texture_color(file_content, 'F');
	check_for_texture_color(file_content, 'C');
}
