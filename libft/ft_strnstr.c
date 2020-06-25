/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:13:41 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/14 21:38:11 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	eq(const char *haystack, const char *needle, size_t len)
{
	while (*haystack == *needle && *needle && len)
	{
		haystack++;
		needle++;
		len--;
	}
	if (*needle == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack && len)
	{
		if (eq(haystack, needle, len) == 1)
			return ((char*)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
