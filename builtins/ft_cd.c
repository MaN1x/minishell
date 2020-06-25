/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 20:00:24 by maxim             #+#    #+#             */
/*   Updated: 2020/06/24 23:22:17 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>
#include "builtins.h"
#include "../libft/libft.h"

void	ft_cd(t_command command, char ***envp)
{
	char		*key;
	char		*full_path;

	if (access(command.args[1], F_OK))
	{
		print_err(command, "No such file or directory");
		return;
	}
	if (access(command.args[1], R_OK))
	{
		print_err(command, "Permission denied");
		return;
	}
	if (chdir(command.args[1]) == -1)
	{
		print_err(command, "Not a directory");
		return;
	}
	if (!(full_path = ft_strnew(MAXPATHLEN)))
		ft_putendl("malloc err");
	getcwd(full_path, MAXPATHLEN);
	if (!(key = ft_strjoin("PWD=", full_path)))
		ft_putendl("malloc err");
	free(full_path);
	free(command.args[1]);
	command.args[1] = key;
	ft_setenv(command, envp);
}
