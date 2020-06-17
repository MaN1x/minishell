/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 21:38:27 by mjoss             #+#    #+#             */
/*   Updated: 2020/06/06 03:23:24 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "minishell.h"
# define BUF_SIZE 2

char	*read_line(void)
{
	char 	*line;
	char	buf;
	int 	len_line;
	int 	rd;

	len_line = BUF_SIZE;
	if ((line = ft_strnew(BUF_SIZE)) == NULL)
		return (NULL);
	while((rd = read(STDIN_FILENO, &buf, 1)) > 0)
	{
		if (buf == '\n' || buf == '\0' || buf == EOF)
		{
			line[ft_strlen(line)] = '\0';
			return(line);
		}
		else
			ft_strncat(line, &buf, 1);
		if (ft_strlen(line) == len_line)
		{
			len_line *= 2;
			line = ft_strinc(&line);
		}
	}
	if (rd < 0 )
		ft_putstr("rd err\n");
}

int		main(int argc, char **argv, char **envp)
{
	int			i;
	char		*line;
	t_command	command;

	i = 0;
	ft_putstr("$>");
	line = read_line();
	command = parse(line);

	ft_putchar('\n');
	ft_putchar('\n');

	i = 0;
	while (command.args[i])
	{
		free(command.args[i]);
		i++;
	}

	free(command.args);
	free(command.name);

/*
	while(*envp)
    {
	    ft_putstr(*envp);
	    ft_putchar('\n');
	    *envp++;
    }
*/

	free(line);
	return 0;
}
