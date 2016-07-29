/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 14:43:03 by oexall            #+#    #+#             */
/*   Updated: 2016/07/29 10:08:25 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static int	ft_home_exec(char **args, t_all *all)
{
	int		res;
	char	*h_path;
	char	*e_path;

	res = 1;
	h_path = NULL;
	e_path = NULL;
	h_path = getcwd(NULL, 0);
	e_path = ft_join(h_path, args[0], '/');
	if (execve(e_path, args, all->env) == -1)
		res = -1;
	free(h_path);
	free(e_path);
	return (res);
}

static int	ft_exec(char **args, t_all *all)
{
	int		i;
	int		res;
	char	*v_path;
	char	**s_path;

	i = 0;
	res = -1;
	v_path = ft_getenv(all, "PATH=", '/');
	s_path = ft_strsplit(v_path, ':');
	v_path = NULL;
	while (s_path[i] != NULL)
	{
		v_path = ft_join(s_path[i], args[0], '/');
		if (execve(v_path, args, all->env) != -1)
		{
			free(v_path);
			res = 1;
			break ;
		}
		if (v_path)
			free(v_path);
		i++;
	}
	ft_deltab(s_path);
	return (res);
}

int			ft_launch(char **args, t_all *all)
{
	pid_t	pid;
	int		status;

	pid = fork();
	status = 1;
	if (pid == 0 && args && args[0] != NULL && args[0][0] != '\0')
	{
		if (execve(args[0], args, all->env) != -1)
			return (0);
		if (ft_home_exec(args, all) != -1)
			return (0);
		if (ft_exec(args, all) != -1)
			return (0);
		return (ft_cmderr(args[0], "Command not found", 0));
	}
	else if (pid > 0)
		wait(&status);
	ft_init_term(&all->win);
	return (1);
}
