/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:49:39 by oexall            #+#    #+#             */
/*   Updated: 2016/07/28 14:58:03 by oexall           ###   ########.fr       */
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

static void	ft_clear_hist(t_all *all)
{
	t_hist	*list;
	t_hist	*tmp;

	list = all->hist;
	while (list->elem)
	{
		tmp = list->next;
		list->next = NULL;
		if (list->elem)
			free(list->elem);
		list = NULL;
		list = tmp;
	}
	free(all->hist);
}

static void	ft_init(t_all *all)
{
	all->line = NULL;
	all->len = -1;
	all->user = ft_getenv(all, "USER", '=');
	all->user++;
	all->pwd = getcwd(NULL, 0);
	all->old_pwd = all->pwd;
	all->line = ft_strnew(1024);
	ft_putstr("\033c");
	all->win.cursor.hpos = 0;
	all->win.cursor.vpos = ft_strlen(all->user) + 2;
}

int			main(int argc, char **argv, char **environ)
{
	t_all	all;

	(void)argc;
	(void)argv;
	ft_init_term(&all.win);
	all.env = ft_copyenv(environ);
	ft_init(&all);
	ft_loop(&all);
	free(all.pwd);
	ft_deltab(all.env);
	ft_clear_hist(&all);
	if (all.line)
		free(all.line);
	ft_end_term(&all.win);
	return (0);
}
