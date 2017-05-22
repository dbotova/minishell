/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_wrap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:01:41 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/21 16:01:43 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_WRAP_H
# define ARRAY_WRAP_H
# include "../libft.h"
# define SIZE_BLOCK 100

typedef struct	s_array_wrap
{
	char		**data;
	size_t		size;
	size_t		used;
}				t_array_wrap;

void			init_array(t_array_wrap **array, size_t size);
t_array_wrap	*realloc_array(t_array_wrap *old_array, size_t new_size);
void			free_array(t_array_wrap *array);
void			add_element(t_array_wrap *array, char *new_item);
void			edit_element(t_array_wrap *array, char *item, char *value, char symb);
size_t			find_element(t_array_wrap *array, char *item, size_t len, char symb);
void			print_elements(t_array_wrap *array);
void			delete_element(t_array_wrap *array, char *element);
void			copy_array(t_array_wrap *array, char **elements);
void			copy_array(t_array_wrap *array, char **elements);

#endif
