/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:04:25 by simoulin          #+#    #+#             */
/*   Updated: 2020/01/10 16:20:21 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_alocate(int size)
{
	char		*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

int			ft_print(char **str, int fd, char *buf)
{
	char		*tmp;
	int			ret;

	ret = 1;
	while (!(ft_strchr(*str, '\n')) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret)
		{
			buf[ret] = '\0';
			tmp = *str;
			if (!(*str = ft_strjoin(*str, buf)))
				return (-1);
			free(tmp);
		}
	}
	free(buf);
	if (ret == 0)
		return (1);
	return (0);
}

char		*ft_put(char **str)
{
	char		*new;
	char		*tmp;
	char		*buf;

	tmp = NULL;
	buf = ft_strchr(*str, '\n');
	if (buf)
	{
		tmp = *str;
		if (!(new = ft_strndup(*str, buf - *str)))
			return (NULL);
		free(tmp);
	}
	else if (!(new = ft_strdup(*str)))
		return (NULL);
	return (new);
}

int			get_next_line(const int fd, char **line)
{
	int				a;
	char			*buf;
	static char		*str;

	a = 0;
	buf = NULL;
	str = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0
			|| (buf == NULL && !(buf = ft_alocate(BUFFER_SIZE + 1)))
			|| read(fd, buf, 0) == -1
			|| (str == NULL && !(str = ft_alocate(0)))
			|| (a = ft_print(&str, fd, buf)) == -1)
		return (-1);
	if (a == 1)
	{
		if (!((*line) = ft_put(&str)))
			return (-1);
		free(str);
		return (0);
	}
	if (!((*line) = ft_put(&str)))
		return (-1);
	return (1);
}
