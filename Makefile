# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 19:07:14 by acesar-l          #+#    #+#              #
#    Updated: 2023/01/28 03:02:33 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	cub3D

COMPILER 	=	clang
CFLAGS 		= 	-Wall -Wextra -Werror
MLX_FLAGS	=	-lmlx -lXext -lX11
CLEANUP 	= 	rm -rf

LIBFT_PATH	= ./libraries/Libft
LIBFT		= ./libraries/Libft/libft.a

SRCS_PATH	= ./sources

INCLUDES	= -I ./includes

SRCS 		=	$(SRCS_PATH)/main.c								\
				$(SRCS_PATH)/hooks.c							\
				$(SRCS_PATH)/render_map.c						\
				$(SRCS_PATH)/validate/file_validate.c			\
				$(SRCS_PATH)/validate/arguments_validation.c	\
				$(SRCS_PATH)/validate/cubfile_validation.c		\
				$(SRCS_PATH)/validate/map_validation.c			\
				$(SRCS_PATH)/error/error_manager.c				\
				$(SRCS_PATH)/file/get_content.c					\
				$(SRCS_PATH)/clear.c							\
				$(SRCS_PATH)/create.c							\
				$(SRCS_PATH)/map/map_init.c						\
				$(SRCS_PATH)/MiniLibx/setup.c

GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m

all:			$(NAME)

$(NAME):		$(LIBFT)
				@$(COMPILER) $(INCLUDES) $(SRCS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(LIBFT)
				@echo "$(NAME): $(GREEN)$(NAME) was generated$(RESET)"

${LIBFT}:
				@make --no-print-directory  bonus -C $(LIBFT_PATH)

clean:
				@make --no-print-directory clean -C $(LIBFT_PATH)

fclean:
				@$(CLEANUP) $(NAME)
				@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
				@make --no-print-directory fclean -C $(LIBFT_PATH)

re:				fclean $(NAME)

run:
				@./cub3D maps/map1.ber

val:
				@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes ./cub3D maps/map1.ber

.PHONY:			all clean fclean re