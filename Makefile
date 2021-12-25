# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 16:58:20 by mdaillet          #+#    #+#              #
#    Updated: 2021/12/24 10:38:14 by mdaillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g3 -O0 #-fsanitize=leak

SRCS	=	srcs/main.c \
			srcs/utils/ft_str.c \
			srcs/utils/ft_free.c \
			srcs/utils/ft_error.c \
			srcs/utils/ft_map_utils.c \
			srcs/utils/ft_colors.c	\
			srcs/checker/ft_checker.c \
			srcs/checker/ft_check_map2.c \
			srcs/checker/ft_check_map3.c \
			srcs/checker/ft_check_map.c \
			srcs/checker/ft_treat_fc.c \
			srcs/checker/ft_treat_walls.c \
			srcs/parse/ft_init.c \
			srcs/parse/ft_init2.c \
			srcs/parse/ft_parse.c \
			srcs/parse/ft_parse_config.c \
			srcs/execute/ft_key_hook.c \
			srcs/execute/ft_minimap.c \
			srcs/execute/ft_cub3d.c \
			srcs/execute/ft_wall_textures.c \
			srcs/execute/ft_mov.c \
			srcs/execute/ft_draw.c

OBJS	=	$(SRCS:.c=.o)

LIBS	=	-lm -Llibft -lft -Lminilibx -lmlx -lXext -lX11

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			make -C minilibx
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
			@echo "Compilation done !"

bonus: $(NAME)
					
clean:
			make -C libft clean
			make -C minilibx clean
			rm -rf $(OBJS)

fclean:		clean
			make -C libft fclean
			make -C minilibx fclean
			rm -rf $(NAME)
			@echo "Cleaning done !"

norme:
			norminette inc
			norminette srcs
			norminette libft
			@echo "Norme done !"

re:			fclean all

.PHONY:		all clean fclean norme re
