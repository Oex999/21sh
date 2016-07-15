/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:52:52 by oexall            #+#    #+#             */
/*   Updated: 2016/07/15 12:38:53 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/libft.h"

typedef struct	s_all
{
	char		**env;
	char		*user;
}				t_all;

void			ft_deltab(char **tab);
char			*ft_trimwhite(char *str);

void			ft_loop(t_all *all);
int				ft_format_args(char *line, t_all *all);

char			**ft_split(char *str);

#endif
