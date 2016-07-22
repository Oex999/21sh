/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 10:38:32 by oexall            #+#    #+#             */
/*   Updated: 2016/07/22 10:45:17 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int		ft_format_args(char *line, t_all *all)
{
	int		res;
	char	**args;
	int		i;

	res = 1;
	i = 0;
	args = ft_split(line);
	while (args[i] != NULL)
	{
		args[i] = ft_trimwhite(args[i]);
		i++;
	}
	res = ft_execute(args, all);
	ft_deltab(args);
	return (res);
}

void	ft_loop(t_all *all)
{
	int		status;
	char	*line;
	char	**cmds;
	int		c;

	status = 1;
	while (status)
	{
		ft_putstr(all->user);
		ft_putstr("$>");
		get_next_line(0, &line);
		cmds = ft_strsplit(line, ';');
		c = 0;
		while (cmds[c] != NULL)
		{
			status = ft_format_args(ft_trimwhite(cmds[c]), all);
			c++;
		}
		ft_deltab(cmds);
		free(line);
	}
}
