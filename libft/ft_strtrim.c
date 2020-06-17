/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:22:52 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/17 21:08:09 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if ((i = ft_strlen(s)) != 0)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
			i--;
		if (!(new = ft_strnew(i + 1)))
			return (NULL);
		new = ft_strncat(new, s, i + 1);
		return (new);
	}
	else
	{
		if (!(new = (char*)malloc(sizeof(char))))
			return (NULL);
		*new = '\0';
		return (new);
	}
	return (NULL);
}
