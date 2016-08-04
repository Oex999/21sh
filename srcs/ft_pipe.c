/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 10:40:09 by oexall            #+#    #+#             */
/*   Updated: 2016/08/01 10:18:35 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static void	ft_runpipe(int fd[], char **args, t_all *all)
{
	pid_t	pid;
	int		i;
	char	**tmp;

	i = ft_ispipe(args);
	tmp = &args[i + 1];
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], 0);
		close(fd[1]);
		if (ft_ispipe(tmp) > 0)
			ft_execute_all(tmp, all);
		else
			ft_execute(tmp, all);
	}
	else if (pid > 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		args[i] = NULL;
		ft_execute(args, all);
	}
}

int			ft_execute_pipe(char **args, t_all *all)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	pipe(fd);
	status = 1;
	pid = fork();
	if (pid == 0)
	{
		ft_runpipe(fd, args, all);
		return (0);
	}
	else if (pid > 0)
		wait(&status);
	close(fd[0]);
	close(fd[1]);
	ft_init_term(&all->win);
	return (1);
}
