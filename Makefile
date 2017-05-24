# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbotova <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/23 15:32:55 by dbotova           #+#    #+#              #
#    Updated: 2017/05/23 15:32:56 by dbotova          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS =	main.o

LIBS = ./libft/libft.a

HEADERS = minishell.h ./libft/libft.h

CFLAGS += -Wall -Werror -Wextra -g -ggdb

NAME = minishell

all: $(NAME)

$(OBJ): $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
