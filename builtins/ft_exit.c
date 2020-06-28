/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:46:36 by maxim             #+#    #+#             */
/*   Updated: 2020/06/28 00:19:22 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minishell.h"
#include "../libft/libft.h"

void	ft_exit(t_command command)
{
	int i;
	int	ret;

	i = 0;
	if (command.args[1] == 0)
		exit(0);
	while (command.args[1][i] && (ft_isdigit(command.args[1][i])))
			i++;
	if (command.args[1][i] == '\0')
	{
		ret = ft_atoi(command.args[1]);
		exit(ret);
	}
	else
		print_err(command, "Illegal number");
}
