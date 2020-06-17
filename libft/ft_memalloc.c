/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:14:56 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/10 22:27:17 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if ((tmp = malloc(size)) && size)
	{
		while (size--)
			((unsigned char*)tmp)[size] = 0;
		return (tmp);
	}
	else
		return (0);
}
