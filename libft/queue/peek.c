/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:44:12 by dbotova           #+#    #+#             */
/*   Updated: 2017/08/08 14:44:14 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_list	*ft_peek(t_queue *queue)
{
	t_list *first;

	first = NULL;
	if (!ft_qempty(queue))
	{
		first = ft_dequeue(queue);
		ft_enqueue(queue, first->content, first->content_size);
	}
	return (first);
}
