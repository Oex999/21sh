/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 15:13:22 by oexall            #+#    #+#             */
/*   Updated: 2016/07/21 12:31:15 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

char	*ft_getenv(t_all *all, char *value, char ptr)
{
	int		i;

	i = 0;
	while (all->env[i] != NULL)
	{
		if (ft_strncmp(all->env[i], value, ft_strlen(value)) == 0)
			return (ft_strchr(all->env[i], ptr));
		i++;
	}
	return (NULL);
}

int		ft_update_env(char *env, char *val, t_all *all)
{
	char	*n_env;
	int		i;

	i = 0;
	while (all->env[i] != NULL)
	{
		if (ft_strncmp(all->env[i], env, ft_strlen(env)) == 0)
		{
			n_env = ft_join(env, val, '=');
			ft_strdel(&all->env[i]);
			all->env[i] = ft_strdup(n_env);
			free(n_env);
			return (i);
		}
		i++;
	}
	return (-1);
}

int		ft_indexof(char *env, t_all *all)
{
	int		i;

	i = 0;
	while (all->env[i] != NULL)
	{
		if (ft_strncmp(all->env[i], env, ft_strlen(env)) == 0)
			return (i);
		i++;
	}
	return (-1);
}
