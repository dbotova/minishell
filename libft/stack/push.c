/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 21:11:10 by dz                #+#    #+#             */
/*   Updated: 2017/08/06 21:11:12 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_push(t_list **list, void *item, size_t size)
{
	t_list *new_item;

	new_item = NULL;
	new_item = ft_lstnew(item, size);
	ft_lstadd(list, new_item);
}