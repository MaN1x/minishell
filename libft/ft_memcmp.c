/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:45:18 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/07 18:44:18 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *((unsigned char*)s1) == *((unsigned char*)s2))
	{
		s1++;
		s2++;
	}
	return ((*(unsigned char*)s1) - *((unsigned char*)s2));
}
