/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:59:13 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/10 19:41:10 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *((unsigned char*)s1) == *((unsigned char*)s2) &&
			n - 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}
