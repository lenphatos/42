/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:52:25 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/27 15:44:14 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	int				is_precision;
	int				precision;
	int				minus;
	int				zero;
	struct s_list	*next;
}				t_list;

int				ft_check(const char *s, int i);
int				ft_search_params(const char c, va_list ap, int *nb, t_list *l);
int				ft_verif_relou(const char *s, int i);
int				ft_strlen(const char *str);
long			ft_atoi(const char *str);
int				ft_printf(const char *str, ...);
void			ft_putchar_percent(char c, int *nb, t_list *l);
void			ft_putnbr_unsigned(unsigned int n, int *nb);
void			ft_choose(char *str, int *nb, t_list *l);
void			ft_print_spaces_back(const char *str, int *nb, t_list *l);
void			ft_print_spaces(const char *str, int *nb, t_list *l);
void			ft_put_address(long nbr, int *nb, t_list *l, char *base);
void			ft_itoa(long n, int *nbr, t_list *l);
void			ft_itoa_u(unsigned int n, int *nbr, t_list *l);
void			ft_putchar_fd(char c, int *nb);
void			ft_putchar_c(char c, int *nb, t_list *l);
void			ft_swp(char *str, int *nbr, t_list *l);
void			ft_putstr_fd(char *s, int *nb);
void			ft_putstr_c(char *str, int *nb, t_list *l);
void			ft_putnbr_h(unsigned int nbr, int *nb, t_list *l, char *base);
void			ft_putdif_fd(char *str, int *nbr, t_list *l);
void			ft_put(char c, int *nb);

#endif
