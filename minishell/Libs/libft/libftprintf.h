/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:52:25 by simoulin          #+#    #+#             */
/*   Updated: 2020/07/10 12:25:06 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_list_p
{
	int				is_precision;
	int				precision;
	int				minus;
	int				zero;
	struct list		*next;
}				t_list_p;

int				ft_check_p(const char *s, int i);
int				ft_search_params_p(const char c,
	va_list ap, int *nb, t_list_p *l);
int				ft_verif_relou_p(const char *s, int i);
int				ft_strlen_p(const char *str);
long			ft_atoi_p(const char *str);
int				ft_printf(const char *str, ...);
void			ft_putchar_percent_p(char c, int *nb, t_list_p *l);
void			ft_putnbr_unsigned_p(unsigned int n, int *nb);
void			ft_choose_p(char *str, int *nb, t_list_p *l);
void			ft_print_spaces_back_p(const char *str, int *nb, t_list_p *l);
void			ft_print_spaces_p(const char *str, int *nb, t_list_p *l);
void			ft_put_address_p(long nbr, int *nb, t_list_p *l, char *base);
void			ft_itoa_p(long n, int *nbr, t_list_p *l);
void			ft_itoa_u_p(unsigned int n, int *nbr, t_list_p *l);
void			ft_putchar_fd_p(char c, int *nb);
void			ft_putchar_c_p(char c, int *nb, t_list_p *l);
void			ft_swp_p(char *str, int *nbr, t_list_p *l);
void			ft_putstr_fd_p(char *s, int *nb);
void			ft_putstr_c_p(char *str, int *nb, t_list_p *l);
void			ft_putnbr_h_p(unsigned int nbr, int *nb,
	t_list_p *l, char *base);
void			ft_putdif_fd_p(char *str, int *nbr, t_list_p *l);
void			ft_put_p(char c, int *nb);

#endif
