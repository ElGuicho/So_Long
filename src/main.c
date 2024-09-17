/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:40 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/17 19:03:23 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int main(int argc, char const **argv)
{
	t_data	*img;
	t_vars	*vars;
	t_map	*lay;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
		return (1);
	img = malloc(sizeof(t_data));
	if (img == NULL)
	{
		free(vars);
		return (1);
	}
	lay = malloc(sizeof(t_map));
	if (lay == NULL)
	{
		free(img);
		free(vars);
		return (1);
	}
	vars->img = img;
	vars->lay = lay;
	init_vars(vars, lay, img);
	if (create_map(argc, argv, lay) == 1)
	{
		freee(img, vars, lay);
		return (1);
	}
	if (check_path(lay) == 1)
	{
		freee(img, vars, lay);
		return (1);
	}
	if (init_mlx(vars, lay) == 1)
	{
		freee(img, vars, lay);
		return (1);
	}
	mlx_hook(vars->win, 2, 1L<<0, close_win, vars);
	mlx_hook(vars->win, 17, 1L<<0, close_window, vars);
	init_imgs(vars, img);
	put_sprites(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_loop(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
