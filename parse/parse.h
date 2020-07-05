/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:56:53 by maxim             #+#    #+#             */
/*   Updated: 2020/07/05 01:02:32 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSE_H
# define MINISHELL_PARSE_H
# include "../minishell.h"

t_command	parse(char *line);
void		parse_tilda(t_command *command, char **env);
void		parse_parameter_extension(t_command *command, char **envp);

#endif
