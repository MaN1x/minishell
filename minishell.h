/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mineshell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:23:01 by maxim             #+#    #+#             */
/*   Updated: 2020/07/05 15:29:39 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUF_SIZE 10

typedef struct		s_command
{
	unsigned char	builtin;
	char			**args;
}					t_command;

void				run(t_command command, char ***envp);
void				run_builtin(t_command command, char ***envp);
void				print_err(t_command command, char *err);

#endif
