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
# include "../libft.h"
# include "../queue/queue.h"

typedef struct			s_hashtable
{
	t_dlist				**data;
	unsigned int 		size;
}						t_hashtable;

void					hashtable(t_hashtable **table, size_t size);
void					htable_add(t_hashtable *table, void *object,
						unsigned int size, void (*hash)(void *, size_t));
void					htable_remove(t_hashtable *table, void *object,
						size_t size);
int						htable_has_key(t_hashtable *table, unsigned int key);
int						htable_has_object(t_hashtable *table, void *object);
void					htable_clear(t_hashtable *table);

#endif
