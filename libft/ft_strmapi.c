/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:11:32 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/17 19:09:38 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char ((*f)(unsigned int, char)))
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		new = ft_strnew(ft_strlen(s));
		if (new)
		{
			while (s[i])
			{
				new[i] = f(i, s[i]);
				i++;
			}
			return (new);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
