/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:31:12 by maxim             #+#    #+#             */
/*   Updated: 2020/07/05 18:56:41 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	run_builtin(t_command *command, char ***envp)
{
	if (ft_strequ(command->args[0], "echo"))
		ft_echo(*command);
	if (ft_strequ(command->args[0], "exit"))
		ft_exit(*command);
	if (ft_strequ(command->args[0], "cd"))
		ft_cd(command, envp);
	if (ft_strequ(command->args[0], "unsetenv"))
		ft_unsetenv(*command, envp);
	if (ft_strequ(command->args[0], "setenv"))
		ft_setenv(*command, envp);
	if (ft_strequ(command->args[0], "env"))
		env(*command, envp);
}
