/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:11:57 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/20 18:22:57 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_TYPES_H
# define UTIL_TYPES_H

typedef struct s_player_collision_rule
{
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;
}	t_player_collision_rule;

#endif