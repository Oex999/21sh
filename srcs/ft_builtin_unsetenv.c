/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_unsetenv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 08:53:47 by oexall            #+#    #+#             */
/*   Updated: 2016/07/21 09:14:44 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int		ft_unsetenv(char **args, t_all *all)
{
	int		i;

	i = 0;
	if (args[1] == NULL)
		return (ft_cmderr(args[0], "Needs an Argument.", 1));
	while (all->env[i])
	{
		if (ft_strncmp(all->env[i], args[1], ft_strlen(args[1])) == 0)
		{
			ft_strdel(&all->env[i]);
			while (all->env[i + 1])
			{
				all->env[i] = all->env[i + 1];
				all->env[i + 1] = NULL;
				i++;
			}
		}
		i++;
	}
	return (1);
}
