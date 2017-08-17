/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 19:49:25 by dz                #+#    #+#             */
/*   Updated: 2017/08/06 19:49:26 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLLIST_H
# define DLLIST_H
# include <stddef.h>

typedef	struct			s_dlist
{
	void				*content;
	size_t				content_size;
	struct s_dlist		*next;
	struct s_dlist		*prev;
}						t_dlist;

# include "../mem/mem.h"

t_dlist					*ft_dlstnew(void const *content, size_t content_size);
void					ft_dlstdelone(t_dlist **alst, void (*del)(void*, size_t));
void					ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void					ft_dlstadd(t_dlist **alst, t_dlist *new);
void					ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
t_dlist					*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem));
void					ft_ddel(void *data, size_t size);

#endif