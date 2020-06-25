/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:36:27 by maxim             #+#    #+#             */
/*   Updated: 2020/06/21 18:43:34 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "../minishell.h"

void	env(char **envp);
void 	ft_cd(t_command command, char ***envp);
void	ft_setenv(t_command command, char ***envp);
void 	ft_unsetenv(t_command command, char ***envp);

#endif
