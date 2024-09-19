/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_moveset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:15:21 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/19 18:37:43 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	check_position(t_vars *vars)
{
	if (vars->lay->map[vars->img->y / 64][vars->img->x / 64] == 'C')
	{
		vars->lay->collect--;
		vars->lay->map[vars->img->y / 64][vars->img->x / 64] = '0';
	}
	if (vars->lay->map[vars->img->y / 64][vars->img->x / 64] == 'E' && vars->lay->collect == 0)
		endgame(vars);
}

void	move_up(t_vars *vars)
{
	//ft_printf("n_row = %d\n", vars->lay->n_row);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, vars->img->x, vars->img->y);
	vars->img->y -= 64;
	check_position(vars);
	if (vars->lay->map[vars->img->y / 64 + 1][vars->img->x / 64] == 'E' && vars->lay->collect != 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->door_exit, vars->img->x, vars->img->y + 64);
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
	vars->steps++;
	ft_printf("number of steps = %d\n", vars->steps);
}

void	move_left(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, vars->img->x, vars->img->y);
	vars->img->x -= 64;	
	check_position(vars);
	if (vars->lay->map[vars->img->y / 64][vars->img->x / 64 + 1] == 'E' && vars->lay->collect != 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->door_exit, vars->img->x + 64, vars->img->y);
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
	vars->steps++;
	ft_printf("number of steps = %d\n", vars->steps);
}

void	move_down(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, vars->img->x, vars->img->y);
	vars->img->y += 64;	
	check_position(vars);
	if (vars->lay->map[vars->img->y / 64 - 1][vars->img->x / 64] == 'E' && vars->lay->collect != 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->door_exit, vars->img->x, vars->img->y - 64);
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
	vars->steps++;
	ft_printf("number of steps = %d\n", vars->steps);
}

void	move_right(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, vars->img->x, vars->img->y);
	vars->img->x += 64;	
	check_position(vars);
	if (vars->lay->map[vars->img->y / 64][vars->img->x / 64 - 1] == 'E' && vars->lay->collect != 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->door_exit, vars->img->x - 64, vars->img->y);
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, vars->img->x, vars->img->y);
	vars->steps++;
	ft_printf("number of steps = %d\n", vars->steps);
}
