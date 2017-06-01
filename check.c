/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:35:26 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/23 18:35:28 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_check(char *av, t_main *main, int i)
{
	if (!ft_strcmp(av, "1") || !ft_strcmp(av, "jul") || i == 1)
		ft_init_jul(main);
	else if (!ft_strcmp(av, "2") || !ft_strcmp(av, "mb") || i == 2)
		ft_init_mb(main);
	else if (!ft_strcmp(av, "3") || !ft_strcmp(av, "tr") || i == 3)
		ft_init_tr(main);
	else if (!ft_strcmp(av, "4") || !ft_strcmp(av, "bs") || i == 4)
		ft_init_bs(main);
	else if (!ft_strcmp(av, "5") || !ft_strcmp(av, "ht") || i == 5)
		ft_init_ht(main);
	else if (!ft_strcmp(av, "6") || !ft_strcmp(av, "c_mb") || i == 6)
		ft_init_c_mb(main);
	else if (!ft_strcmp(av, "7") || !ft_strcmp(av, "c_tr") || i == 7)
		ft_init_c_tr(main);
	else if (!ft_strcmp(av, "8")
				|| !ft_strcmp(av, "per_bs") || i == 8)
		ft_init_per_bs(main);
	else
		return (0);
	return (1);
}

void	ft_color(char *img, int i)
{
	img[0] = sin(3 * i + 4) * 127 + 200;
	img[1] = sin(3 * i + 2) * 127 + 200;
	img[2] = sin(3 * i) * 127 + 200;
}

void	ft_error_check(void)
{
	printf("Wrong argument !\nTry :\n");
	printf("1)julia(jul)\n");
	printf("2)mandelbrot(mb)\n");
	printf("3)tricorn(tr)\n");
	printf("4)burning_ship(bs)\n");
	printf("5)heart(ht)\n");
	printf("6)celtic(c_mb)\n");
	printf("7)celtic_tricorn(c_tr)\n");
	printf("8)perpendicular_burning_ship(per_bs)\n");
	exit(0);
}

void	ft_move(int key, t_fract *fract)
{
	int i;

	i = -1;
	while (++i < 20)
	{
		if (key == 123 || key == 124)
			fract[i].movex += key == 124 ? 5 : -5;
		if (key == 125 || key == 126)
			fract[i].movey += key == 125 ? 5 : -5;
	}
}
