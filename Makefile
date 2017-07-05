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

OBJS =	main.o \
		ft_setenv.o \
		ft_unsetenv.o \
		ft_cd.o \
		ft_echo.o

LIBFT = ./libft/libft.a

LIBS= $(LIBFT)

HEADERS = minishell.h ./libft/libft.h

#CFLAGS += -Wall -Werror -Wextra -g -O0
CFLAGS += -g -O0

NAME = minishell

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJ): $(HEADERS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean: 
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all
