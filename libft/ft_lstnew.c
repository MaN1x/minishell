/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:47:01 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/15 22:27:29 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(node->content = malloc(content_size)))
		{
			free(node);
			return (NULL);
		}
		ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
		node->next = NULL;
	}
	else
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
	}
	return (node);
}
