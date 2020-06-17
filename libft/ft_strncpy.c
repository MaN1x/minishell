/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:12:21 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/07 20:45:17 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*tmp;

	tmp = dst;
	while (len)
	{
		if (*src)
		{
			*dst = *src;
			src++;
		}
		else
			*dst = '\0';
		dst++;
		len--;
	}
	return (tmp);
}
