/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:30:29 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/03 00:25:03 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void    check_map_char_elements(char **map);

// void map_validation(char **file_content)
// {
//     char    **map;

//     map = &file_content[NUM_OF_ELEM_BEFORE_MAP];
//     check_map_char_elements(map);
// }

// static void    check_map_char_elements(char **map)
// {
//     int line;
//     int column;
//     int player_starting_pos;

//     line = 0;
//     player_starting_pos = 0;
//     while (map[line])
//     {
//         column = 0;
//         while (map[line][column])
//         {
//             if (!ft_strchr("01NSEW ", map[line][column]))
//                 error_manager(MAP_INVALID_ELEMENT);
//             if ((map[line][column] == 'N') || (map[line][column] == 'S')
//             || (map[line][column] == 'E') || (map[line][column] == 'W'))
//                 player_starting_pos++;
//             column++;
//         }
//         if (player_starting_pos > 1)
//             error_manager(MAP_MULT_PLAYER_STARTING_POS);
//         line++;
//     }
//     if (player_starting_pos != 1)
//             error_manager(MAP_MISS_PLAYER_STARTING_POS);
// }

