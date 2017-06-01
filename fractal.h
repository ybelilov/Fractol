/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:50:05 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/30 19:31:13 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# define MAX_ITER 10
# define F main->fract
# define M args->main
# define MN arg->main

typedef struct		s_fract
{
	long double		re;
	long double		im;
	long double		re_c;
	long double		im_c;
	long double		tmp;
	int				max_iter;
	int				(*fract)(struct s_fract*, int, int);
	long double		movex;
	long double		movey;
	long double		zoom;
	long double		alpha;
}					t_fract;

typedef struct		s_main
{
	void			*mlx_ptr;
	void			*window;
	char			*img;
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				stop;
	int				num;
	t_fract			*fract;
}					t_main;

typedef struct		s_arg
{
	int				id;
	pthread_t		pthread;
	t_main			*main;
}					t_arg;

void				first_draw(t_arg *arg);
void				*draw(void *arg);
void				ft_color(char *img, int i);
int					ft_check(char *av, t_main *main, int i);
void				ft_error_check(void);

void				ft_init_jul(t_main *main);
void				ft_init_mb(t_main *main);
void				ft_init_tr(t_main *main);
void				ft_init_bs(t_main *main);
void				ft_init_ht(t_main *main);
void				ft_init_c_mb(t_main *main);
void				ft_init_c_tr(t_main *main);
void				ft_init_per_bs(t_main *main);

int					ft_jul(struct s_fract *fract, int x, int y);
int					ft_mb(struct s_fract *fract, int x, int y);
int					ft_tr(struct s_fract *fract, int x, int y);
int					ft_bs(struct s_fract *fract, int x, int y);
int					ft_ht(struct s_fract *fract, int x, int y);
int					ft_c_mb(struct s_fract *fract, int x, int y);
int					ft_c_tr(struct s_fract *fract, int x, int y);
int					ft_per_bs(struct s_fract *fract, int x, int y);

int					key_functions(int key, t_arg *arg);
int					mouse(int x, int y, t_arg *arg);
int					mouse_functions(int button, int x, int y, t_arg *arg);
void				ft_move(int key, t_fract *fract);
#endif
