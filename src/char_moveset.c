/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_moveset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:15:21 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/25 18:35:52 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	check_position(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->img->x;
	y = vars->img->y;
	if (vars->lay->map[y / 64][x / 64] == 'C')
	{
		vars->lay->collect--;
		vars->lay->map[y / 64][x / 64] = '0';
	}
	if (vars->lay->map[y / 64][x / 64] == 'E' && vars->lay->collect == 0)
		endgame(vars);
}

void	move_up(t_vars *vars)
{
	int		x;
	int		y;
	void	*door_exit;

	x = vars->img->x;
	y = vars->img->y;
	door_exit = vars->img->door_exit;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, x, y);
	vars->img->y -= 64;
	y = vars->img->y;
	check_position(vars);
	if (vars->lay->map[y / 64 + 1][x / 64] == 'E' && vars->lay->collect != 0)
		mlx_put_image_to_window(vars->mlx, vars->win, door_exit, x, y + 64);
	vars->steps++;
	ft_printf("number of steps = %d\n", vars->steps);
}

void	move_left(t_vars *vars)
{
	int		x;
	int		y;
	void	*door_exit;

	x = vars->img->x;
	y = vars->img->y;
	door_exit = vars->img->door_exit;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, x, y);
	vars->img->x -= 64;
	x = vars->img->x;
	check_position(vars);
	if (vars->lay->map[y / 64][x / 64 + 1] == 'E' && vars->lay->collect != 0)
		mlx_put_image_to_window(vars->mlx, vars->win, door_exit, x + 64, y);
	vars->steps++;
	ft_printf("number of steps = %d\n", vars->steps);
}

void	move_down(t_vars *vars)
{
	int		x;
	int		y;
	void	*door_exit;

	x = vars->img->x;
	y = vars->img->y;
	door_exit = vars->img->door_exit;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, x, y);
	vars->img->y += 64;
	y = vars->img->y;
	check_position(vars);
	if (vars->lay->map[y / 64 - 1][x / 64] == 'E' && vars->lay->collect != 0)
		mlx_put_image_to_window(vars->mlx, vars->win, door_exit, x, y - 64);
	vars->steps++;
	ft_printf("number of steps = %d\n", vars->steps);
}

void	move_right(t_vars *vars)
{
	int		x;
	int		y;
	void	*door_exit;

	x = vars->img->x;
	y = vars->img->y;
	door_exit = vars->img->door_exit;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->floor, x, y);
	vars->img->x += 64;
	x = vars->img->x;
	check_position(vars);
	if (vars->lay->map[y / 64][x / 64 - 1] == 'E' && vars->lay->collect != 0)
		mlx_put_image_to_window(vars->mlx, vars->win, door_exit, x - 64, y);
	vars->steps++;
	ft_printf("number of steps = %d\n", vars->steps);
}
