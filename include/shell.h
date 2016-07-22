/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:52:52 by oexall            #+#    #+#             */
/*   Updated: 2016/07/22 10:18:41 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <termcap.h>
# include <termios.h>
# include <stdlib.h>
# include "errors.h"
# include "../libft/libft.h"

typedef struct		s_cursor
{
	int				hpos;
	int				vpos;
}					t_cursor;

typedef struct		s_win
{
	struct	termios	term;
	t_cursor		cursor;
	int				insert_mode;
	int				delete_mode;
}					t_win;

typedef struct		s_all
{
	char			**env;
	char			*user;
	char			*old_pwd;
	char			*pwd;
	t_win			win;
}					t_all;

/*ft_misc_(one;two).c*/
void				ft_deltab(char **tab);
char				*ft_trimwhite(char *str);
int					ft_print_env(t_all *all);
char				*ft_join(char *s1, char *s2, char join);
int					ft_tputchar(int c);
int					ft_cargs(char **args);
char				**ft_dubtab(char **tab, int len);
/*ft_loop.c*/
void				ft_loop(t_all *all);
int					ft_format_args(char *line, t_all *all);
/*ft_split.c*/
char				**ft_split(char *str);
/*ft_execute.c*/
int					ft_execute(char **args, t_all *all);
/*ft_launch.c*/
int					ft_launch(char **args, t_all *all);
/*ft_env.c*/
char				*ft_getenv(t_all *all, char *value, char ptr);
int					ft_update_env(char *env, char *val, t_all *all);
int					ft_indexof(char *env, t_all *all);
/*ft_termcap.c*/
int					ft_init_term(t_win *win);
int					ft_end_term(t_win *win);
/*ft_keyhook.c*/
int					ft_keyhook(t_all *all);
/*ft_error.c*/
int					ft_cmderr(char *cmd, char *err, int ret);
int					ft_cderr(int ecode, char *cmd, char *arg);
/*ft_builin_(cd|echo|setenv|unsetenv).c*/
int					ft_cd(char **args, t_all *all);
int					ft_echo(char **args, t_all *all);
int					ft_setenv(char **args, t_all *all);
int					ft_unsetenv(char **args, t_all *all);
#endif
