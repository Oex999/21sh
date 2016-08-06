/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 07:20:32 by oexall            #+#    #+#             */
/*   Updated: 2016/08/06 09:12:53 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int		ft_tputchar(int c)
{
	return (write(2, &c, 1));
}

int		ft_cargs(char **args)
{
	int	c;

	c = 0;
	while (args[c] != NULL)
		c++;
	return (c);
}

char	**ft_dubtab(char **tab, int len)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	while (tab[++i] != NULL)
		tmp[i] = ft_strdup(tab[i]);
	while (++i < len)
		tmp[i][0] = '\0';
	tmp[len] = NULL;
	return (tmp);
}

void	ft_copy_into_line(t_all *all, char *str)
{
	int	i;

	i = 0;
	ft_strclr(all->line);
	all->len = -1;
	all->len += ft_strlen(str);
	all->win.cursor.vpos = USER + all->len + 1;
	while (str[i] != '\0')
	{
		all->line[i] = str[i];
		i++;
	}
}

int		ft_isredir(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (ft_strncmp(args[i], ">", 1) == 0)
			return (i);
		if (ft_strncmp(args[i], ">>", 2) == 0)
			return (i);
	}
	return (-1);
}
