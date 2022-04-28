/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:23:17 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/18 15:10:53 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

int			ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strchr(const char *s, int c);
int			ft_print(char **str, int fd, char *buf);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(const int fd, char **line);

#endif
