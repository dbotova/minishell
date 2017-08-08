/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 19:57:59 by dz                #+#    #+#             */
/*   Updated: 2017/08/06 19:58:00 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../libft.h"

t_list	*ft_pop(t_list **list);
void	ft_push(t_list **list, void *item, size_t size);
int		ft_empty(t_list *list);
t_list	*ft_stacktop(t_list *list);

#endif
