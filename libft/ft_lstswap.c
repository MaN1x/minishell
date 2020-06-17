/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:53:44 by mjoss             #+#    #+#             */
/*   Updated: 2019/12/02 20:51:57 by mjoss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list **head, t_list *lst1, t_list *lst2)
{
	t_list *prev_list;

	if (*head != lst1)
	{
		prev_list = *head;
		while (prev_list->next != lst1)
			prev_list = prev_list->next;
		prev_list->next = lst2;
		lst1->next = lst2->next;
		lst2->next = lst1;
	}
	else
	{
		lst1->next = lst2->next;
		lst2->next = lst1;
		*head = lst2;
	}
}
