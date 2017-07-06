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

#BUILDINS = buildins
#SRC =	main.c						\
		$(BUILDINS)/ft_setenv.c 	\
		$(BUILDINS)/ft_unsetenv.c 	\
		$(BUILDINS)/ft_cd.c 		\
		$(BUILDINS)/ft_echo.c 		\
		$(BUILDINS)/ft_exit.c
OBJS =	main.o 						\
		ft_setenv.o 	\
		ft_unsetenv.o 	\
		ft_cd.o 		\
		ft_echo.o 		\
		ft_exit.o

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
