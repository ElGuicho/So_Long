/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:50:46 by gmunoz            #+#    #+#             */
/*   Updated: 2024/08/15 18:03:18 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
        mlx_destroy_window(vars->mlx, vars->win);
        return (0);
    }
    return (1);
}
int close_window(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
/* 	ft_printf("x = %d\n", vars->img->x);
	ft_printf("y = %d\n", vars->img->y); */
/* 	t_data *img;
	t_map *lay;

	img = vars->img;
	lay = vars->lay; */
	if (keycode == 119)
	{
		if (vars->img->y > 33)
		{
			//ft_printf("n_row = %d\n", vars->lay->n_row);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img2, vars->img->x, vars->img->y);
			vars->img->y -= 64;
			//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
			vars->steps++;
			ft_printf("number of steps = %d\n", vars->steps);
		}	
		ft_printf("y = %d\n", vars->img->y);
	}
	if (keycode == 97)
	{
		if (vars->img->x > 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img2, vars->img->x, vars->img->y);
			vars->img->x -= 64;	
			//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
			vars->steps++;
			ft_printf("number of steps = %d\n", vars->steps);
		}
		ft_printf("x = %d\n", vars->img->x);
	}
	if (keycode == 115)
	{
		//ft_printf("n_row = %d\n", vars->lay->n_row);
		if (vars->img->y < (vars->lay->n_row * 64) - 64)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img2, vars->img->x, vars->img->y);
			vars->img->y += 64;	
			//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
			vars->steps++;
			ft_printf("number of steps = %d\n", vars->steps);
		}
		ft_printf("y = %d\n", vars->img->y);
	}
	if (keycode == 100)
	{
		if (vars->img->x < (vars->lay->n_col * 64) - 64)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img2, vars->img->x, vars->img->y);
			vars->img->x += 64;	
			//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
			vars->steps++;
			ft_printf("number of steps = %d\n", vars->steps);
		}
		ft_printf("x = %d\n", vars->img->x);
	}
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
	return (0);
}