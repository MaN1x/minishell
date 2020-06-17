/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelspcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 02:56:50 by maxim             #+#    #+#             */
/*   Updated: 2020/05/19 03:16:47 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int spcs_len(char *str)
{
	int len;

	len = 0;
	while (ft_isspace(str[len]))
		len++;
	return (len);
}

char	*ft_strdelspcs(char *str)
{
	if (str)
	{
		
	}
}
