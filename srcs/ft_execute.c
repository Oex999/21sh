/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 14:03:32 by oexall            #+#    #+#             */
/*   Updated: 2016/07/21 09:09:51 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static int	ft_bncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if ((!(s1[i]) || !(s2[i])) && i < n)
			return (-1);
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int			ft_execute(char **args, t_all *all)
{
	if (!args[0])
		return (1);
	else if (ft_bncmp(args[0], "exit", 4) == 0)
		return (0);
	else if (ft_bncmp(args[0], "clear", 5) == 0)
		ft_putstr("\033c");
	else if (ft_bncmp(args[0], "env", 3) == 0)
		return (ft_print_env(all));
	else if (ft_bncmp(args[0], "cd", 2) == 0)
		return (ft_cd(args, all));
	else if (ft_bncmp(args[0], "echo", 2) == 0)
		return (ft_echo(args, all));
	else if (ft_bncmp(args[0], "setenv", 6) == 0)
		return (ft_setenv(args, all));
	else if (ft_bncmp(args[0], "unsetenv", 8) == 0)
		return (ft_unsetenv(args, all));
	return (ft_launch(args, all));
}
