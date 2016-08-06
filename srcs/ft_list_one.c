/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 12:33:17 by oexall            #+#    #+#             */
/*   Updated: 2016/08/04 07:59:36 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

static void	ft_allzero(t_hist **hist)
{
	t_hist	*list;

	list = NULL;
	list = *hist;
	while (list->elem)
	{
		list->select = 0;
		list = list->next;
	}
}

t_hist		*ft_create_elem(char *str)
{
	t_hist	*hist;

	hist = (t_hist *)malloc(sizeof(t_hist));
	hist->select = 1;
	hist->elem = ft_strdup(str);
	hist->next = NULL;
	return (hist);
}

void		ft_list_push_front(t_hist **begin_list, char *str)
{
	t_hist	*list;
	t_hist	*tmp;

	list = NULL;
	tmp = NULL;
	list = *begin_list;
	tmp = ft_create_elem(str);
	if (tmp && list)
	{
		ft_allzero(&list);
		tmp->next = list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_create_elem(str);
}
