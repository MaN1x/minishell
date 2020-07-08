/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 21:38:27 by mjoss             #+#    #+#             */
/*   Updated: 2020/07/05 19:29:57 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "minishell.h"

char		*read_line(void)
{
	char	*line;
	char	buf;
	int		len_line;
	int		rd;

	len_line = BUF_SIZE;
	line = ft_strnew(BUF_SIZE);
	while ((rd = read(STDIN_FILENO, &buf, 1)) > 0)
	{
		if (buf == '\n' || buf == '\0')
		{
			line[ft_strlen(line)] = '\0';
			return (line);
		}
		else
			ft_strncat(line, &buf, 1);
		if (ft_strlen(line) == (unsigned long)len_line)
		{
			len_line *= 2;
			line = ft_strinc(&line);
		}
	}
	if (rd < 0)
		ft_putstr("rd err\n");
	return (NULL);
}

static void	free_all(t_command *command, char **line)
{
	int i;

	i = 0;
	while (command->args[i])
	{
		free(command->args[i]);
		i++;
	}
	free(command->args);
	free(*line);
}

static void	free_env(char ***env)
{
	int		i;
	char	**envp;

	i = 0;
	envp = *env;
	while (envp[i])
		free(envp[i++]);
	free(envp);
}

int			main(int argc, char **argv, char **env)
{
	char		*line;
	char		**envp;
	t_command	command;

	(void)argc;
	(void)argv;
	envp = ft_massdup(env);
	while (1)
	{
		ft_putstr("$>");
		line = read_line();
		command = parse(line);
		parse_tilda(&command, envp);
		parse_parameter_extension(&command, envp);
		run(&command, &envp);
		free_all(&command, &line);
	}
	free_env(&envp);
	return (0);
}
