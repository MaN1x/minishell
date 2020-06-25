/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:31:12 by maxim             #+#    #+#             */
/*   Updated: 2020/06/21 18:46:57 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtins.h"
#include "libft/libft.h"
#include "minishell.h"

void	run_builtin(t_command command, char ***envp)
{
	if (ft_strequ(command.args[0], "cd"))
		ft_cd(command, envp);
	if (ft_strequ(command.args[0], "unsetenv"))
		ft_unsetenv(command, envp);
	if (ft_strequ(command.args[0], "setenv"))
		ft_setenv(command, envp);
	if (ft_strequ(command.args[0], "env"))
		env(*envp);
}
