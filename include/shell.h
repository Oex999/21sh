/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:52:52 by oexall            #+#    #+#             */
/*   Updated: 2016/08/06 09:31:10 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <termcap.h>
# include <termios.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include "errors.h"
# include "../libft/libft.h"

# define CURSOR all->win.cursor.vpos
# define USER ft_strlen(all->user) + 2
# define TOTAL all->len + USER

typedef enum		e_keys
{
	KEY_UP = 4283163,
	KEY_DOWN = 4348699,
	KEY_BACKSPACE = 127,
	KEY_LEFT_ARROW = 4479771,
	KEY_RIGHT_ARROW = 4414235,
	KEY_HOME = 4741915,
	KEY_END = 4610843
}					t_keys;

typedef struct		s_cursor
{
	int				hpos;
	int				vpos;
}					t_cursor;

typedef struct		s_win
{
	struct termios	term;
	t_cursor		cursor;
	int				insert_mode;
	int				delete_mode;
}					t_win;

typedef struct		s_hist
{
	char			*elem;
	int				select;
	struct s_hist	*next;
}					t_hist;

typedef struct		s_all
{
	char			**env;
	char			*user;
	char			*old_pwd;
	char			*pwd;
	t_win			win;
	char			*line;
	int				len;
	t_hist			*hist;
}					t_all;

void				ft_deltab(char **tab);
char				*ft_trimwhite(char *str);
int					ft_print_env(t_all *all);
char				*ft_join(char *s1, char *s2, char join);
int					ft_tputchar(int c);
int					ft_cargs(char **args);
char				**ft_dubtab(char **tab, int len);
void				ft_copy_into_line(t_all *all, char *str);
int					ft_isredir(char **args);

void				ft_loop(t_all *all);
int					ft_format_args(char *line, t_all *all);

char				**ft_split(char *str);

int					ft_execute(char **args, t_all *all);
int					ft_execute_all(char **args, t_all *all);

int					ft_home_exec(char **args, t_all *all);
int					ft_exec(char **args, t_all *all);
void				ft_changeredir(char ***p_args);
int					ft_launch(char **args, t_all *all);

char				*ft_getenv(t_all *all, char *value, char ptr);
int					ft_update_env(char *env, char *val, t_all *all);
int					ft_indexof(char *env, t_all *all);

int					ft_init_term(t_win *win);
int					ft_end_term(t_win *win);

void				ft_move_left(t_all *all);
void				ft_move_right(t_all *all);
int					ft_keyhook(t_all *all);

int					ft_cmderr(char *cmd, char *err, int ret);
int					ft_cderr(int ecode, char *cmd, char *arg);

int					ft_cd(char **args, t_all *all);
int					ft_echo(char **args, t_all *all);
int					ft_setenv(char **args, t_all *all);
int					ft_unsetenv(char **args, t_all *all);

void				ft_putline(t_all *all);
void				ft_hist_key(t_all *all, int dir);

t_hist				*ft_create_elem(char *str);
void				ft_list_push_front(t_hist **begin_list, char *str);

void				ft_backspace(t_all *all);
void				ft_insert(char c, t_all *all);
void				ft_home_end(t_all *all, int dir);

int					ft_ispipe(char **args);

int					ft_execute_pipe(char **args, t_all *all);
#endif
