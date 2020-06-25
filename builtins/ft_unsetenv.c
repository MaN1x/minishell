/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:43:39 by maxim             #+#    #+#             */
/*   Updated: 2020/06/25 00:32:28 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../libft/libft.h"
#include <stdlib.h>

static int	check_valid(char *arg)
{
	while (*arg && *arg != '=')
		arg++;
	if (*arg == '=')
		return (0);
	else
		return (1);
}

void 		ft_unsetenv(t_command command, char ***envp)
{
	int 	i;
	int 	j;
	int 	len;
	char	**new_env;

	i = 0;
	j = 0;
	len = 0;
	if (check_valid(command.args[1]))
	{
		while ((*envp)[i] && ft_strncmp((*envp)[i], command.args[1], ft_strlen(command.args[1])))
			i++;
		if ((*envp)[i])
		{
			while ((*envp)[len])
				len++;
			new_env = (char**)malloc(len * sizeof(char*));
			new_env[len - 1] = 0;
			while (j != i)
			{
				new_env[j] =  ft_strdup((*envp)[j]);
				free((*envp)[j]);
				j++;
			}
			free((*envp)[i++]);
			while ((*envp)[i])
			{
				new_env[j] = ft_strdup((*envp)[i]);
				free((*envp)[i]);
				i++;
				j++;
			}
			free(*envp);
			*envp = new_env;
		}
	}
}
