# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 20:12:23 by pabad-ap          #+#    #+#              #
#    Updated: 2024/10/03 20:21:06 by pabad-ap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

DIR_LIBFT	= ./lib/libft/
LIBFT		= libft.a

#___MAC___
#DIR_MLX		= ./lib/minilibx_macos/
#MLX			= libmlx.a

#___LINUX___
DIR_MLX		= ./lib/minilibx_linux/
MLX			= libmlx.a
MLXFLAG		= -lmlx -lXext -lX11

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
DEPFLAGS	= -MMD



OBJS = main.o ft_input_checks.o ft_fdf_utils.o ft_get_next_line.o \
	ft_get_next_line_utils.o ft_str_to_int.o ft_fill_point_details.o \
	ft_line_bresenham.o ft_mlx_functions.o ft_iso_point.o \
	ft_hooks_handler.o

DEPS = $(addsuffix .d, $(basename $(OBJS)))

all: libft mlx $(NAME)

-include $(DEPS)
$(NAME) : $(OBJS)  
#	$(CC) $(CFLAGS) $(OBJS) -L$(DIR_LIBFT) -L$(DIR_MLX)  -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME) #MAC
	$(CC) $(CFLAGS) $(OBJS)  -L$(DIR_LIBFT) -L$(DIR_MLX) -lft -lm $(MLXFLAG) -o $(NAME) #LINUX

$(OBJS): Makefile fdf.h

mlx:
	@make -C $(DIR_MLX) all

libft:
	$(MAKE) -C $(DIR_LIBFT)

clean:
	$(MAKE) clean -C $(DIR_LIBFT)
	$(MAKE) clean -C $(DIR_MLX)
	rm -f $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) fclean -C $(DIR_LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean libft mlx
