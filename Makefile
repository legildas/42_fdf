# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/26 15:03:57 by gsaynac           #+#    #+#              #
#    Updated: 2015/08/26 18:02:14 by gsaynac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	gcc
FLAGS	=	-Wall -Wextra

SRC_D	=	./src/
SRC		=	$(SRC_D)main.c \
			$(SRC_D)mlx.c \
			$(SRC_D)error.c \
			$(SRC_D)parse.c \
			$(SRC_D)process.c \
			$(SRC_D)draw.c \
			$(SRC_D)settings.c

OBJ_D	=	./.obj/
OBJ		=	$(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

LIBFT_D	=	./libft/
LIBFT	=	$(LIBFT_D)libft.a

MLX_D	=	./mlx/
MLX		=	$(MLX_D)libmlx.a

INC_D	=	./inc/

INC		=	-I$(INC_D) \
			-I$(LIBFT_D) \
			-I$(MLX_D)

LIB		=	$(LIBFT) $(MLX) -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(MLX) $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIB) -o $(NAME)
	@printf "\n\033[0;32m\033[1m%-24s..%s\n\n\033[0m" "$@" "is complete !"

$(MLX) :
	@make -C $(MLX_D)

$(LIBFT) :
	@make -C $(LIBFT_D)

$(OBJ_D)%.o : $(SRC_D)%.c
	@mkdir -p $(OBJ_D)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@printf "\033[0m%-24s..\033[1m%s\n" "$<" "$@ !"

clean :
	@make -C $(LIBFT_D) clean
	@make -C $(MLX_D) clean
	@/bin/rm -rf $(OBJ_D);

fclean : clean
	@make -C $(LIBFT_D) fclean
	@make -C $(MLX_D) clean
	@/bin/rm -rf $(NAME);

re : fclean all