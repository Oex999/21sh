/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 10:00:33 by oexall            #+#    #+#             */
/*   Updated: 2016/07/15 12:16:29 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void		ft_deltab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
				free(tab[i]);
			i++;
		}
		free(tab);
	}
}

static int	ft_isspecial(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_trimwhite(char *str)
{
	char	*end;

	while (ft_isspecial(*str) == 1)
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspecial(*end) == 1)
		end--;
	*(end + 1) = '\0';
	return (str);
}
