# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/01 18:26:03 by vminomiy          #+#    #+#              #
#    Updated: 2020/09/02 22:40:45 by vminomiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

CC		=	nasm

FLAGS	=	-f elf64

SRCS	=	ft_strlen.s		\
			ft_strcpy.s		\
			ft_strcmp.s		\
			ft_write.s		\
			ft_read.s		\
			ft_strdup.s

OBJS	=	$(patsubst %.s, %.o, ${SRCS})

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@echo "\033[0mUpdating library..."
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)
			@echo "\033[0m"

%.o: %.s
			@echo "\033[0mGenerating Lib..."
			$(CC) $(FLAGS) -o $@ $<
			@echo "\033[0m"

clean	:	
			@echo "\033[0mCleaning objects..."
			rm -f $(OBJS)
			rm -f ./tester
			@echo "\033[0m"

fclean	:	clean
			@echo "\033[0mCleaning objects and library..."
			rm -f $(NAME)
			@echo "\033[0m"

re		:	fclean all

test	:	all main.c
			clang -g -no-pie -Werror -Wextra -Wall main.c -L./ -lasm -I ./libasm.h -o tester

.PHONY	:	all re clean fclean test