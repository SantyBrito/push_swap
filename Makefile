# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 15:51:25 by sbrito            #+#    #+#              #
#    Updated: 2024/03/18 21:09:09 by sbrito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRS	=	push_swap.c \
			push_func.c \
			push_add.c	\
			push_check.c

OBJC	=	push_swap.o \
			push_func.o \
			push_add.o	\
			push_check.o

INC		=	push_swap.h

NAME	=	push_swap

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJC)
	cc $(FLAGS) $(OBJC) -o $(NAME)

$(OBJC): $(SCRS)
	cc $(FLAGS) $(SCRS) -c

clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(NAME)

re: fclean all
