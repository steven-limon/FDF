#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slimon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 00:08:39 by slimon            #+#    #+#              #
#    Updated: 2019/09/23 04:50:29 by slimon           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
CFLAGS = -Wall -Wextra -Werror
IDIR = ./includes
LIBDIR = libs
MLXDIR = libs/minilibx

SDIR=./srcs
_SRC	=	map2.c\
			edges.c\
			controls.c\
			callbacks.c\
			hooks.c\
			draw.c\
			transformations.c\
			transformations2.c\
			projection.c\
			matrix.c\
			color.c\
			vector1.c\
			vector2.c\
			camera.c\
			matrix_transforms1.c\
			matrix_transforms2.c\
			get_next_line.c\
			map.c\
			main.c
SRC = $(addprefix $(SDIR)/, $(_SRC))
OBJ = $(SRC:.c=.o)

HEADERS = -I $(IDIR) -I $(LIBDIR)/includes -I $(MLXDIR)
LIBS = -L $(LIBDIR)/libft -lft -L $(MLXDIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
$(NAME):
	make -C ./libs/minilibx
	make -C ./libs/libft
	gcc $(LIBS) $(SRC) $(CFLAGS) $(HEADERS) -o $(NAME)
debug:
	gcc $(LIBS) $(SRC) $(HEADERS) -o $(NAME) -g
clean:
	make -C ./libs/minilibx clean
	make -C ./libs/libft clean
	rm -f ./*.o
fclean: clean
	make -C ./libs/libft fclean 
	rm -f $(NAME)
re: fclean all
