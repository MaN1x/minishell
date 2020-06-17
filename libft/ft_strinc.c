/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:11:12 by maxim             #+#    #+#             */
/*   Updated: 2020/05/05 22:47:04 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strinc(char **str)
{
	char *new_str;

	if (!(new_str = ft_strnew(ft_strlen(*str) * 2)))
		return (new_str);
	ft_strcpy(new_str, *str);
	free(*str);
	return (new_str);
}
