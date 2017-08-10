/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:43:03 by dbotova           #+#    #+#             */
/*   Updated: 2017/08/08 14:43:05 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include "../llist/llist.h"
# include "../libft.h"

typedef	struct			s_queue
{
	struct s_list		*front;
	struct s_list		*last;
}						t_queue;

void					ft_enqueue(t_queue *queue, void *content,
						size_t size);
t_list					*ft_dequeue(t_queue *queue);
t_list					*ft_peek(t_queue *queue);
int						ft_qempty(t_queue *queue);
t_queue					*init_queue();

#endif
