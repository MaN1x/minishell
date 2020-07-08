/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 20:00:24 by maxim             #+#    #+#             */
/*   Updated: 2020/07/08 03:49:04 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>
#include "minishell.h"
#include "libft.h"

static void	parse_cd(t_command *command, char **envp)
{
	if (command->args[1] && *(command->args[1]) == '-')
	{
		free(command->args[1]);
		if (find_in_env("OLDPWD", envp))
			command->args[1] = ft_strdup(find_in_env("OLDPWD", envp));
		else
			command->args[1] = ft_strdup(".");
	}
	if (!command->args[1])
	{
		free(command->args[0]);
		free(command->args[1]);
		free(command->args);
		command->args = (char**)malloc(3 * sizeof(char*));
		command->args[0] = ft_strdup("cd");
		command->args[2] = 0;
		if (find_in_env("HOME", envp))
			command->args[1] = ft_strdup(find_in_env("HOME", envp));
		else
			command->args[1] = ft_strdup(".");
	}
}

static int	err(t_command *command)
{
	if (access(command->args[1], F_OK))
	{
		print_err(*command, "No such file or directory");
		return (0);
	}
	if (access(command->args[1], R_OK))
	{
		print_err(*command, "Permission denied");
		return (0);
	}
	if (chdir(command->args[1]) == -1)
	{
		print_err(*command, "Not a directory");
		return (0);
	}
	return (1);
}

void		ft_cd(t_command *command, char ***envp)
{
	char		*key;
	char		*full_path;
	char		*prev_path;

	parse_cd(command, *envp);
	if (!(full_path = ft_strnew(MAXPATHLEN)))
		ft_putendl("malloc err");
	getcwd(full_path, MAXPATHLEN);
	if ((err(command)) == 0)
	{
		free(full_path);
		return ;
	}
	if (!(key = ft_strjoin("PWD=", full_path)))
		ft_putendl("malloc err");
	prev_path = ft_strjoin("OLDPWD=", full_path);
	free(full_path);
	free(command->args[1]);
	command->args[1] = prev_path;
	ft_setenv(*command, envp);
	free(command->args[1]);
	command->args[1] = key;
	ft_setenv(*command, envp);
}
