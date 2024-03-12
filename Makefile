# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armgevor <armgevor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 15:15:41 by valeriafedo       #+#    #+#              #
#    Updated: 2024/02/29 20:26:26 by armgevor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



.PHONY		:	all clean fclean re libft debug

NAME		=	miniRT

HEADER		=	$(addprefix include/,	\
					minirt.h			\
					parcing.h			\
					scene.h				\
					get_next_line.h		\
					utils.h)

CFLAGS		=	-I include

CFLAGS		+=	-Wall -Wextra -Werror -g

# CFLAGS		+=	-fsanitize=address

RM			=	rm -rf

LIBFT		=	./libft/libft.a
LIBFT_H		=	./libft/libft.h

LIBMLX		=	./libmlx/libmlx.a

SRCS		=	$(addprefix src/, $(FILE_C))

FILE_C		=	main.c

FILE_C		+=	$(addprefix parcing/, 		\
					get_next_line.c			\
					get_next_line_utils.c	\
					get_split.c				\
					parc.c					\
					id_check.c				\
					free_and_to_struct1.c	\
					free_and_to_struct2.c	\
					free_and_to_struct3.c	\
					error_free_exit.c)


FILE_C		+=	$(addprefix utils/, \
					init.c			\
					init1.c			\
					lft_utils.c)

OBJ			=	$(addprefix objects/, $(FILE_C:%.c=%.o))

FOLDER		=	$(sort $(dir objects/ $(OBJ)))

all			:	$(FOLDER) $(LIBFT) $(LIBMLX) $(NAME)

$(NAME)		:	$(OBJ) $(LIBFT) $(LIBMLX)
				$(CC) $(CFLAGS) $(DEBF) $(LIBFT) $(LIBMLX) -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

$(LIBFT)		:	libft_obj
				make -C ./libft

libft_obj	:
				mkdir libft_obj

$(LIBMLX)		:
				make -C ./libmlx


$(FOLDER)	:
				mkdir -p $@

objects/%.o	:	./src/%.c $(HEADER) Makefile $(LIBFT_H)
				$(CC) $(CFLAGS) $(DEBF) -c $< -o $@

debug:
				make DEBF="-g3"

clean		:
				$(RM) $(OBJ)
				$(RM) $(FOLDER)
				make clean -C ./libft
				make clean -C ./libmlx
				$(RM) libft_obj

fclean		:	clean
				$(RM) $(NAME)
				make fclean -C ./libft

re			:	fclean all