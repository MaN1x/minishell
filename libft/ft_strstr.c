/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:43:58 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/10 18:10:06 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			while ((haystack[i] == needle[i]) && needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char*)haystack);
			else
				i = 0;
		}
		haystack++;
	}
	return (NULL);
}
