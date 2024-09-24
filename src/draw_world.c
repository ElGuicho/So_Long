/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:25:28 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/24 18:41:34 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	draw_map(t_vars *vars, t_map *lay, t_data *img, int i)
{
	int		lx;
	int		ly;
	void	*win;

	lx = (lay->n_col - 1) * 64;
	ly = (lay->n_row - 1) * 64;
	win = vars->win;
	mlx_put_image_to_window(vars->mlx, win, img->corner_up_left, 0, 0);
	mlx_put_image_to_window(vars->mlx, win, img->corner_up_right, lx, 0);
	mlx_put_image_to_window(vars->mlx, win, img->corner_down_left, 0, ly);
	mlx_put_image_to_window(vars->mlx, win, img->corner_down_right, lx, ly);
	while (i < lay->n_col - 1)
	{
		mlx_put_image_to_window(vars->mlx, win, img->wall_up, i * 64, 0);
		mlx_put_image_to_window(vars->mlx, win, img->wall_down, i * 64, ly);
		i++;
	}
	i = 1;
	while (i < vars->lay->n_row - 1)
	{
		mlx_put_image_to_window(vars->mlx, win, img->wall_left, 0, i * 64);
		mlx_put_image_to_window(vars->mlx, win, img->wall_right, lx, i * 64);
		i++;
	}
}

void	draw_interactibles(t_vars *vars, int i, int j)
{
	void	*mlx;
	void	*win;
	int		y;

	mlx = vars->mlx;
	win = vars->win;
	y = j * 64;
	while (i < vars->lay->n_col - 1)
	{
		if (vars->lay->map[j][i] == 'C')
			mlx_put_image_to_window(mlx, win, vars->img->coin, i * 64, y);
		else if (vars->lay->map[j][i] == 'E')
			mlx_put_image_to_window(mlx, win, vars->img->door_exit, i * 64, y);
		else if (vars->lay->map[j][i] == '1')
			mlx_put_image_to_window(mlx, win, vars->img->inner_wall, i * 64, y);
		else if (vars->lay->map[j][i] == 'P')
		{
			mlx_put_image_to_window(mlx, win, vars->img->main_char, i * 64, y);
			vars->img->x = i * 64;
			vars->img->y = y;
		}
		else
			mlx_put_image_to_window(mlx, win, vars->img->floor, i * 64, y);
		i++;
	}
}

void	put_sprites(t_vars *vars, t_map *lay, t_data *img)
{
	int	j;

	j = 1;
	draw_map(vars, lay, img, 1);
	while (j < vars->lay->n_row - 1)
	{
		draw_interactibles(vars, 1, j);
		j++;
	}
}
