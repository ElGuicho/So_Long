/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:40 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/05 19:33:44 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	freee(t_data *img, t_vars *vars, t_map *lay)
{
	if (lay)
	{
		if (lay->map)
			free(lay->map);
		free(lay);
	}
	if (img)
	{
		if (img->main_char)
			free(img->main_char);
		if (img->floor)
			free(img->floor);
		if (img->addr)
			free(img->addr);
		free(img);
	}
	if (vars)
	{
		if (vars->win)
			free(vars->win);
		if (vars->mlx)
			free(vars->mlx);
		free(vars);
	}
}

int main(int argc, char const **argv)
{
	t_data	*img;
	t_vars	*vars;
	t_map	*lay;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
	{
		ft_printf("vars malloc failed\n");
		return (1);
	}
	img = malloc(sizeof(t_data));
	if (img == NULL)
	{
		ft_printf("img malloc failed\n");
		free(vars);
		return (1);
	}
	lay = malloc(sizeof(t_map));
	if (lay == NULL)
	{
		ft_printf("lay malloc failed\n");
		free(img);
		free(vars);
		return (1);
	}
	vars->img = img;
	vars->lay = lay;
	init_vars(vars, lay, img);
	if(create_map(argc, argv, lay) == 1)
	{
		freee(img, vars, lay);
		return (1);
	}
	if (init_mlx(vars, lay) == 1)
	{
		freee(img, vars, lay);
		return (1);
	}
	if(mlx_hook(vars->win, 2, 1L<<0, close_win, vars) == 0)
	{
		//freee(img, vars, lay);
		return (0);
	}
	if(mlx_hook(vars->win, 17, 1L<<0, close_window, vars) == 0)
	{
		//freee(img, vars, lay);
		return (0);
	}
	//mlx_do_sync(vars->mlx);
	if (init_imgs(vars, img) == 1)
	{
		//freee(img, vars, lay);
		return (1);
	}
	//mlx_do_sync(vars->mlx);
	put_sprites(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_loop(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	return 0;
}

/* 
img->addr = mlx_get_data_addr(img->main_char, &img->bits_per_pixel, &img->line_length, &img->endian);
if (!img->addr)
{
	ft_printf("mlx_get_data_addr failed\n");
	close_window(vars);
	//freee(img, vars, lay);
    return (1);
}
*/

/* 
img->main_char = mlx_new_image(mlx, 1920, 1080);
ft_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/

/*
mlx_mouse_hook(vars->win, mouse_hook, &vars);

int mouse_hook(int button, int x, int y, t_vars *vars)
{
	ft_printf("Mouse button %d pressed at position %d, %d\n", button, x, y);
	(void)vars;
	return (0);
}
*/