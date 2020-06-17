/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:27:34 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/07 17:41:17 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*((unsigned char*)s) == (unsigned char)c)
			return ((void*)s);
		s++;
		n--;
	}
	return (NULL);
}
