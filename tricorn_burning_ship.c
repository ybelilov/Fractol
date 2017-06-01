/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_burning_ship.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:36:41 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/23 18:36:43 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_init_tr(t_main *main)
{
	int i;

	i = -1;
	while (++i < 20)
	{
		F[i].zoom = 100;
		F[i].movex = 500;
		F[i].movey = 500;
		F[i].fract = ft_tr;
		F[i].max_iter = MAX_ITER;
	}
	main->num = 3;
}

void	ft_init_bs(t_main *main)
{
	int i;

	i = -1;
	while (++i < 20)
	{
		F[i].zoom = 100;
		F[i].movex = 500;
		F[i].movey = 500;
		F[i].fract = ft_bs;
		F[i].max_iter = MAX_ITER;
	}
	main->num = 4;
}

int		ft_tr(t_fract *fract, int x, int y)
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
		fract->tmp = -2 * re * im + fract->im_c;
		re = re * re - im * im + fract->re_c;
		im = fract->tmp;
	}
	if (j == fract->max_iter)
		return (0);
	return (j);
}

int		ft_bs(t_fract *fract, int x, int y)
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
		fract->tmp = 2 * fabsl(re * im) + fract->im_c;
		re = re * re - im * im + fract->re_c;
		im = fract->tmp;
	}
	if (j == fract->max_iter)
		return (0);
	return (j);
}
