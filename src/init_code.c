/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:15:10 by gmunoz            #+#    #+#             */
/*   Updated: 2024/09/17 19:07:28 by gmunoz           ###   ########.fr       */
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
	lay->path_up = 0;
	lay->path_down = 0;
	lay->path_left = 0;
	lay->path_right = 0;
	vars->mlx = NULL;
}

int	init_mlx(t_vars *vars, t_map *lay)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->win = mlx_new_window(vars->mlx, lay->n_col * 64, \
		lay->n_row * 64, "Tudi Gaimu");
	if (!vars->win)
	{
		mlx_destroy_display(vars->mlx);
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
        close_window(vars);
    return (0);
}

void	init_imgs(t_vars *vars, t_data *img)
{
    img_err(vars, (void **)&(img->main_char), "sprites/main_char.xpm");
	img_err(vars, (void **)&(img->floor), "sprites/alternative_floor.xpm");
	img_err(vars, (void **)&(img->corner_up_left), "sprites/corner_up_left.xpm");
	img_err(vars, (void **)&(img->corner_up_right), "sprites/corner_up_right.xpm");
	img_err(vars, (void **)&(img->corner_down_left), "sprites/corner_down_left.xpm");
	img_err(vars, (void **)&(img->corner_down_right), "sprites/corner_down_right.xpm");
	img_err(vars, (void **)&(img->wall_up), "sprites/wall_up.xpm");
	img_err(vars, (void **)&(img->wall_down), "sprites/wall_down.xpm");
	img_err(vars, (void **)&(img->wall_left), "sprites/wall_left.xpm");
	img_err(vars, (void **)&(img->wall_right), "sprites/wall_right.xpm");
	img_err(vars, (void **)&(img->inner_wall), "sprites/inner_wall.xpm");
	img_err(vars, (void **)&(img->door_exit), "sprites/door_exit.xpm");
	img_err(vars, (void **)&(img->coin), "sprites/collect.xpm");
	img_err(vars, (void **)&(img->char_in_door), "sprites/char_in_door.xpm");
}
