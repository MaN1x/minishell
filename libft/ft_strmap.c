/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:03:18 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/17 20:41:27 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*tmp;

	if (s && f)
	{
		new = ft_strnew(ft_strlen(s));
		tmp = new;
		if (new)
		{
			while (*s)
			{
				*new = f(*s);
				s++;
				new++;
			}
			return (tmp);
		}
	}
	return (NULL);
}
