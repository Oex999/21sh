/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 08:01:48 by oexall            #+#    #+#             */
/*   Updated: 2016/07/28 11:13:31 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static void	ft_add_to_line(char c, t_all *all)
{
	++(all->len);
	all->line[all->len] = c;
	ft_putchar(c);
}

static void	ft_move_left(t_all *all)
{
	if (CURSOR > (int)(ft_strlen(all->user) + 2))
	{
		all->win.cursor.vpos -= 1;
		tputs(tgetstr("le", NULL), 1, ft_tputchar);
	}
}

static void	ft_move_right(t_all *all)
{
	if (CURSOR < (int)(ft_strlen(all->user) + 3 + all->len))
	{
		all->win.cursor.vpos += 1;
		tputs(tgetstr("nd", NULL), 1, ft_tputchar);
	}
}

static void	ft_common(int keycode, t_all *all)
{
	if (keycode == KEY_UP)
		ft_hist_key(all, 1);
	else if (keycode == KEY_DOWN)
		ft_hist_key(all, -1);
	else if (keycode == KEY_BACKSPACE)
		ft_backspace(all);
	else if (keycode == KEY_LEFT_ARROW)
		ft_move_left(all);
	else if (keycode == KEY_RIGHT_ARROW)
		ft_move_right(all);
}

int			ft_keyhook(t_all *all)
{
	int				ret;
	unsigned int	code;
	char			*keycode[5];

	ret = 1;
	code = 0;
	while (ret)
	{
		ft_bzero(keycode, 5);
		read(0, keycode, 4);
		code = *(unsigned int *)keycode;
		ft_common(code, all);
		if (code == 10)
		{
			if (all->len > -1)
				ft_putchar('\n');
			all->win.cursor.vpos = ft_strlen(all->user) + 3;
			ft_list_push_front(&all->hist, all->line);
			return ((all->len >= 0) ? 1 : 0);
		}
		else if (code >= 32 && code <= 126)
			ft_add_to_line((char)code, all);
	}
	return (1);
}
