/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 15:34:30 by dz                #+#    #+#             */
/*   Updated: 2017/08/15 15:34:32 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

typedef struct	s_hashtable
{
	t_list		*data;
	int 		size;
}				t_hashtable;

void			hashtable(t_hashtable **table, int size);
void			htable_add(t_hashtable *table, void *object, size_t size);
void			htable_remove(t_hashtable *table, void *object);
int				htable_has_key(t_hashtable *table, int key);
int				htable_has_object(t_hashtable *table, void *object);
int				htable_clear(t_hashtable *table);

#endif
