/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:07:58 by oexall            #+#    #+#             */
/*   Updated: 2016/07/28 08:32:21 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void	ft_backspace(t_all *all)
{
	all->line[all->len] = '\0';
	all->len -= 1;
	//ft_putline(all);
	tputs(tgetstr("dc", NULL), 1, ft_tputchar);
}
