/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:40:23 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/17 19:10:25 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (s)
	{
		new = ft_strnew(len);
		if (new)
		{
			while (len--)
				new[len] = s[start + len];
			return (new);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
