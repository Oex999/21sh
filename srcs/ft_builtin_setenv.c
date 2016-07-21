/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_setenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 07:55:23 by oexall            #+#    #+#             */
/*   Updated: 2016/07/21 08:53:15 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int		ft_setenv(char **args, t_all *all)
{
	int		c;
	char	**tmp_env;

	if (args[1] == NULL || args[2] == NULL || ft_cargs(args) > 3)
		return (ft_cmderr(args[0], E_SETENVARGS, 1));
	if (ft_indexof(args[1], all) != -1)
		return (ft_update_env(args[1], args[2], all));
	c = ft_cargs(all->env);
	tmp_env = ft_dubtab(all->env, c + 1);
	tmp_env[c] = ft_join(args[1], args[2], '=');
	ft_deltab(all->env);
	all->env = tmp_env;
	return (1);
}
