/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 12:17:50 by oexall            #+#    #+#             */
/*   Updated: 2016/07/28 14:10:59 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static void	ft_move_up(t_all *all)
{
	t_hist	*list;

	list = all->hist;
	while (list->elem)
	{
		if (list->select == 1)
		{
			if (list->next->elem)
			{
				list->select = 0;
				list->next->select = 1;
			}
			return ;
		}
		list = list->next;
	}
}

static void	ft_move_down(t_all *all)
{
	t_hist	*list;

	list = all->hist;
	while (list->elem)
	{
		if (list->next->elem && list->next->select == 1)
		{
			list->next->select = 0;
			list->select = 1;
			return ;
		}
		list = list->next;
	}
}

void		ft_putline(t_all *all)
{
	tputs(tgetstr("dl", NULL), 1, ft_tputchar);
	tputs(tgetstr("cr", NULL), 1, ft_tputchar);
	ft_putstr(all->user);
	ft_putstr("$>");
	ft_putstr(all->line);
}

void		ft_hist_key(t_all *all, int dir)
{
	t_hist	*list;

	list = all->hist;
	if (dir == -1 && list->select == 1)
	{
		all->len = -1;
		ft_strclr(all->line);
		ft_putline(all);
		return ;
	}
	else if (dir == -1)
		ft_move_down(all);
	while (list->elem)
	{
		if (list->select == 1)
		{
			ft_copy_into_line(all, list->elem);
			break ;
		}
		list = list->next;
	}
	if (dir == 1)
		ft_move_up(all);
	ft_putline(all);
}
