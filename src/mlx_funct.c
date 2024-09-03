/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:50:46 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/03 18:59:12 by gmunoz           ###   ########.fr       */
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

void	endgame(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_string_put(vars->mlx, vars->win, 100, 100, 0x00FF0000, "You won!");
	sleep(2);
	close_window(vars);
	exit(0);
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
		if (vars->img->y > 64 && vars->lay->map[vars->img->y / 64 - 1][vars->img->x / 64] != '1')
		{
			//ft_printf("n_row = %d\n", vars->lay->n_row);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, vars->img->x, vars->img->y);
			vars->img->y -= 64;
			if (vars->lay->map[vars->img->y / 64][vars->img->x / 64] == 'C')
			{
				vars->lay->collect--;
				vars->lay->map[vars->img->y / 64][vars->img->x / 64] = '0';	
			}
			if (vars->lay->map[vars->img->y / 64][vars->img->x / 64] == 'E' && vars->lay->collect == 0)
				endgame(vars);
			//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
			vars->steps++;
			ft_printf("number of steps = %d\n", vars->steps);
		}	
		ft_printf("y = %d\n", vars->img->y);
	}
	if (keycode == 97)
	{
		if (vars->img->x > 64 && vars->lay->map[vars->img->y / 64][vars->img->x / 64 - 1] != '1')
		{
			if (vars->lay->map[vars->img->y / 64][vars->img->x / 64] == 'C')
			{
				vars->lay->collect--;
				vars->lay->map[vars->img->y / 64][vars->img->x / 64] = '0';	
			}
			if (vars->lay->map[vars->img->y / 64][vars->img->x / 64] == 'E' && vars->lay->collect == 0)
				endgame(vars);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, vars->img->x, vars->img->y);
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
		if (vars->img->y < (vars->lay->n_row * 64) - 128 && vars->lay->map[vars->img->y / 64 + 1][vars->img->x / 64] != '1')
		{
			if (vars->lay->map[vars->img->y / 64][vars->img->x / 64] == 'C')
			{
				vars->lay->collect--;
				vars->lay->map[vars->img->y / 64][vars->img->x / 64] = '0';	
			}
			if (vars->lay->map[vars->img->y / 64][vars->img->x / 64] == 'E' && vars->lay->collect == 0)
				endgame(vars);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, vars->img->x, vars->img->y);
			vars->img->y += 64;	
			//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
			vars->steps++;
			ft_printf("number of steps = %d\n", vars->steps);
		}
		ft_printf("y = %d\n", vars->img->y);
	}
	if (keycode == 100)
	{
		if (vars->img->x < (vars->lay->n_col * 64) - 128 && vars->lay->map[vars->img->y / 64][vars->img->x / 64 + 1] != '1')
		{
			if (vars->lay->map[vars->img->y / 64][vars->img->x / 64] == 'C')
			{
				vars->lay->collect--;
				vars->lay->map[vars->img->y / 64][vars->img->x / 64] = '0';	
			}
			if (vars->lay->map[vars->img->y / 64][vars->img->x / 64] == 'E' && vars->lay->collect == 0)
				endgame(vars);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, vars->img->x, vars->img->y);
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
/* 	printf("vars->img->x = %d\n", vars->img->x);
	printf("vars->img->y = %d\n", vars->img->y); */
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->main_char, vars->img->x, vars->img->y);
	return (0);
}