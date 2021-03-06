/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 13:13:28 by dbotova           #+#    #+#             */
/*   Updated: 2016/10/02 13:13:29 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dllist.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem))
{
	while (lst && *f)
	{
		f(lst);
		lst = lst->next;
	}
}
