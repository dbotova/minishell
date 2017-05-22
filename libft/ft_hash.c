/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 16:55:07 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/21 16:55:09 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int mix(unsigned int internal_state, unsigned int message_block)
{
   return (internal_state * message_block) ^
          ((internal_state << 3) + (message_block >> 2));
}

unsigned int hash(char *message, size_t message_length)
{
	unsigned int internal_state = MAGIC_NUMBER;
	unsigned int message_block = 0;

	while (message_length >= 4)
	{
		memcpy(&message_block, message, sizeof(unsigned int));

		internal_state = mix(message_block, internal_state);
		message_length -= sizeof(unsigned int);
		message        += sizeof(unsigned int);
	}

	if (message_length)
	{
		memcpy(&message_block, message, message_length);
		internal_state = mix(message_block, internal_state);
	}

	return internal_state % 10;
}
