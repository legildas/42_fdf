# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/26 15:03:57 by gsaynac           #+#    #+#              #
#    Updated: 2015/08/26 15:07:26 by gsaynac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = -I./inc/ -I./libft/

SRC_D = ./src/
SRC = 	$(SRC_D)main.c

OBJ_D = ./.obj/
OBJ = $(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

LIBFT_D = ./libft/
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) $(LIBFT) $(OBJ) -o $(NAME)
	@printf "\n\033[0;32m\033[1m%-24s..%s\n\n\033[0m" "$@" "is complete !"

$(LIBFT) :
	@make -C $(LIBFT_D)

$(OBJ_D)%.o : $(SRC_D)%.c
	@mkdir -p $(OBJ_D)
	@$(CC) $(FLAGS) -o $@ -c $< $(INC)
	@printf "\033[0m%-24s..\033[1m%s\n" "$<" "$@ !"

clean :
	@make -C $(LIBFT_D) clean
	@/bin/rm -rf $(OBJ_D);

fclean : clean
	@make -C $(LIBFT_D) fclean
	@/bin/rm -rf $(NAME);

re : fclean all