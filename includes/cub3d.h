/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:14:37 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/17 05:33:50 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "stdio.h"
# include "stdlib.h"

# include "defines.h"
# include "types.h"

# include "error.h"

# include "libft.h"

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include <math.h>
# include <fcntl.h>

double			normalize_radian_angle(double angle);
void			ft_drawn(t_data *data);
void			ft_distance_wall(t_data *data);

void			render(t_data *data);

void			print_player(t_data *data, char *where);

void			print_message_file_is_invalid(char *filename, \
char *description);
int				close_game(t_data *data);
int				handle_input(int keysym, t_data *data);
int				render_map(t_data *data);
void			img_pix_put(t_img *img, int x, int y, int color);
char			*read_file(char const *filename);
void			color_validation(char **file_content);
void			check_for_element(char **content, char *elem);
void			check_for_texture_color(char **content, char txtr);

void			print_error_msg(char *error_msg);
void			message_error_texture(t_error_texture error_code);
void			message_error_map(t_error_map error_code);
void			message_error_mlx(t_error_mlx error_code);
void			message_error_arg(t_error_arg error_code);
void			message_error_malloc(t_error_malloc error_code);
void			message_error_file(t_error_file error_code);

char			*get_texture_path(char **content, char *txtr);

void			setup_textures(t_data *data);
t_img			*new_image(void *mlx_ptr, int width, int height);

int				handle_no_event(void);

int				is_wall(char **map, int x, int y);

/**
 * @brief Validate the arguments that were entered on the command line.
 *
 * @param argc How many arguments were entered on the command line.
 * @param argv The arguments that were entered on the command line.
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			arguments_validation(int argc, char *const *argv);

/**
 * @brief Prints an error message and exit the program.
 *
 * @param error_type enum that defines the error.
 *
 * @return Nothing. It exits the program.
*/
void			error_manager(t_error error_type, int error_code, \
t_data *data);

/**
 * @brief Allocate memory for a data type called t_data.
 *
 * @return The allocated memory, all set to NULL in case of pointer, and 0
 * in case of integers.
*/
t_data			*create_data(void);

/**
 * @brief Free all the memory allocated for a t_data pointer and its content.
 *
 * @param data the data to be freed.
*/
void			clear_data(t_data *data);

/**
 * @brief Init MiniLibx Graphics Library, pointers, windowns and etc.
 *
 * @param data struct data to store the minilix
 * pointers returned from the init process.
*/
void			setup_minilibx(t_data *data);

/**
 * @brief Validate the elements that were written on the cubfile passed.
 *
 * @param cubfile_name name of the cubfile passed.
 *
 * @return The content of the cubfile passed, already validated.
 * In case there's an error, the function handles it.
*/
char			**cubfile_validation(char *cubfile_name);

/**
 * @brief Validate the texture elements in a cubfile.
 *
 * @param file_content A matrix with the .cub content.
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			texture_validation(char **file_content);

/**
 * @brief Validate the Map in a cubfile.
 *
 * @param file_content A matrix with the .cub content
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			map_validation(char **file_content);

/**
 * @brief Checks if the given file can be opened and read.
 *
 * @param filename name of the file.
 *
 * @return 0 for no error. Enum with the file error specified.
*/
t_error_file	is_file_readable(char *filename);

/**
 * @brief Setup a struct with important information for
 * the project development
 *
 * @param cubfile_content content of the file passed to the project.
 *
 * @return 0 for no error. Enum with the file error specified.
*/
t_data	*setup_data(char **cubfile_content);


int				key_press(int key, t_data *data);

int				ft_iswall(char **map, double i, double j);

int				ft_move_and_turn(t_data *data);

char			**ft_get_map(char **text);

char			**ft_read_all_file(const char *path);

#endif