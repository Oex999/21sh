/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:07:58 by oexall            #+#    #+#             */
/*   Updated: 2016/07/29 07:33:58 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	ft_backspace(t_all *all)
{
	int	i;

	if (all->len > -1 && CURSOR >= (int)(TOTAL + 1))
	{
		all->line[all->len] = '\0';
		--(all->len);
		ft_putline(all);
		CURSOR -= 1;
	}
	else if (all->len > -1 && CURSOR > (int)(USER))
	{
		tputs(tgetstr("sc", NULL), 1, ft_tputchar);
		i = (int)(CURSOR - USER - 5);
		while (i < all->len)
		{
			all->line[i] = all->line[i + 1];
			i++;
		}
		all->line[all->len] = '\0';
		--(all->len);
		CURSOR -= 1;
		ft_putline(all);
		tputs(tgetstr("rc", NULL), 1, ft_tputchar);
		tputs(tgetstr("le", NULL), 1, ft_tputchar);
	}
}

void	ft_insert(char c, t_all *all)
{
	int	i;

	CURSOR += 1;
	if (CURSOR >= (int)(TOTAL + 1))
	{
		++(all->len);
		all->line[all->len] = c;
		ft_putline(all);
	}
	else
	{
		tputs(tgetstr("sc", NULL), 1, ft_tputchar);
		i = all->len;
		while (i > (int)(CURSOR - USER - 6))
		{
			all->line[i + 1] = all->line[i];
			i--;
		}
		++(all->len);
		all->line[(CURSOR - USER) - 5] = c;
		ft_putline(all);
		tputs(tgetstr("rc", NULL), 1, ft_tputchar);
		tputs(tgetstr("nd", NULL), 1, ft_tputchar);
	}
}

void	ft_home_end(t_all *all, int dir)
{
	if (dir == -1)
	{
		while (CURSOR > (int)(USER))
			ft_move_left(all);
	}
	else if (dir == 1)
	{
		while (CURSOR < (int)(TOTAL + 1))
			ft_move_right(all);
	}
}
