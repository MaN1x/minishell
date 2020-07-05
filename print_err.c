/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 23:12:56 by maxim             #+#    #+#             */
/*   Updated: 2020/06/24 23:12:56 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft/libft.h"

int		syscall_err(void)
{
	ft_putendl("syscall error");
	exit(-1);
}

void	print_err(t_command command, char *err)
{
	ft_putstr(command.args[0]);
	ft_putstr(": ");
	ft_putstr(command.args[1]);
	ft_putstr(": ");
	ft_putendl(err);
}
