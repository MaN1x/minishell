/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:19:24 by mjoss             #+#    #+#             */
/*   Updated: 2020/07/05 17:34:11 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static int	args_count(char *line)
{
	int count;
	int	position;

	position = 0;
	count = 0;
	while (line[position])
	{
		while (ft_isspace(line[position]))
			position++;
		while (!ft_isspace(line[position]) && line[position])
			position++;
		if (!ft_isspace(line[position - 1]))
			count++;
	}
	return (count);
}

static void	parse_args(char *line, t_command *command)
{
	int position;
	int word_len;
	int word_nbr;

	word_nbr = 0;
	word_len = 0;
	position = 0;
	command->args = (char**)ft_memalloc((args_count(line) + 1) * sizeof(char*));
	while (line[position])
	{
		while (ft_isspace(line[position]))
			position++;
		while (!ft_isspace(line[position]) && line[position])
		{
			position++;
			word_len++;
		}
		if (!ft_isspace(line[position - 1]))
		{
			command->args[word_nbr] = ft_strnew(word_len);
			ft_memcpy(command->args[word_nbr++], &line[position - word_len],
					word_len);
			word_len = 0;
		}
	}
}

t_command	parse(char *line)
{
	t_command	command;

	command.builtin = 0;
	parse_args(line, &command);
	if (ft_strequ(command.args[0], "echo") ||
		ft_strequ(command.args[0], "cd") ||
		ft_strequ(command.args[0], "setenv") ||
		ft_strequ(command.args[0], "unsetenv") ||
		ft_strequ(command.args[0], "env") ||
		ft_strequ(command.args[0], "exit"))
		command.builtin = 1;
	return (command);
}
