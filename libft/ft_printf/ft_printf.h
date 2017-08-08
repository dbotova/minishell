/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printh.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 23:32:32 by dz                #+#    #+#             */
/*   Updated: 2017/08/06 23:32:33 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include "../str/str.h"
# include "../mem/mem.h"
# define ABS(x) (x < 0) ? (-x) : (x)
# define MIN(x, y) (x < y) ? (x) : (y)
# define MAX(x, y) (x > y) ? (x) : (y)
# define ROUND(x) (unsigned long long)(x + 5)
# define SPECS "sSpdDioOuUxXcCfF%"
# define STR "sSpdDioOuUxXcC +-.0123456789zlhj#%*L'"
# define FLAGS "+-.0123456789zlhj#* L'"
# define SMART_FREE(x) {free(x); x = NULL;}

union					u_types
{
	char				*s;
	char				c;
	int					d;
	int					is_digit;
	intmax_t			ix;
	unsigned int		u;
	unsigned long		ul;
	long long			ll;
	long				l;
	unsigned long long	ull;
	long long			p;
	char				ar[2];
	unsigned char		uc;
	unsigned short		us;
	wchar_t				*ws;
	wchar_t				wc;
	double				f;
	long double			lf;
};

typedef struct			s_flags
{
	int					is_hash;
	int					width;
	int					is_dot;
	int					is_minus;
	int					is_plus;
	int					is_zero;
	int					cutoff;
	int					is_l;
	int					is_j;
	int					is_space;
	int					is_h;
	int					is_o;
	int					is_z;
	int					is_cl;
	int					is_separete;
	char				*target;
}						t_flags;

int						ft_printf(char *args, ...);
char					*ft_ftoa_precision(long double n, int precision);
char					*ft_ltoa_base(long long n, int base);
char					*ft_ultoa_base(unsigned long long nb, int base);
int						ft_nbrsize(long n);
t_flags					*ft_newflagslst();
char					*ft_getflags(char *ptr, t_flags **flags, va_list ap);
void					ft_create_jump_table(int(*jump_table[])(va_list,
						union u_types, t_flags*));
int						ft_float_print(va_list ap, union u_types tp,
						t_flags *flags);
char					*ft_num_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_char_read(char *target, t_flags *flags,
						char **prefix, char **width);
wchar_t					*ft_wchar_read(wchar_t *target, t_flags *flags,
						char **prefix, char **width);
wchar_t					*ft_wstr_read(wchar_t *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_str_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_undef_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_hex_read(t_flags *flags,
						char **prefix, char **width, char *hash);
char					*ft_float_read(char *target, t_flags *flags,
						char **prefix, char **width);
char					*ft_pointer_read(char *target, t_flags *flags,
						char **prefix, char **width);
int						ft_octa_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cocta_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_int_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cint_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_hex_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_chex_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_unsigned_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cunsigned_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_str_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cstr_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_pointer_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_char_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_cchar_print(va_list ap, union u_types tp,
						t_flags *flags);
int						ft_print(union u_types tp, t_flags *flags);
int						ft_undef_print(char *ptr, t_flags *flags);

#endif
