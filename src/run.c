/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:48:00 by maxim             #+#    #+#             */
/*   Updated: 2020/07/05 21:16:27 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "minishell.h"
#include "libft.h"

static char	*join_path(char *path, char *name)
{
	char	*full_path;
	char	*tmp;

	if (!(tmp = ft_strjoin(path, "/")))
		return (0);
	if (!(full_path = ft_strjoin(tmp, name)))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (full_path);
}

static char	*check_dir(char *dir, char *name)
{
	char	*current_dir;

	if (*name != '/')
	{
		if (!(current_dir = join_path(dir, name)))
			ft_putstr("malloc error");
	}
	else
		current_dir = ft_strdup(name);
	if (access(current_dir, X_OK) == 0)
		return (current_dir);
	else
	{
		free(current_dir);
		return (0);
	}
}

static char	*find_in_path(t_command command, char **envp)
{
	char	*current_dir;
	char	**dirs;
	int		i;

	i = 0;
	current_dir = 0;
	while (*envp && ft_strncmp(*envp, "PATH", 4))
		envp++;
	if (*envp == NULL)
		return (0);
	if ((dirs = ft_strsplit(*envp + 5, ':')) == NULL)
		ft_putstr("malloc error\n");
	while (dirs[i] && !(current_dir = check_dir(dirs[i], command.args[0])))
		i++;
	i = 0;
	while (dirs[i])
		free(dirs[i++]);
	free(dirs);
	return (current_dir);
}

static void	run_bin(t_command command, char **envp)
{
	pid_t	pid;
	char	*bin_file;

	if (command.args[0] == 0)
		return ;
	if ((bin_file = find_in_path(command, envp)))
		;
	else if (!(bin_file = check_dir(".", command.args[0])))
	{
		print_err(command, "No such file or directory");
		return ;
	}
	free(command.args[0]);
	command.args[0] = bin_file;
	if ((pid = fork()) < 0)
		ft_putstr("ошибка fork\n");
	else if (pid == 0)
		if (execve(command.args[0], command.args, envp) < 0)
			ft_putstr("ошибка execve\n");
	if ((pid = wait(0)) < 0)
		ft_putstr("ошибка waitpid\n");
}

void		run(t_command *command, char ***envp)
{
	if (command->builtin == 1)
		run_builtin(command, envp);
	else
		run_bin(*command, *envp);
}
