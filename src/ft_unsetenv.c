/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:43:39 by maxim             #+#    #+#             */
/*   Updated: 2020/07/05 20:47:10 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
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

static void	cpy_env(char ***new_en, int sep, char ***envp)
{
	int		j;
	char	**new_env;

	new_env = *new_en;
	j = 0;
	while (j != sep)
	{
		new_env[j] = ft_strdup((*envp)[j]);
		free((*envp)[j]);
		j++;
	}
	free((*envp)[sep++]);
	while ((*envp)[sep])
	{
		new_env[j] = ft_strdup((*envp)[sep]);
		free((*envp)[sep]);
		sep++;
		j++;
	}
	free(*envp);
}

void		ft_unsetenv(t_command command, char ***envp)
{
	int		i;
	int		len;
	char	**new_env;

	i = 0;
	len = 0;
	if (check_valid(command.args[1]))
	{
		while ((*envp)[i] && ft_strncmp((*envp)[i], command.args[1],
												ft_strlen(command.args[1])))
			i++;
		if ((*envp)[i])
		{
			while ((*envp)[len])
				len++;
			new_env = (char**)malloc(len * sizeof(char*));
			new_env[len - 1] = 0;
			cpy_env(&new_env, i, envp);
			*envp = new_env;
		}
	}
}
