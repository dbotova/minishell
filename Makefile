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

BUILTINS = builtins
LIB = lib

OBJS =	main.o 						\
		$(BUILTINS)/ft_setenv.o 	\
		$(BUILTINS)/ft_unsetenv.o 	\
		$(BUILTINS)/ft_cd.o 		\
		$(BUILTINS)/ft_echo.o 		\
		$(BUILTINS)/ft_exit.o 		\
		$(BUILTINS)/ft_run.o 		\
		$(LIB)/ft_getenv.o 			\
		$(LIB)/ft_chkpermission.o 	\
		$(LIB)/ft_get_full_path.o

LIBFT = ./libft/libft.a

LIBS= $(LIBFT)

HEADERS = minishell.h ./libft/libft.h

CFLAGS += -Wall -Werror -Wextra -g -O0
#CFLAGS += -g -O0 -I.

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
