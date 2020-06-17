/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:13:03 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/14 21:45:35 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*mem(int n, int *size)
{
	char	*nbr;

	*size = 0;
	if (n <= 0)
		*size = *size + 1;
	while (n)
	{
		n /= 10;
		*size = *size + 1;
	}
	nbr = ft_strnew(*size);
	if (nbr)
		return (nbr);
	else
		return (NULL);
}

char		*ft_itoa(int n)
{
	long	buf;
	char	*out;
	int		size;

	buf = n;
	if (!(out = mem(n, &size)))
		return (NULL);
	out[0] = '0';
	if (buf < 0)
	{
		out[0] = '-';
		buf *= -1;
	}
	while (buf)
	{
		out[size - 1] = buf % 10 + '0';
		buf /= 10;
		size--;
	}
	return (out);
}
