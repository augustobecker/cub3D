# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 19:07:14 by acesar-l          #+#    #+#              #
#    Updated: 2023/01/24 20:57:06 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	cub3D

COMPILER 	=	gcc -g
CFLAGS 		= 	-Wall -Wextra -Werror
CLEANUP 	= 	rm -rf

LIBFT_PATH	= ./libraries/Libft
LIBFT		= ./libraries/Libft/libft.a

SRCS_PATH	= ./sources

INCLUDE		= -I ./includes

SRCS 		=	$(SRCS_PATH)/main.c								\
				$(SRCS_PATH)/validate/arguments_validation.c	\
				$(SRCS_PATH)/error/error_manager.c


GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m

all:			$(NAME)

$(NAME):		$(LIBFT)
				@$(COMPILER) $(CFLAGS) $(LIBFT) $(SRCS) $(INCLUDE) -o $(NAME)
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

.PHONY:			all clean fclean re