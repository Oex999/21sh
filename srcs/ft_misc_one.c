/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 10:00:33 by oexall            #+#    #+#             */
/*   Updated: 2016/07/15 15:03:50 by oexall           ###   ########.fr       */
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

int			ft_print_env(t_all *all)
{
	int	i;

	i = 0;
	while (all->env[i] != NULL)
	{
		ft_putendl(all->env[i]);
		i++;
	}
	return (1);
}

char		*ft_join(char *s1, char *s2, char join)
{
	char	*str;
	int		len;
	int		t;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	t = -1;
	while (*s1)
		str[++t] = *s1++;
	str[++t] = join;
	while (*s2)
		str[++t] = *s2++;
	str[++t] = '\0';
	return (str);
}
