/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 10:01:29 by oexall            #+#    #+#             */
/*   Updated: 2016/07/19 11:51:15 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static void	ft_print_hidden(char hc)
{
	if (hc == 'n')
		ft_putchar('\n');
	else if (hc == 't')
		ft_putchar('\t');
	else if (hc == 'v')
		ft_putchar('\v');
	else if (hc == 'r')
		ft_putchar('\r');
	else if (hc == 'f')
		ft_putchar('\f');
	else if (hc == 'a')
		ft_putchar('\a');
	else if (hc == 'b')
		ft_putchar('\b');
	else if (hc == '"')
		ft_putchar('\"');
	else if (hc == '\\')
		ft_putchar('\\');
}

static int	ft_printenv(char *env, t_all *all)
{
	char	*var;
	char	*value;
	int		len;

	len = 0;
	while (env[len] && env[len] != ' ' && env[len] != '\"' &&
			env[len] >= 'A' && env[len] <= 'Z')
		len++;
	var = ft_strsub(env, 0, len);
	if ((value = ft_getenv(all, var, '=')) != NULL)
		ft_putstr(++value);
	free(var);
	return (len + 1);
}

static void	ft_print_echo(char *str, t_all *all)
{
	int	i;
	int	in_q;

	i = 0;
	in_q = (str[i] == '\"') ? 1 : 0;
	i += (str[i] == '\"');
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			i += ft_printenv(&str[i + 1], all);
		if (str[i] == '\\' && str[i + 1] != '\0')
		{
			if (in_q == 1)
				ft_print_hidden(str[i + 1]);
			i += (in_q == 1) ? 2 : 1;
			continue;
		}
		if (str[i] != '\"')
			ft_putchar(str[i]);
		i++;
	}
}

int			ft_echo(char **args, t_all *all)
{
	int	i;
	int	is_n;

	i = 1;
	is_n = 0;
	if (args[i] && ft_strncmp("-n", args[i], 2) == 0)
		is_n = i++;
	while (args[i] && args[i] != NULL)
	{
		ft_print_echo(args[i], all);
		if (args[i + 1] != NULL)
			ft_putchar(' ');
		i++;
	}
	if (is_n == 0)
		ft_putchar('\n');
	else
		ft_putendl("\e[7m%\e[0m");
	return (1);
}
