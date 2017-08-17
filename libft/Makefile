# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbotova <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 16:50:27 by dbotova           #+#    #+#              #
#    Updated: 2016/09/26 16:50:34 by dbotova          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF =		./ft_printf
ARRAY =			./array_wrap
LLIST =			./llist
PPATH =			./$(PRINTF)/print
RPATH =			./$(PRINTF)/read
UPATH =			./$(PRINTF)/util
STACK =			./stack
STR =			./str
MEM =			./mem
QUEUE =			./queue
HASHTABLE =		./hashtable

HEADERS =	libft.h $(LLIST)/llist.h $(STACK)/stack.h $(STR)/str.h 			\
			$(MEM)/mem.h $(PRINTF)/ft_printf.h $(QUEUE)/queue.h 			\
			$(HASHTABLE)/hashtable.h

SRC =	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c					\
		ft_isdigit.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_itoa.c		\
		$(LLIST)/ft_lstadd.c $(LLIST)/ft_lstdel.c $(LLIST)/ft_lstdelone.c 	\
		$(LLIST)/ft_lstiter.c $(LLIST)/ft_lstmap.c	$(LLIST)/ft_list_last.c	\
		$(LLIST)/ft_lstnew.c $(LLIST)/ft_del.c											\
		$(MEM)/ft_memalloc.c $(MEM)/ft_memccpy.c $(MEM)/ft_bzero.c			\
		$(MEM)/ft_memchr.c $(MEM)/ft_memcmp.c $(MEM)/ft_memset.c			\
		$(MEM)/ft_memcpy.c $(MEM)/ft_memdel.c $(MEM)/ft_memmove.c  			\
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c			\
		ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c $(STR)/ft_strcat.c 		\
		$(STR)/ft_strchr.c	$(STR)/ft_strcpy.c $(STR)/ft_strdel.c 			\
		$(STR)/ft_strclr.c $(STR)/ft_strcmp.c  $(STR)/ft_strdup.c			\
		$(STR)/ft_strequ.c $(STR)/ft_striter.c $(STR)/ft_striteri.c 		\
		$(STR)/ft_strjoin.c $(STR)/ft_strlcat.c	$(STR)/ft_strnstr.c 		\
		$(STR)/ft_strlen.c $(STR)/ft_strmap.c $(STR)/ft_strmapi.c 			\
		$(STR)/ft_strncat.c $(STR)/ft_strncmp.c	$(STR)/ft_strrchr.c			\
		$(STR)/ft_strncpy.c $(STR)/ft_strnequ.c $(STR)/ft_strnew.c 			\
		$(STR)/ft_strsplit.c $(STR)/ft_strstr.c $(STR)/ft_strsub.c 			\
		$(STR)/ft_strtrim.c ft_tolower.c $(STR)/ft_strlowcase.c 			\
		$(STR)/ft_strupcase.c 												\
		ft_toupper.c ft_putchar.c free_double_array.c						\
		get_next_line.c ft_ftoa_precision.c ft_getnum.c ft_ltoa_base.c 		\
		ft_nbrsize.c ft_power.c ft_putnstr.c ft_putwchar.c ft_putwstr.c 	\
		ft_ultoa_base.c ft_wcharlen.c ft_wstrlen.c ft_num_separete.c 		\
		$(PRINTF)/ft_printf.c 												\
		$(PPATH)/ft_cchar_print.c $(PPATH)/ft_char_print.c 					\
		$(PPATH)/ft_chex_print.c $(PPATH)/ft_cint_print.c 					\
		$(PPATH)/ft_cocta_print.c $(PPATH)/ft_cstr_print.c 					\
		$(PPATH)/ft_cunsigned_print.c $(PPATH)/ft_float_print.c 			\
		$(PPATH)/ft_hex_print.c $(PPATH)/ft_int_print.c 					\
		$(PPATH)/ft_octa_print.c $(PPATH)/ft_pointer_print.c 				\
		$(PPATH)/ft_print.c $(PPATH)/ft_str_print.c  						\
		$(PPATH)/ft_unsigned_print.c $(PPATH)/ft_undef_print.c				\
		$(RPATH)/ft_char_read.c $(RPATH)/ft_float_read.c  					\
		$(RPATH)/ft_num_read.c $(RPATH)/ft_pointer_read.c 					\
		$(RPATH)/ft_undef_read.c $(RPATH)/ft_wchar_read.c 					\
		$(RPATH)/ft_wstr_read.c $(RPATH)/ft_hex_read.c						\
		$(UPATH)/ft_create_jump_table.c $(UPATH)/ft_getflags.c 				\
		$(UPATH)/ft_newflagslst.c $(RPATH)/ft_str_read.c ft_itoa_base.c 	\
		get_next_word.c ft_hash.c  											\
		$(ARRAY)/copy_array.c $(ARRAY)/delete_element.c 					\
		$(ARRAY)/edit_element.c $(ARRAY)/find_element.c 					\
		$(ARRAY)/free_array.c $(ARRAY)/init_array.c 						\
		$(ARRAY)/print_elements.c $(ARRAY)/realloc_array.c 					\
		$(ARRAY)/str_to_array.c $(ARRAY)/add_element.c						\
		$(STR)/ft_strtrimchr.c  											\
		$(STACK)/stacktop.c $(STACK)/empty.c $(STACK)/pop.c $(STACK)/push.c \
		$(QUEUE)/peek.c $(QUEUE)/qempty.c $(QUEUE)/enqueue.c 		\
		$(QUEUE)/dequeue.c $(QUEUE)/init_queue.c

OBJ = 	ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o			\
		ft_isdigit.o ft_isprint.o ft_ispunct.o ft_isspace.o ft_itoa.o		\
		ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o		\
		ft_lstnew.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o		\
		ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o		\
		ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o			\
		ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o	\
		ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o			\
		ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o	\
		ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o		\
		ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o		\
		ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o		\
		ft_toupper.o ft_strlowcase.o ft_strupcase.o ft_list_last.o 			\
		get_next_line.o ft_ftoa_precision.o ft_getnum.o ft_ltoa_base.o 		\
		ft_nbrsize.o ft_power.o ft_putnstr.o ft_putwchar.o ft_putwstr.o 	\
		ft_ultoa_base.o ft_wcharlen.o ft_wstrlen.o ft_num_separete.o 		\
		ft_printf.o	ft_cchar_print.o ft_char_print.o ft_chex_print.o 		\
		ft_cint_print.o ft_cocta_print.o ft_cstr_print.o   					\
		ft_float_print.o ft_hex_print.o ft_int_print.o ft_octa_print.o 		\
		ft_pointer_print.o ft_print.o ft_str_print.o ft_undef_print.o 		\
		ft_unsigned_print.o ft_char_read.o ft_float_read.o ft_hex_read.o 	\
		ft_num_read.o ft_pointer_read.o ft_str_read.o ft_undef_read.o 		\
		ft_wchar_read.o ft_wstr_read.o ft_ftoa_precision.o ft_getnum.o 		\
		ft_ltoa_base.o ft_cunsigned_print.o ft_nbrsize.o ft_power.o 		\
		ft_putnstr.o ft_putwchar.o ft_putwstr.o ft_ultoa_base.o 			\
		ft_wcharlen.o ft_wstrlen.o ft_create_jump_table.o ft_getflags.o 	\
		ft_newflagslst.o ft_num_separete.o ft_itoa_base.o get_next_word.o 	\
		ft_hash.o add_element.o copy_array.o delete_element.o 				\
		edit_element.o find_element.o free_array.o init_array.o 			\
		print_elements.o realloc_array.o ft_strtrimchr.o str_to_array.o 	\
		free_double_array.o ft_del.o										\
		stacktop.o empty.o pop.o push.o peek.o qempty.o enqueue.o 	\
		dequeue.o init_queue.o

NAME = libft.a

CFLAGS += -Wall -Werror -Wextra -g -c -O0 -I.

all: $(NAME)

$(OBJ): $(HEADERS)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
