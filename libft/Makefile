#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaynac <gsaynac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 19:46:32 by gsaynac           #+#    #+#              #
#    Updated: 2014/05/14 20:01:14 by gsaynac          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = ./

SRC_D = ./
SRC = $(SRC_D)ft_atoi.c \
	$(SRC_D)ft_strcat.c \
	$(SRC_D)ft_strchr.c \
	$(SRC_D)ft_strcpy.c \
	$(SRC_D)ft_strdup.c \
	$(SRC_D)ft_strlen.c \
	$(SRC_D)ft_strncat.c \
	$(SRC_D)ft_strncpy.c \
	$(SRC_D)ft_strrchr.c \
	$(SRC_D)ft_strstr.c \
	$(SRC_D)ft_strnstr.c \
	$(SRC_D)ft_strcmp.c \
	$(SRC_D)ft_strncmp.c \
	$(SRC_D)ft_strlcat.c \
	$(SRC_D)ft_isalpha.c \
	$(SRC_D)ft_isdigit.c \
	$(SRC_D)ft_isalnum.c \
	$(SRC_D)ft_isascii.c \
	$(SRC_D)ft_isprint.c \
	$(SRC_D)ft_toupper.c \
	$(SRC_D)ft_tolower.c \
	$(SRC_D)ft_memset.c \
	$(SRC_D)ft_bzero.c \
	$(SRC_D)ft_memcpy.c \
	$(SRC_D)ft_memccpy.c \
	$(SRC_D)ft_memmove.c \
	$(SRC_D)ft_memchr.c \
	$(SRC_D)ft_memcmp.c \
	$(SRC_D)ft_putchar.c \
	$(SRC_D)ft_putchar_fd.c \
	$(SRC_D)ft_putendl.c \
	$(SRC_D)ft_putendl_fd.c \
	$(SRC_D)ft_putnbr.c \
	$(SRC_D)ft_putnbr_fd.c \
	$(SRC_D)ft_putstr.c \
	$(SRC_D)ft_putstr_fd.c \
	$(SRC_D)ft_putcat.c \
	$(SRC_D)ft_memalloc.c \
	$(SRC_D)ft_memdel.c \
	$(SRC_D)ft_strnew.c \
	$(SRC_D)ft_strdel.c \
	$(SRC_D)ft_strclr.c \
	$(SRC_D)ft_striter.c \
	$(SRC_D)ft_striteri.c \
	$(SRC_D)ft_strmap.c \
	$(SRC_D)ft_strmapi.c \
	$(SRC_D)ft_strequ.c \
	$(SRC_D)ft_strnequ.c \
	$(SRC_D)ft_strsub.c \
	$(SRC_D)ft_strjoin.c \
	$(SRC_D)ft_strtrim.c \
	$(SRC_D)ft_itoa.c \
	$(SRC_D)ft_strsplit.c \
	$(SRC_D)ft_lstnew.c \
	$(SRC_D)ft_lstdelone.c \
	$(SRC_D)ft_lstdel.c \
	$(SRC_D)ft_lstadd.c \
	$(SRC_D)ft_lstiter.c \
	$(SRC_D)ft_lstmap.c \
	$(SRC_D)ft_upper_str.c \
	$(SRC_D)ft_lower_str.c \
	$(SRC_D)ft_pow.c \
	$(SRC_D)ft_max.c \
	$(SRC_D)ft_min.c \
	$(SRC_D)ft_fabs.c \
	$(SRC_D)ft_ceil.c \
	$(SRC_D)ft_floor.c \
	$(SRC_D)ft_sqrt.c \
	$(SRC_D)get_next_line.c

OBJ_D = .obj/
OBJ = $(SRC:$(SRC_D)%.c=$(OBJ_D)%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@printf "\n\033[0;32m\033[1m%-24s..%s\n\n\033[0m" "$@" "is complete !"

$(OBJ_D)%.o : $(SRC_D)%.c
	@mkdir -p $(OBJ_D)
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC)
	@printf "\033[0m%-24s..\033[1m%s\n" "$<" "$@ !"

clean :
	@/bin/rm -rf $(OBJ_D);

fclean : clean
	@/bin/rm -rf $(NAME);

re : fclean all
