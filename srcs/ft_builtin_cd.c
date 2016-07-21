/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 08:44:28 by oexall            #+#    #+#             */
/*   Updated: 2016/07/19 09:53:21 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int		ft_cd(char **args, t_all *all)
{
	char	*path;

	if (ft_cargs(args) > 2)
		return (ft_cderr(2, args[0], args[1]));
	if (args[1] != NULL)
		path = args[1];
	if (args[1] == NULL || args[1][0] == '~')
		if ((path = ft_getenv(all, "HOME", '/')) == NULL)
			return (ft_cderr(5, args[0], NULL));
	if (args[1] != NULL && args[1][0] == '~' && args[1][1] != '\0')
		path = ft_strjoin(path, ft_strchr(args[1], '/'));
	if (access(path, F_OK) != 0)
		return (ft_cderr(1, args[0], path));
	if (access(path, R_OK) != 0)
		return (ft_cderr(3, args[0], path));
	if (chdir(path) != 0)
		return (ft_cderr(4, args[0], path));
	if (args[1] != NULL && args[1][0] == '~' && args[1][1] != '\0')
		free(path);
	all->old_pwd = all->pwd;
	ft_strdel(&all->pwd);
	all->pwd = getcwd(NULL, 0);
	ft_update_env("OLDPWD", all->old_pwd, all);
	ft_update_env("PWD", all->pwd, all);
	return (1);
}
