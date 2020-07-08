/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameter_extension.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:58:55 by maxim             #+#    #+#             */
/*   Updated: 2020/07/05 17:34:11 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft.h"

static char	*replace_ex(char *command, char *envp, int start)
{
	char	*new_arg;
	char	*tmp;

	(command)[start] = 0;
	tmp = ft_strjoin(command, ft_strstr(envp, "=") + 1);
	new_arg = ft_strjoin(tmp, &((command)[start + ft_strlen(envp) -
								ft_strlen(ft_strstr(envp, "=")) + 1]));
	free(tmp);
	return (new_arg);
}

static char	*find_and_replace_ex(char *str, char **envp)
{
	int	j;
	int	k;
	int	len;

	j = 0;
	k = 0;
	len = 0;
	while ((str)[j] && (str)[j] != '$')
		j++;
	if ((str)[j] == '$')
		while (envp[k])
		{
			while (envp[k][len] != '=')
				len++;
			if (ft_strncmp(&((str)[j + 1]), envp[k], len) == 0)
			{
				return (replace_ex(str, envp[k], j));
			}
			len = 0;
			k++;
		}
	return (0);
}

void		parse_parameter_extension(t_command *command, char **envp)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (command->args[i])
	{
		while (command->args[i][j])
		{
			if ((tmp = find_and_replace_ex((command->args[i]), envp)))
			{
				free(command->args[i]);
				command->args[i] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
