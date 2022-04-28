/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 10:07:57 by simoulin          #+#    #+#             */
/*   Updated: 2019/11/13 16:26:36 by simoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i++] >= '0' && str[i - 1] <= '9')
		result = result * 10 + str[i - 1] - 48;
	return (result * sign);
}
