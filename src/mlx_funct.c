/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:50:46 by gmunoz            #+#    #+#             */
/*   Updated: 2024/08/22 19:06:47 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		/* mlx_clear_window(vars->mlx, vars->win); */
        mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->win);
        return (0);
    }
    return (1);
}
int close_window(t_vars *vars)
{
	/* mlx_clear_window(vars->mlx, vars->win);
    mlx_destroy_window(vars->mlx, vars->win); */
	mlx_destroy_display(vars->mlx);
	free(vars->win);
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
		if (vars->img->y > 64)
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
		if (vars->img->x > 64)
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
		if (vars->img->y < (vars->lay->n_row * 64) - 128)
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
		if (vars->img->x < (vars->lay->n_col * 64) - 128)
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
	int i;
	int j;

	i = 1;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->corner_up_left, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->corner_up_right, (vars->lay->n_col - 1) * 64, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->corner_down_left, 0, (vars->lay->n_row - 1) * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->corner_down_right, (vars->lay->n_col - 1) * 64, (vars->lay->n_row - 1) * 64);
	while (i < vars->lay->n_col - 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->wall_up, i * 64, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->wall_down, i * 64, (vars->lay->n_row - 1) * 64);
		i++;
	}
	i = 1;
	while (i < vars->lay->n_row - 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->wall_left, 0, i * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->wall_right, (vars->lay->n_col - 1) * 64, i * 64);
		i++;
	}
	i = 1;
	j = 1;
	while (j < vars->lay->n_row - 1)
	{
		while (i < vars->lay->n_col - 1)
		{
			/* if (vars->lay->map[j][i] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img->, i * 64, j * 64);
			if (vars->lay->map[j][i] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img->, i * 64, j * 64); */
			if (vars->lay->map[j][i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img->wall_up, i * 64, j * 64);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img2, i * 64, j * 64);
			i++;
			if (vars->lay->map[j][i] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, i * 64, j * 64);
		}
		i = 1;
		j++;
	}
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
	return (0);
}