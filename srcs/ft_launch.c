/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 14:43:03 by oexall            #+#    #+#             */
/*   Updated: 2016/08/06 09:47:30 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int		ft_home_exec(char **args, t_all *all)
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

int		ft_exec(char **args, t_all *all)
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

void	ft_changeredir(char ***p_args)
{
	char	**args;
	int		fd;
	int		i;
	int		len;

	args = *p_args;
	i = ft_isredir(args);
	len = ft_strlen(args[i]);
	if (ft_strncmp(args[i], ">", 1) == 0 && args[i + 1] && len == 1)
	{
		fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		args[i] = NULL;
		return ;
	}
	if (ft_strncmp(args[i], ">>", 2) == 0 && args[i + 1] && len == 2)
	{
		fd = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		args[i] = NULL;
		return ;
	}
}

int		ft_launch(char **args, t_all *all)
{
	pid_t	pid;
	int		status;

	pid = fork();
	status = 1;
	if (pid == 0 && args && args[0] != NULL && args[0][0] != '\0')
	{
		if (ft_isredir(args) > -1)
			ft_changeredir(&args);
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
