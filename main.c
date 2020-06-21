/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 21:38:27 by mjoss             #+#    #+#             */
/*   Updated: 2020/06/21 03:24:02 by maxim            ###   ########.fr       */
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


static char **init_env(char **env)
{
	int		len;
	char	**envp;

	len = 0;
	while (env[len])
		len++;
	envp = (char**)malloc((len + 1) * sizeof(char*));
	len = 0;
	while (env[len])
	{
		envp[len] = ft_strdup(env[len]);
		len++;
	}
	envp[len] = 0;
	return (envp);
}

int		main(int argc, char **argv, char **env)
{
	int			i;
	char		*line;
	char 		**envp;
	t_command	command;

	i = 0;
	envp = init_env(env);
	ft_putstr("$>");
	line = read_line();
	command = parse(line);
	run(command, &envp);


	i = 0;
	while (command.args[i])
	{
		free(command.args[i]);
		i++;
	}
	free(command.args);

	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);

	free(line);
	return 0;
}
