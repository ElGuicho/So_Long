/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:50:46 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/25 17:16:33 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 119)
	{
		if (vars->img->y > 64
			&& vars->lay->map[vars->img->y / 64 - 1][vars->img->x / 64] != '1')
			move_up(vars);
	}
	if (keycode == 97)
	{
		if (vars->img->x > 64
			&& vars->lay->map[vars->img->y / 64][vars->img->x / 64 - 1] != '1')
			move_left(vars);
	}
	if (keycode == 115)
	{
		if (vars->img->y < (vars->lay->n_row * 64) - 128
			&& vars->lay->map[vars->img->y / 64 + 1][vars->img->x / 64] != '1')
			move_down(vars);
	}
	if (keycode == 100)
	{
		if (vars->img->x < (vars->lay->n_col * 64) - 128
			&& vars->lay->map[vars->img->y / 64][vars->img->x / 64 + 1] != '1')
			move_right(vars);
	}
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	int		x;
	int		y;
	void	*main_char;
	void	*char_in_door;

	x = vars->img->x;
	y = vars->img->y;
	main_char = vars->img->main_char;
	char_in_door = vars->img->char_in_door;
	if (vars->lay->map[y / 64][x / 64] != 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, main_char, x, y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, char_in_door, x, y);
	return (0);
}
