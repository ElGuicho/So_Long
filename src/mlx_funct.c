/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:50:46 by gmunoz            #+#    #+#             */
/*   Updated: 2024/08/14 19:04:21 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}
int close_window(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
/* 	ft_printf("x = %d\n", img->x);
	ft_printf("y = %d\n", img->y); */
	t_data *img;
	t_map *lay;

	img = vars->img;
	lay = vars->lay;
	if (keycode == 119)
	{
		if (img->y > 33)
		{
			//ft_printf("n_row = %d\n", lay->n_row);
			mlx_put_image_to_window(vars->mlx, vars->win, img->img2, img->x, img->y);
			img->y -= 128;
			mlx_put_image_to_window(vars->mlx, vars->win, img->img, img->x, img->y);
			vars->steps++;
			ft_printf("number of steps = %d\n", vars->steps);
		}	
		ft_printf("y = %d\n", img->y);
	}
	if (keycode == 97)
	{
		if (img->x > 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, img->img2, img->x, img->y);
			img->x -= 128;	
			mlx_put_image_to_window(vars->mlx, vars->win, img->img, img->x, img->y);
			vars->steps++;
			ft_printf("number of steps = %d\n", vars->steps);
		}
		ft_printf("x = %d\n", img->x);
	}
	if (keycode == 115)
	{
		//ft_printf("n_row = %d\n", lay->n_row);
		if (img->y < (lay->n_row * 128))
		{
			mlx_put_image_to_window(vars->mlx, vars->win, img->img2, img->x, img->y);
			img->y += 128;	
			mlx_put_image_to_window(vars->mlx, vars->win, img->img, img->x, img->y);
			vars->steps++;
			ft_printf("number of steps = %d\n", vars->steps);
		}
		ft_printf("y = %d\n", img->y);
	}
	if (keycode == 100)
	{
		if (img->x < (lay->n_col * 64))
		{
			mlx_put_image_to_window(vars->mlx, vars->win, img->img2, img->x, img->y);
			img->x += 128;	
			mlx_put_image_to_window(vars->mlx, vars->win, img->img, img->x, img->y);
			vars->steps++;
			ft_printf("number of steps = %d\n", vars->steps);
		}
		ft_printf("x = %d\n", img->x);
	}
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 161);
	return (0);
}