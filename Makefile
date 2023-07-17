# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imontero <imontero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 16:14:07 by imontero          #+#    #+#              #
#    Updated: 2023/07/14 11:37:56 by imontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 				so_long

NAME_BONUS =		so_long_bonus

CC = 				gcc

CFLAGS =			-g3 -Wall -Werror -Wextra -Ilibmlx #-fsanitize=address

MLXFLAGS =			-framework OpenGL -framework AppKit

FTPRINTF = 			ft_printf.a

GNL = 				get_next_line.a

LIBFT = 			libft.a

MLX = 				libmlx.a

SRC_FILES = 		main.c \
            		utils/utils.c \
					errors/errors1.c \
					errors/errors2.c \
					checks/check1.c \
					checks/check2.c \
					checks/check3.c \
					game/game.c \
					game/game2.c \
					game/game3.c \

SRC_FILES_BONUS = 	bonus/main_bonus.c \
            		bonus/utilsb/utils_bonus.c \
					bonus/errorsb/errors1_bonus.c \
					bonus/errorsb/errors2_bonus.c \
					bonus/checksb/check1_bonus.c \
					bonus/checksb/check2_bonus.c \
					bonus/checksb/check3_bonus.c \
					bonus/gameb/game_bonus.c \
					bonus/gameb/game2_bonus.c \
					bonus/gameb/game3_bonus.c \
					bonus/gameb/game4_bonus.c \
					bonus/gameb/put_images_bonus.c \
					bonus/animb/animations.c \
					bonus/animb/animations2.c \
					bonus/animb/animaux.c \

INCLUDE = 			so_long.h

INCLUDE_BONUS =		bonus/so_long_bonus.h

OBJS = $(SRC_FILES:.c=.o)

OBJS_BONUS = $(SRC_FILES_BONUS:.c=.o)

#.c.o: $(SRCS)
#	$(CC) $(CFLAGS) $(SRCS) -c $(OBJS) -o

all: ftprintf gnl libft mlx $(NAME)

bonus: ftprintf gnl libft mlx $(NAME_BONUS)

mlx:
	make -C libmlx
	cp libmlx/$(MLX) $(MLX)

ftprintf:
	make -C ft_printf
	cp ft_printf/$(FTPRINTF) $(FTPRINTF)

libft:
	make -C libft
	cp libft/$(LIBFT) $(LIBFT)

gnl:
	make -C gnl
	cp gnl/$(GNL) $(GNL)

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(FTPRINTF) $(GNL) $(LIBFT) $(MLX) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(INCLUDE_BONUS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS_BONUS) $(FTPRINTF) $(GNL) $(LIBFT) $(MLX) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	rm -f $(FTPRINTF)
	rm -f $(LIBFT)
	rm -f $(GNL)
	rm -f $(MLX)
	make -C ft_printf clean
	make -C libft clean
	make -C gnl clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make -C ft_printf fclean
	make -C libft fclean
	make -C gnl fclean
	make -C libmlx clean

re: fclean all

.PHONY: all clean fclean re libft gnl printf bonus