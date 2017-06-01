/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:36:07 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/23 18:36:09 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				key_functions(int key_code, t_arg *arg)
{
	int i;

	i = -1;
	if (key_code == 53)
	{
		mlx_destroy_window(MN->mlx_ptr, MN->window);
		exit(1);
	}
	if (key_code == 76)
		ft_check("", MN, MN->num < 8 ? MN->num + 1 : MN->num - 7);
	if (key_code == 36)
		MN->stop = MN->stop == 1 ? 0 : 1;
	if (key_code == 69 || key_code == 78)
		while (++i < 20)
			MN->fract[i].max_iter += key_code == 69 ? 5 : -5;
	if (key_code >= 123 && key_code <= 126)
		ft_move(key_code, MN->fract);
	if (key_code == 76 || (key_code >= 123 && key_code <= 126) ||
			key_code == 69 || key_code == 78)
		first_draw(arg);
	return (0);
}

int				mouse_functions(int button, int x, int y, t_arg *arg)
{
	int i;

	i = -1;
	if (button == 1 || button == 4)
	{
		while (++i < 20)
		{
			MN->fract[i].zoom += MN->fract[i].zoom / 5;
			MN->fract[i].movex += (long double)(MN->fract[i].movex - x) / 5;
			MN->fract[i].movey += (long double)(MN->fract[i].movey - y) / 5;
		}
		first_draw(arg);
	}
	if (button == 2 || button == 5)
	{
		while (++i < 20)
		{
			MN->fract[i].zoom -= MN->fract[i].zoom / 5;
			MN->fract[i].movex -= (long double)(MN->fract[i].movex - x) / 5;
			MN->fract[i].movey -= (long double)(MN->fract[i].movey - y) / 5;
		}
		first_draw(arg);
	}
	return (0);
}

static double	count_alpha(double x, double y)
{
	double r;

	r = sqrt(fabs((x - 0) * (x - 0)) + fabs((y - 0) * (y - 0)));
	return (r * 0.5);
}

int				mouse(int x, int y, t_arg *arg)
{
	int i;

	if ((x >= 0 && y >= 0) && (x <= 1000 && y <= 1000) && MN->stop == 1)
	{
		i = -1;
		while (++i < 20)
			MN->fract[i].alpha = count_alpha(x, y);
		first_draw(arg);
	}
	return (0);
}
