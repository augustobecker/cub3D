/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:14:37 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/05 18:12:43 by gnuncio-         ###   ########.fr       */
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

void			render(t_data *data);
void			raycasting(t_data *data);
void			cast_ray(t_data *data, t_ray *ray);

//images
void			setup_textures(t_data *data);
t_img			*new_image(void *mlx_ptr, int width, int height);

int				handle_no_event(void);

//raycast
int				wall_height(t_ray *ray);

//pixel_put
void			img_pix_put(t_img *img, int x, int y, int color);
void			img_pixel_put_txtr(t_img *win, t_img *txtr, t_player *player, \
t_ray *ray, int px_y);

//map/utils
t_bool			is_wall(char **map, int x, int y);

//render/ distance
double			get_player_distance_to_wall(t_data *data, t_player *player, \
t_ray *ray);

//drawn
double			normalize_radian_angle(double angle);

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
t_data			*setup_data(char **cubfile_content);


int				key_press(int key, t_data *data);

#endif