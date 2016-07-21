/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 07:20:32 by oexall            #+#    #+#             */
/*   Updated: 2016/07/21 08:44:02 by oexall           ###   ########.fr       */
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
