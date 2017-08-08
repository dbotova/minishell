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
# include "../libft.h"

typedef	struct			s_queue
{
	void				*content;
	size_t				content_size;
	struct s_queue		*next;
	struct s_queue		*last;
}						t_queue;

t_queue					ft_enqueue(t_queue *queue, void const content, size_t size);
t_queue					ft_dequeue(t_queue *queue);
t_queue					ft_peek(t_queue *queue);
int						ft_empty(t_queue *queue);

#endif
