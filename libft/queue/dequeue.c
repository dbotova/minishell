/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:44:04 by dbotova           #+#    #+#             */
/*   Updated: 2017/08/08 14:44:05 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_list	*ft_dequeue(t_queue *queue)
{
	t_list *item;

	item = NULL;
	if (!ft_qempty(queue))
	{
		item = queue->front;
		queue->front = queue->front->next;
	}
	return (item);
}
