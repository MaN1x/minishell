/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mineshell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:23:01 by maxim             #+#    #+#             */
/*   Updated: 2020/06/28 21:16:09 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUF_SIZE 10

typedef struct		s_command
{
	unsigned char	builtin;
	char 			**args;
}					t_command;

t_command			parse(char *line);
void 				run(t_command command, char ***envp);
void				run_builtin(t_command command, char ***envp);
void 				print_err(t_command command, char *err);
void				parse_tilda(t_command *command, char **envp);

#endif
