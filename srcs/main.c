/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:49:39 by oexall            #+#    #+#             */
/*   Updated: 2016/07/22 10:45:24 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static char	**ft_copyenv(char **environ)
{
	char	**tmp;
	int		i;

	i = 0;
	while (environ[i] != NULL)
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 1));
	if (tmp)
	{
		i = 0;
		while (environ[i] != NULL)
		{
			tmp[i] = ft_strdup(environ[i]);
			i++;
		}
		tmp[i] = NULL;
	}
	else
		return (NULL);
	return (tmp);
}

int			main(int argc, char **argv, char **environ)
{
	t_all	all;

	(void)argc;
	(void)argv;
	ft_init_term(&all.win);
	all.env = ft_copyenv(environ);
	all.user = ft_getenv(&all, "USER", '=');
	all.user++;
	all.pwd = getcwd(NULL, 0);
	all.old_pwd = all.pwd;
	ft_loop(&all);
	free(all.pwd);
	ft_deltab(all.env);
	ft_end_term(&all.win);
	return (0);
}
