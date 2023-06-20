/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:14:37 by acesar-l          #+#    #+#             */
/*   Updated: 2023/06/21 00:47:04 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "stdio.h"

# include "defines.h"
# include "types.h"
# include "util_types.h"
# include "error.h"

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include <math.h>
# include <fcntl.h>

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
 * @brief Validate the elements that were written on the cubfile passed.
 *
 * @param cubfile_name name of the cubfile passed.
 *
 * @return The content of the cubfile passed, already validated.
 * In case there's an error, the function handles it.
*/
char			**cubfile_validation(char *cubfile_name);

/**
 * @brief Checks if the given file can be opened and read.
 *
 * @param filename name of the file.
 *
 * @return 0 for no error. Enum with the file error specified.
*/
t_error_file	is_file_readable(char *filename);

/**
 * @brief Read a file and return its content.
 *
 * @param filename name of the file.
 *
 * @return Content of the file in a single string. 
 * In case there's an error, the function handles it.
*/
char			*read_file(char const *filename);

/**
 * @brief Allocate memory for a data type called t_data.
 *
 * @return The allocated memory, all set to NULL in case of pointer, and 0
 * in case of integers.
*/
t_data			*create_data(void);

/**
 * @brief Setup a struct with important information for
 * the project development.
 *
 * @param cubfile_content content of the file passed to the project.
 *
 * @return 0 for no error. Enum with the file error specified.
*/
t_data			*setup_data(char **cubfile_content);

/**
 * @brief Free all the memory allocated for a t_data pointer and its content.
 *	It includes images, mlx pointers, strings. 
 * All that could be allocated by data.
 *
 * @param data the struct t_data to be freed.
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
 * @brief Validate the texture elements in a cubfile.
 *
 * @param file_content A matrix with the .cub content.
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			texture_validation(char **file_content);

/**
 * @brief Validate the color elements in a cubfile.
 *
 * @param file_content A matrix with the .cub content.
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			color_validation(char **file_content);

/**
 * @brief Validate if the cubfile contains the given element.
 *
 * @param content A matrix with the .cub content.
 *
 * @param elem The element to search for.
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			check_for_element(char **content, char *elem);

/**
 * @brief Validate if the cubfile contains the given color element.
 *
 * @param content A matrix with the .cub content.
 *
 * @param txtr Type of texture to search for.
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			check_for_texture_color(char **content, char txtr);

/**
 * @brief Returns the file passed as parameter to a texture from a cubfile
 *
 * @param content A matrix with the .cub content.
 *
 * @param txtr Type of texture to search for.
 *
 * @return Filename including Path. NULL for error.
*/
char			*get_texture_path(char **content, char *txtr);

/**
 * @brief Init all params related to img textures in a struct data
 *
 * @param data struct data to store the textures info.
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			setup_textures(t_data *data);

/**
 * @brief Validate the Map in a cubfile.
 *
 * @param file_content A matrix with the .cub content
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			map_validation(char **file_content);

/**
 * @brief Specific validation for the map. 
 * Validate if its surrounded by walls.
 *
 * @param map A matrix with the map content
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			check_is_map_surrounded_by_walls(char **map);

/**
 * @brief Setup the colors inside a struct with important information for
 * the project development.
 *
 * @param data struct to store the colors.
 *
 * @param content A matrix with the .cub content.
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			setup_colors(t_data *data, char **content);

/**
 * @brief Generate a new mlx image 
 * and returns a struct with data from the image.
 *
 * @param width Image width, in pixels.
 * @param height Image height, in pixels.
 *
 * @return An mlx image ready to be put. 
 * In case there's an error, the function handles it.
*/
t_img			*new_image(void *mlx_ptr, int width, int height);

/**
 * @brief Normalize the value of the angle passed in radians, 
 * keeping it beetween 0 and 2 * PI.
 *
 * @param angle The angle in radians to normalize.
 *
 * @return The angle normalized.
*/
double			normalize_radian_angle(double angle);

/**
 * @brief Checks if the given position (x, y) inside a map is relative to a wall
 *
 * @param x Position on a horizontal axis
 * @param y Position on a vertical axis
 *
 * @return 0 if its a wall, 1 if it's not, -1 for invalid x or y.
*/
int				is_wall(char **map, int x, int y);

/**
 * @brief Based on arguments from structs data, player and ray, return
 * the distance from a player (x, y) to the closest wall in a given angle.
 *
 * @param data Relevant information for the function, as the map.
 *
 * @param player Information about player position.
 *
 * @param ray Information about the angle to calculate from.
 *
 * @return Distance from a player to the closest wall.
 * In case there's an error, the function handles it.
*/
double			get_player_distance_to_wall(t_data *data, t_player *player, \
t_ray *ray);

/**
 * @brief Generate the image for a specific ray.
 *
 * @param data struct data with relevant information, such as a 
 * pointer to the window in which it will be later rendered.
 *
 * @param ray relevant information about the ray, its angle, number.
 *
 * @return Nothing. In case there's an error, the function handles it.
*/
void			cast_ray(t_data *data, t_ray *ray);

/**
 * @brief Set a given pixel (x, y) from a screen to a specific color.
 *
 * @param img Mlx image to change a pixel color
 *
 * @param x Pixel position on a horizontal axis.
 *
 * @param y Pixel position on a vertical axis.
 *
 * @param color New pixel color, in hexadecimal.
 *
 * @return Nothing.
*/
void			img_pix_put(t_img *img, int x, int y, int color);

/**
 * @brief Render the whole screen using info from data struct.
 *
 * @param data struct containing relevant info from the window,
 * player and mlx pointers
 *
 * @return Nothing.
*/
void			render(t_data *data);

/**
 * @brief Hook to handle player movement and camera rotarion.
 * It render the updated player or camera position.
 *
 * @param data struct containing relevant info from the game,
 * such as window to render, player info, mlx pointers.
 *
 * @return  0.
*/
int				move_and_turn(t_data *data);

/**
 * @brief Keyboard Hook to key pressed. Handle Moviments and
 * Exit the program if necessary.
 *
 * @param keysym Code to a key
 *
 * @param data struct containing relevant info from the game,
 * such as window to render, player info, mlx pointers.
 *
 * @return 0.
*/
int				key_press(int keysym, t_data *data);

/**
 * @brief Hooks to the game engine. It handle movements, 
 * keyboard and mouse events.
 *
 * @param keysym Code to a key
 *
 * @param data struct containing relevant info from the game,
 * such as window to render, player info, mlx pointers.
 *
 * @return 0.
*/
int				key_unpress(int keysym, t_data *data);

/**
 * @brief Hooks to the game engine. It handle movements, 
 * keyboard and mouse events.
 *
 * @param data struct containing relevant info from the game,
 * such as window to render, player info, mlx pointers.
 *
 * @return Nothing.
*/
void			hook_setup(t_data *data);

/**
 * @brief Prints an error message and exit the program.
 *
 * @param error_type enum that defines the type of error.
 *
 * @param error_code specific error code from that error type.
 *
 * @param data struct data to be freed, if necessary.
 *
 * @return Nothing. It exits the program.
*/
void			error_manager(t_error error_type, int error_code, \
t_data *data);

/**
 * @brief Free all the memory allocated and close game.
 *
 * @param data the struct t_data to be freed.
 *
 * @return 0.
*/
int				close_game(t_data *data);

/**
 * @brief Prints an error message formated with the project name and some colors.
 *
 * @param filename filename that returned an error.
 *
 * @param description description of the expected function from the invalid file.
 *
 * @return Nothing. It just prints.
*/
void			print_message_file_is_invalid(char *filename, \
char *description);

/**
 * @brief Prints an error message formated with the project name and some colors.
 *
 * @param error_msg specific message for the error
 *
 * @return Nothing. It just prints.
*/
void			print_error_msg(char *error_msg);

/**
 * @brief Prints an error message for specific texture errors.
 *
 * @param error_code specific error code from what that happened.
 *
 * @return Nothing. It just prints.
*/
void			message_error_texture(t_error_texture error_code);

/**
 * @brief Prints an error message for specific map errors.
 *
 * @param error_code specific error code from what that happened.
 *
 * @return Nothing. It just prints.
*/
void			message_error_map(t_error_map error_code);

/**
 * @brief Prints an error message for specific mlx errors.
 *
 * @param error_code specific error code from what that happened.
 *
 * @return Nothing. It just prints.
*/
void			message_error_mlx(t_error_mlx error_code);

/**
 * @brief Prints an error message for specific argument errors.
 *
 * @param error_code specific error code from what that happened.
 *
 * @return Nothing. It just prints.
*/
void			message_error_arg(t_error_arg error_code);

/**
 * @brief Prints an error message for specific malloc errors.
 *
 * @param error_code specific error code from what that happened.
 *
 * @return Nothing. It just prints.
*/
void			message_error_malloc(t_error_malloc error_code);

/**
 * @brief Prints an error message for specific file errors.
 *
 * @param error_code specific error code from what that happened.
 *
 * @return Nothing. It just prints.
*/
void			message_error_file(t_error_file error_code);

#endif