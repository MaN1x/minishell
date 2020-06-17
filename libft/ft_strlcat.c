/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:04:20 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/08 23:00:01 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < size)
		i++;
	while (i < size)
	{
		if (i == size - 1 || *src == '\0')
		{
			dst[i] = '\0';
			break ;
		}
		else
		{
			dst[i] = *src;
			src++;
		}
		i++;
	}
	return (i + ft_strlen(src));
}
