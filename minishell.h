/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mineshell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:23:01 by maxim             #+#    #+#             */
/*   Updated: 2020/06/17 20:30:49 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct		s_command
{
	unsigned char	builtin;
	char 			**args;
}					t_command;

t_command			parse(char *line);

#endif
