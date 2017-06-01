/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:49:09 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/15 15:49:09 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		main(int ac, char **av)
{
	t_main	main;
	t_arg	*arg;
	int		i;

	main.fract = malloc(sizeof(t_fract) * 20);
	main.img_ptr = NULL;
	arg = malloc(sizeof(t_arg) * 20);
	if (ac != 2 || ft_check(av[1], &main, 0) == 0)
		ft_error_check();
	main.mlx_ptr = mlx_init();
	main.window = mlx_new_window(main.mlx_ptr, 1000, 1000, "Fract'ol");
	main.stop = 1;
	i = -1;
	while (++i < 20)
	{
		arg[i].id = i;
		arg[i].main = &main;
	}
	first_draw(arg);
	mlx_hook(main.window, 2, 0, key_functions, arg);
	mlx_hook(main.window, 4, 0, mouse_functions, arg);
	mlx_hook(main.window, 6, 0, mouse, arg);
	mlx_loop(main.mlx_ptr);
	return (0);
}

void	first_draw(t_arg *arg)
{
	int i;

	if (MN->img_ptr)
		mlx_destroy_image(MN->mlx_ptr, MN->img_ptr);
	MN->img_ptr = mlx_new_image(MN->mlx_ptr, 1000, 1000);
	MN->img = mlx_get_data_addr(MN->img_ptr, &MN->bits_per_pixel,
				&MN->size_line, &MN->endian);
	i = -1;
	while (++i < 20)
		pthread_create(&arg[i].pthread, NULL, draw, (void*)&arg[i]);
	i = -1;
	while (++i < 20)
		pthread_join(arg[i].pthread, NULL);
	mlx_put_image_to_window(MN->mlx_ptr, MN->window, MN->img_ptr, 0, 0);
}

void	*draw(void *arg)
{
	t_arg	*args;
	int		i;
	int		j;

	args = (t_arg*)arg;
	i = args->id * 50;
	while (i < args->id * 50 + 50)
	{
		j = -1;
		while (++j != 1000)
			ft_color(&M->img[(j * 4 + (i * 4000))],
				M->fract[args->id].fract(&M->fract[args->id], j, i));
		i++;
	}
	return (NULL);
}
