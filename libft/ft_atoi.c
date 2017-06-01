/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:34:21 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:34:32 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	char	nb;
	int		res;

	i = 0;
	res = 0;
	nb = '\0';
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' ||
				str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		nb = '-';
	else if (str[i] == '+')
		nb = '+';
	if (nb)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (nb == '-')
		return (res * (-1));
	else
		return (res);
}
