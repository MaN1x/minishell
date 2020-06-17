/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:51:59 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/14 20:25:14 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = 0;
	if (dst != NULL || src != NULL)
	{
		if (dst < src)
			while (i < len)
			{
				((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
				i++;
			}
		else
		{
			while (len)
			{
				((unsigned char*)dst)[len - 1] = ((unsigned char*)src)[len - 1];
				len--;
			}
		}
	}
	return (dst);
}
