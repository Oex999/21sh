/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 14:18:45 by oexall            #+#    #+#             */
/*   Updated: 2016/07/22 11:06:36 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int		ft_init_term(t_win *win)
{
	if (tgetent(NULL, getenv("TERM")) < 1)
		return (-1);
	if (tcgetattr(0, &(win->term)) == -1)
		return (-1);
	win->term.c_lflag &= ~(ICANON | ECHO);
	win->term.c_cc[VMIN] = 1;
	win->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, 0, &(win->term)) == -1)
		return (-1);
	return (1);
}

int		ft_end_term(t_win *win)
{
	win->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(win->term)) == -1)
		return (-1);
	return (1);
}
