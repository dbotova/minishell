/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 21:11:17 by dz                #+#    #+#             */
/*   Updated: 2017/08/06 21:11:18 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		ft_empty(t_list *list)
{
	if (!list)
		return (1);
	return (0);
}