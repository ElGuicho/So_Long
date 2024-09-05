/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:15:10 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/05 16:10:29 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	init_vars(t_vars *vars, t_map *lay, t_data *img)
{
	img->x = 128;
	img->y = 128;
	vars->steps = 0;
	lay->collect = 0;
	lay->exit = 0;
	lay->player = 0;
	lay->n_row = 0;
	lay->map = NULL;
}

int	init_mlx(t_vars *vars, t_map *lay)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
	    ft_printf("mlx_init failed\n");
		//freee(img, vars, lay);
		return (1);
	}
	ft_printf("lay n_row = %d\n", lay->n_row);
	ft_printf("lay n_col = %d\n", lay->n_col);
	vars->win = mlx_new_window(vars->mlx, lay->n_col * 64, \
		lay->n_row * 64, "Tudi Gaimu");
	if (!vars->win)
	{
		mlx_destroy_display(vars->mlx);
		//free(vars->win);
	    ft_printf("mlx_new_window failed\n");
		//freee(img, vars, lay);
	    return (1);
	}
	return (0);
}

int img_err(t_vars *vars, void **img_ptr, char *img_name)
{
    int img_width;
    int img_height;

    *img_ptr = mlx_xpm_file_to_image(vars->mlx, img_name, &img_width, &img_height);
    if (!(*img_ptr))
	{
        ft_printf("%s failed\n", img_name);
        close_window(vars);
        //freee(img, vars, lay);
        return (1);
    }
    return (0);
}

int init_imgs(t_vars *vars, t_data *img)
{
    if (img_err(vars, (void **)&(img->main_char), "sprites/main_char.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->floor), "sprites/alternative_floor.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->corner_up_left), "sprites/corner_up_left.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->corner_up_right), "sprites/corner_up_right.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->corner_down_left), "sprites/corner_down_left.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->corner_down_right), "sprites/corner_down_right.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->wall_up), "sprites/wall_up.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->wall_down), "sprites/wall_down.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->wall_left), "sprites/wall_left.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->wall_right), "sprites/wall_right.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->inner_wall), "sprites/inner_wall.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->door_exit), "sprites/door_exit.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->coin), "sprites/collect.xpm"))
		return (1);
	if (img_err(vars, (void **)&(img->char_in_door), "sprites/char_in_door.xpm"))
		return (1);
	return (0);
}
