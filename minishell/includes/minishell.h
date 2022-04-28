/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:17:40 by simoulin          #+#    #+#             */
/*   Updated: 2020/07/10 12:22:49 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <libc.h>
# include <dirent.h>
# include "libft.h"
# include "libftprintf.h"

typedef struct	s_list_s
{
	int		k;
	int		info;
	int		unset_0;
	int		nbp;
	int		fd_t;
	int		fd;
	int		pipe[2];
	int		back_slash_n;
	char	*tmp;
	char	*path;
	char	*test;
	char	**env;
	char	**path_rep;
}				t_list_s;

int				egal(char *cmd);
int				ft_exit(char **cmd);
int				ft_strlen_pimp(char *str);
int				ft_size_array(char **tab);
int				ft_size_array(char **tab);
int				ft_check_new_env(char *cmd);
int				ft_printable_env(char *str);
int				ft_cd(char **cmd, t_list_s *l);
int				ft_pwd(char **cmd, t_list_s *l);
int				ft_env(char **cmd, t_list_s *l);
int				ft_echo(char **cmd, t_list_s *l);
int				ft_unset(char **cmd, t_list_s *l);
int				ft_strcmp_p(char *s1, char *s2);
int				ft_strnncmp(char *cmd, char *s2);
int				parsing(char *str, t_list_s *l);
int				ft_export(char **cmd, t_list_s *l);
int				ft_exxecve(char **tab, t_list_s *l);
int				loop_pipe(char ***cmd, t_list_s *l);
int				check_error(char **tab, t_list_s *l);
int				init_struct(t_list_s *l, char *env[]);
int				ft_count_pipe(char **tab, t_list_s *l);
int				ft_check_pipes(char **str, t_list_s *l);
int				cut_spaces_builts(char **arg, t_list_s *l);
int				ft_strcmp_char(const char *s1, const char *s2);
int				ft_strcmp_char(const char *s1, const char *s2);
void			free_array(char **line, char **line_sep);
void			*ft_malloc(t_list_s *l, int size);
void			ft_freeee(char **tab, char **path_rep, char ***cmd, int x);
void			ft_free_tab(char **line, int x);
char			**init_env(char **env, t_list_s *l);
void			ft_free_cmd(char ***cmd);
void			ft_free(char **tab);
void			ft_ls(char **tab);
char			***ft_take_cmd(char **tab, int *x, t_list_s *l);
char			**ft_replace_env(char **tab, t_list_s *l);
char			**ft_redirection(char **tab, t_list_s *l);
char			**ft_split_quote(char *str, t_list_s *l);
char			**sub_case(char **tab, int trou);
char			**add_case(char **tab, int trou);
char			**retire_pv(char **tab, char *c);
char			***retire_quote(char ***tab);
char			***retire_slash(char ***tab);
char			**ft_alpha_order(char **env);
char			**fusionne_quote(char **tab);
char			**retire_pv_esp(char **tab);
char			**ft_copy_tab(char **env);
char			***ft_cmd(char **av);

#endif
