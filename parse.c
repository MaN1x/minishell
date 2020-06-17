/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:19:24 by mjoss             #+#    #+#             */
/*   Updated: 2020/06/03 00:08:20 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

static int	parse_name(char *line, t_command *command)
{
	int	len;

	len = 0;
	while (ft_isspace(*line) && *line)
		line++;
	while (!ft_isspace(line[len]) && line[len])
		len++;
	command->name = ft_strnew(len);
	ft_memcpy(command->name, line, len);
	return (len);
}

static int args_count(char *line, int name_offset)
{
	int count;
	int	position;

	position = name_offset;
	count = 0;
	while (line[position])
	{
		while (ft_isspace(line[position]) && line[position])
			position++;
		count++;
		while (!ft_isspace(line[position]) && line[position])
			position++;
	}
	return (count);
}

static void	parse_args(char *line, int name_offset, t_command *command)
{
	int position;
	int word_len;
	int word_nbr;

	word_nbr = 0;
	word_len = 0;
	position = name_offset;
	command->args = (char**)ft_memalloc(((unsigned long)args_count(line,
											name_offset) + 1 ) * sizeof(char*));
	while (line[position])
	{
		while (ft_isspace(line[position]) && line[position])
			position++;
		while (!ft_isspace(line[position]) && line[position])
		{
			position++;
			word_len++;
		}
		command->args[word_nbr] = ft_strnew(word_len);
		ft_memcpy(command->args[word_nbr], &line[position- word_len],
																word_len);
		word_len = 0;
		word_nbr++;
	}
}

t_command	parse(char *line)
{
	int			name_len;
	t_command	command;

	command.builtin = 0;
	name_len = parse_name(line, &command);
	parse_args(line, name_len, &command);
	if (ft_strequ(command.name, "echo") ||
		ft_strequ(command.name, "cd") ||
		ft_strequ(command.name, "setenv") ||
		ft_strequ(command.name, "unsetenv") ||
		ft_strequ(command.name, "env") ||
		ft_strequ(command.name, "exit"))
		command.builtin = 1;


	return (command);
}