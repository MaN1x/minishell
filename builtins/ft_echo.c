/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:00:30 by maxim             #+#    #+#             */
/*   Updated: 2020/06/26 00:44:32 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

void	ft_echo(t_command command)
{
	int	i;

	i = 1;
	while (command.args[i])
		ft_putstr(command.args[i++]);
	ft_putchar('\n');
}
