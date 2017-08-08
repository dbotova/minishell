/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dz <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 23:07:49 by dz                #+#    #+#             */
/*   Updated: 2017/08/06 23:07:50 by dz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H
# include "../libft.h"

void					ft_bzero(void *pointer, int length);
void					*ft_memset (void *ptr, int value, size_t num);
void					*ft_memcpy(void *str1, const void *str2, size_t n);
void					*ft_memccpy(void *str1, const void *str2, int c,
								size_t n);
void					*ft_memmove(void *str1, const void *str2, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);

#endif
