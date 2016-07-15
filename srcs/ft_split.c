/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 12:19:06 by oexall            #+#    #+#             */
/*   Updated: 2016/07/15 13:56:45 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static int	ft_skipquote(char **line)
{
	if (**line == '\"')
		(*line)++;
	while (**line != '\"')
		(*line)++;
	if (**line == '\"')
		(*line)++;
	return (1);
}

static int	ft_count_args(char *str)
{
	int	c;
	int	in_w;

	c = 0;
	in_w = 0;
	while (*str)
	{
		if (*str == '\"')
			c += ft_skipquote(&str);
		if (in_w == 0 && *str != ' ' && *str != '\t')
			in_w = 1;
		if (in_w == 1 && (*str == ' ' || *str == '\t' || str[1] == '\0'))
		{
			in_w = 0;
			if (*str != '\0')
				c++;
		}
		str++;
	}
	return (c);
}

char		**ft_split(char *str)
{
	char	*start;
	char	**res;
	int		n_args;

	n_args = ft_count_args(str);
	res = (char **)malloc(sizeof(char *) * (n_args + 1));
	start = str;
	while (*str)
	{
		if (*str == '\"')
			ft_skipquote(&str);
		else if (*str == ' ' || *str == '\t')
		{
			if (start != str)
				*(res++) = ft_strsub(start, 0, str - start);
			start = (char *)str + 1;
		}
		str++;
	}
	if (start != str)
		*(res++) = ft_strsub(start, 0, str - start);
	*res = NULL;
	return (res - n_args);
}
