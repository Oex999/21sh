/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 15:13:22 by oexall            #+#    #+#             */
/*   Updated: 2016/07/15 15:17:35 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

char	*ft_getenv(t_all *all, char *value)
{
	int		i;

	i = 0;
	while (all->env[i] != NULL)
	{
		if (ft_strncmp(all->env[i], value, ft_strlen(value)) == 0)
			return (ft_strchr(all->env[i], '/'));
		i++;
	}
	return (NULL);
}
