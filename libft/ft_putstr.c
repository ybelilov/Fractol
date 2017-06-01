/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:44:17 by ybelilov          #+#    #+#             */
/*   Updated: 2016/12/27 16:44:21 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	char c;

	if (s)
	{
		while (*s)
		{
			c = *s;
			write(1, &c, 1);
			s++;
		}
	}
}
