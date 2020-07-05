/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tilda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 21:16:11 by maxim             #+#    #+#             */
/*   Updated: 2020/07/04 21:01:54 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse.h"
#include "../libft/libft.h"

static char	*find_in_env(char *name, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (!ft_strncmp(name, env[i], ft_strlen(name)))
		{
			while (env[i][j] != '=')
				j++;
			return &env[i][++j];
		}
		i++;
	}
	return NULL;
}

void	parse_tilda(t_command *command, char **env)
{
	int		i;
	char	*home;
	char	*tmp;

	i = 0;
	while (command->args[i])
	{
		if (command->args[i][0] == '~' && ((!command->args[i][1] || command->args[i][1] == '/')))
		{
			if ((home = find_in_env("HOME", env)))
			{
				tmp = ft_strjoin(home, &command->args[i][1]);
				free(command->args[i]);
				command->args[i] = tmp;
			}
		}
		i++;
	}
}
