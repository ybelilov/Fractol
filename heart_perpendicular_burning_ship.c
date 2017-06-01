/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart_perpendicular_burning_ship.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:35:52 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/23 18:35:57 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_init_ht(t_main *main)
{
	int i;

	i = -1;
	while (++i < 20)
	{
		F[i].zoom = 100;
		F[i].movex = 500;
		F[i].movey = 500;
		F[i].fract = ft_ht;
		F[i].max_iter = MAX_ITER;
	}
	main->num = 5;
}

void	ft_init_per_bs(t_main *main)
{
	int i;

	i = -1;
	while (++i < 20)
	{
		F[i].zoom = 100;
		F[i].movex = 500;
		F[i].movey = 500;
		F[i].fract = ft_per_bs;
		F[i].max_iter = MAX_ITER;
	}
	main->num = 8;
}

int		ft_ht(t_fract *fract, int x, int y)
{
	double long	re;
	double long	im;
	int			j;

	re = 0;
	im = 0;
	fract->re_c = (x - fract->movex + 0.5) / fract->zoom;
	fract->im_c = (y - fract->movey + 0.5) / fract->zoom;
	j = -1;
	while ((re * re + im * im < 4) && (++j <= fract->max_iter))
	{
		fract->tmp = 2 * fabsl(re) * im + fract->im_c;
		re = re * re - im * im + fract->re_c;
		im = fract->tmp;
	}
	if (j == fract->max_iter)
		return (0);
	return (j);
}

int		ft_per_bs(t_fract *fract, int x, int y)
{
	double long	re;
	double long	im;
	int			j;

	re = 0;
	im = 0;
	fract->re_c = (x - fract->movex + 0.5) / fract->zoom;
	fract->im_c = (y - fract->movey + 0.5) / fract->zoom;
	j = -1;
	while ((re * re + im * im < 4) && (++j <= fract->max_iter))
	{
		fract->tmp = 2 * re * fabsl(im) + fract->im_c;
		re = re * re - im * im + fract->re_c;
		im = fract->tmp;
	}
	if (j == fract->max_iter)
		return (0);
	return (j);
}
