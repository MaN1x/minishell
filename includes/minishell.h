/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mineshell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:23:01 by maxim             #+#    #+#             */
/*   Updated: 2020/07/06 18:53:36 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUF_SIZE 11

typedef struct		s_command
{
	unsigned char	builtin;
	char			**args;
}					t_command;

void				run(t_command *command, char ***envp);
void				run_builtin(t_command *command, char ***envp);
void				print_err(t_command command, char *err);
t_command			parse(char *line);
void				parse_tilda(t_command *command, char **env);
void				parse_parameter_extension(t_command *command, char **envp);
void				env(t_command command, char ***envp);
void				ft_cd(t_command *command, char ***envp);
void				ft_setenv(t_command command, char ***envp);
void				ft_unsetenv(t_command command, char ***envp);
void				ft_exit(t_command command);
void				ft_echo(t_command command);
char				*find_in_env(char *name, char **env);

#endif
