/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:32:28 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/08 23:56:17 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	if ((unsigned char)c == '\0')
		while (*s)
		{
			s++;
			i++;
		}
	while (i-- && *((unsigned char*)s) != (unsigned char)c)
		s--;
	if ((unsigned char)c == *((unsigned char*)s))
		return ((char*)s);
	else
		return (NULL);
}
