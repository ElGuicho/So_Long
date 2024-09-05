/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:25:28 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/05 16:25:46 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	draw_map(t_vars *vars, int i)
{
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
}

void	draw_interactibles(t_vars *vars, int i, int j)
{
	while (i < vars->lay->n_col - 1)
	{
		if (vars->lay->map[j][i] == 'C')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->coin, i * 64, j * 64);
		else if (vars->lay->map[j][i] == 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->door_exit, i * 64, j * 64);
		else if (vars->lay->map[j][i] == '1')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->inner_wall, i * 64, j * 64);
		else if (vars->lay->map[j][i] == 'P')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->main_char, i * 64, j * 64);
			vars->img->x = i * 64;
			vars->img->y = j * 64;
		}
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, i * 64, j * 64);
		i++;
	}
}

void	put_sprites(t_vars *vars)
{
	int j;

	j = 1;
	draw_map(vars, 1);
	while (j < vars->lay->n_row - 1)
	{
		draw_interactibles(vars, 1, j);
		j++;
	}
}
