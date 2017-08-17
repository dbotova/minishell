/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 19:16:14 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/23 19:30:55 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <stdint.h>
# include <float.h>
# include <limits.h>
# include "./ft_printf/ft_printf.h"
# include "./array_wrap/array_wrap.h"
# include "./llist/llist.h"
# include "./stack/stack.h"
# include "./str/str.h"
# include "./mem/mem.h"
# include "./queue/queue.h"
# include "./hashtable/hashtable.h"
# define BUFF_SIZE 100
# define ABS(x) (x < 0) ? (-x) : (x)
# define MIN(x, y) (x < y) ? (x) : (y)
# define MAX(x, y) (x > y) ? (x) : (y)
# define ROUND(x) (unsigned long long)(x + 5)
# define SPECS "sSpdDioOuUxXcCfF%"
# define STR "sSpdDioOuUxXcC +-.0123456789zlhj#%*L'"
# define FLAGS "+-.0123456789zlhj#* L'"
# define SMART_FREE(x) {free(x); x = NULL;}
# define MAGIC_NUMBER 42
# define SIZE_BLOCK 100

typedef struct			s_file
{
	int					fd;
	char				*buf;
	struct s_file		*next;
}						t_file;

unsigned int 			ft_hash(char *message, size_t message_length);
char					*ft_ltoa_base(long long n, int base);
int						get_next_line(const int fd, char **line);
int						get_next_word(const char *line, char **word);
int						ft_atoi(char *str);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_ispunct(int c);
void					ft_putchar(int c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
char					*ft_itoa(int n);
char					*ft_itoa_base(int n, int base);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
int						ft_getnum(char *str, int *value);
void					ft_putwchar(wchar_t chr);
void					ft_putwstr(wchar_t *str, size_t size);
size_t					ft_wstrlen(wchar_t *str);
size_t					ft_wcharlen(wchar_t c);
char					*ft_num_separete(char *str);
unsigned int			ft_power(int n, int pow);
void					ft_putlnbr(unsigned int nb);
void					ft_putnstr(char const *s, int n);
char					*ft_ftoa_precision(long double n, int precision);
char					*ft_ultoa_base(unsigned long long nb, int base);
int						ft_nbrsize(long n);
void					free_double_array(char **array);

#endif
