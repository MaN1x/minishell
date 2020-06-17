/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:55:16 by mjoss             #+#    #+#             */
/*   Updated: 2019/09/17 22:13:15 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;

	if (!lst || !f)
		return (0);
	if (!(new_list = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new_list = f(new_list);
	if (lst->next)
		new_list->next = ft_lstmap(lst->next, f);
	return (new_list);
}
