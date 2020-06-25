/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_massdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:15:46 by maxim             #+#    #+#             */
/*   Updated: 2020/06/21 17:17:41 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_massdup(char **mass)
{
	int		len;
	char	**new_mass;

	len = 0;
	while (mass[len])
		len++;
	new_mass = (char**)malloc((len + 1) * sizeof(char*));
	len = 0;
	while (mass[len])
	{
		new_mass[len] = ft_strdup(mass[len]);
		len++;
	}
	new_mass[len] = 0;
	return (new_mass);
}
