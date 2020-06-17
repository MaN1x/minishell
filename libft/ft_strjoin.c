/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:53:00 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/17 19:10:43 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (s1 && s2)
	{
		tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (tmp)
		{
			ft_strcat(tmp, s1);
			ft_strcat(tmp, s2);
			return (tmp);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
