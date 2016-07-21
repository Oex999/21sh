/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 08:34:53 by oexall            #+#    #+#             */
/*   Updated: 2016/07/21 08:15:11 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int		ft_cmderr(char *cmd, char *err, int ret)
{
	ft_putstr(cmd);
	ft_putstr(": ");
	ft_putendl(err);
	return (ret);
}

int		ft_cderr(int ecode, char *cmd, char *arg)
{
	ft_putstr(cmd);
	if (ecode == 1)
		ft_putstr(E_NONEXISTANT);
	else if (ecode == 2)
		ft_putstr(E_INVALIDARGS);
	else if (ecode == 3)
		ft_putstr(E_DENIEDACCESS);
	else if (ecode == 4)
		ft_putstr(E_NOTDIR);
	else if (ecode == 5)
		ft_putstr(E_NOHOME);
	if (arg)
		ft_putendl(arg);
	else
		ft_putchar('\n');
	return (1);
}
