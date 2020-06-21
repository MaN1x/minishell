/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:48:00 by maxim             #+#    #+#             */
/*   Updated: 2020/06/21 03:27:37 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "minishell.h"
#include "libft/libft.h"

static void ft_setenv(t_command command, char ***envp)
{

}

static void env(char **envp)
{
	while (*envp)
		ft_putendl(*envp++);
}

static void	run_builtin(t_command command, char ***envp)
{
	if (ft_strequ(command.args[0], "setenv"))
		ft_setenv(command, envp);
	if (ft_strequ(command.args[0], "env"))
		env(*envp);
}

static char *join_path(char *path, char *name)
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

static char *check_dir(char *dir, char *name)
{
	char	*current_dir;

	if (!(current_dir = join_path(dir, name)))
		ft_putstr("malloc error");
	if (access(current_dir, X_OK) == 0)
		return (current_dir);
	else
	{
		free(current_dir);
		return (0);
	}
}

static char *find_in_PATH(t_command command, char **envp)
{
	char	*current_dir;
	char	**dirs;
	int 	i;

	i = 0;
	current_dir = 0;
	while (!ft_strnstr(*envp, "PATH", 4) && *envp)
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

static void run_bin(t_command command, char **envp)
{
	pid_t	pid;
	char	*bin_file;

	if ((bin_file = find_in_PATH(command, envp)))
	{
		free(command.args[0]);
		command.args[0] = bin_file;
	}
	if ((pid = fork()) < 0)
		ft_putstr("ошибка fork\n");
	else if (pid == 0)
		if (execve(command.args[0], command.args, envp) < 0)
			ft_putstr("ошибка execve\n");
	if ((pid = waitpid(pid,0,0)) < 0)
		ft_putstr("ошибка waitpid\n");
	ft_putstr("parent process\n");
}

void		run(t_command command, char ***envp)
{
	if (command.builtin == 1)
		run_builtin(command, envp);
	else
		run_bin(command, *envp);
}
