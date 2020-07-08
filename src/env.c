/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:37:16 by maxim             #+#    #+#             */
/*   Updated: 2020/07/06 17:39:15 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

void	env(t_command command, char ***envp)
{
	char	**env;

	env = *envp;
	if (command.args[1] && (ft_strcmp(command.args[1], "-i") == 0))
	{
		while (*env)
			free(*env++);
		free(*envp);
		*envp = (char**)malloc(sizeof(char*));
		**envp = 0;
	}
	else
		while (*env)
			ft_putendl(*env++);
}
