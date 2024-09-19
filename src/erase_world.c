/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:24:52 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/19 18:50:10 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	freee(t_data *img, t_vars *vars, t_map *lay)
{
	int	i;

	i = lay->n_row - 1;
	if (lay)
	{
		if (lay->map)
		{
			while (i >= 0)
			{
				free(lay->map[i]);
				i--;
			}
			free(lay->map);
		}
		free(lay);
	}
	if (img)
		free(img);
	if (vars)
	{
		if (vars->mlx)
			free(vars->mlx);
		free(vars);
	}
}

void	image_free(t_vars *vars)
{
		//doesnt need to check if the image exists?
		mlx_destroy_image(vars->mlx, vars->img->main_char);
		mlx_destroy_image(vars->mlx, vars->img->floor);
		mlx_destroy_image(vars->mlx, vars->img->corner_up_left);
		mlx_destroy_image(vars->mlx, vars->img->corner_up_right);
		mlx_destroy_image(vars->mlx, vars->img->corner_down_left);
		mlx_destroy_image(vars->mlx, vars->img->corner_down_right);
		mlx_destroy_image(vars->mlx, vars->img->wall_up);
		mlx_destroy_image(vars->mlx, vars->img->wall_down);
		mlx_destroy_image(vars->mlx, vars->img->wall_left);
		mlx_destroy_image(vars->mlx, vars->img->wall_right);
		mlx_destroy_image(vars->mlx, vars->img->inner_wall);
		mlx_destroy_image(vars->mlx, vars->img->door_exit);
		mlx_destroy_image(vars->mlx, vars->img->char_in_door);
		mlx_destroy_image(vars->mlx, vars->img->coin);
}

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		image_free(vars);
		mlx_clear_window(vars->mlx, vars->win);
        mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		freee(vars->img, vars, vars->lay);
        exit (0);
    }
	return (0);
}
int	close_window(t_vars *vars)
{
	image_free(vars);
	mlx_clear_window(vars->mlx, vars->win);
    mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	freee(vars->img, vars, vars->lay);
    exit (0);
}

void	endgame(t_vars *vars)
{
	ft_printf("%sYou win!%s\n", GREEN, DEFAULT);
	sleep(1);
	close_window(vars);
	exit(0);
}

