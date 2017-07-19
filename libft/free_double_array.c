/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 21:45:21 by dz                #+#    #+#             */
/*   Updated: 2017/07/18 21:45:22 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_double_array(char **array)
{
   int i;

   i = 0;
   if (!array)
      return ;
   while (array[i])
   {
      SMART_FREE(array[i]);
      i++;
   }
   SMART_FREE(array);
}
