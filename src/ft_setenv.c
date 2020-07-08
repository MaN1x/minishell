/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:33:55 by maxim             #+#    #+#             */
/*   Updated: 2020/07/05 19:27:14 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

static void		free_envp(char ***envp)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *envp;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

static	char	**env_extend(char **envp, char *new_var)
{
	int		len;
	char	**new_envp;

	len = 0;
	while (envp[len])
		len++;
	new_envp = (char**)malloc((len + 2) * sizeof(char*));
	len = 0;
	while (envp[len])
	{
		new_envp[len] = ft_strdup(envp[len]);
		len++;
	}
	new_envp[len] = ft_strdup(new_var);
	new_envp[len + 1] = 0;
	return (new_envp);
}

void		ft_setenv(t_command command, char ***envp)
{
	int		i;
	int		len;
	char	**new_envp;

	i = 0;
	len = 0;
	while (command.args[1][len] != '=' && command.args[1][len])
		len++;
	if (command.args[1][len] != '=')
		return ;
	while ((*envp)[i] && ft_strncmp((*envp)[i], command.args[1], len))
		i++;
	if ((*envp)[i])
	{
		free((*envp)[i]);
		(*envp)[i] = ft_strdup(command.args[1]);
	}
	else
	{
		new_envp = env_extend(*envp, command.args[1]);
		free_envp(envp);
		*envp = new_envp;
	}
}
