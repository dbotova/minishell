/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacktop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 21:11:26 by dz                #+#    #+#             */
/*   Updated: 2017/08/06 21:11:27 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*ft_stacktop(t_list *list)
{
	t_list *top;

	top = NULL;
	if (!ft_empty(list))
	{
		top = ft_pop(&list);
		ft_push(&list, top->content, top->content_size);
	}
	return (top);
}