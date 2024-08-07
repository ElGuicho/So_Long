/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:40 by gmunoz            #+#    #+#             */
/*   Updated: 2024/08/07 14:08:20 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	void	*img2;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		steps;
	int		screen_size;
	t_data	*img;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}
int close_window(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}


int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		printf("number of steps = %d\n", vars->steps);
		vars->steps++;
	}
	return (0);
}
int	animation_hook(int keycode, t_vars *vars)
{
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img2, 1000, 36);
	}
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 64, 36);
	return (0);
}

int main(int argc, char const *argv[])
{
	t_data	img;
	t_vars	vars;
	char	*relative_path = "./char_trial.xpm";
	char	*relative_path2 = "./AnimationSheet_Character.xpm";
	int		img_width;
	int		img_height;

	vars.steps = 1;
	(void)argc;
	(void)argv;
	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
	    printf("mlx_init failed\n");
	    return 1;
	}
	
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Tudi Gaimu");
	if (!vars.win)
	{
	    printf("mlx_new_window failed\n");
	    return 1;
	}
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_hook(vars.win, 17, 1L<<0, close_window, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	if (!img.img)
	{
	    printf("mlx_xpm_file_to_image failed\n");
	    return 1;
	}

	img.img2 = mlx_xpm_file_to_image(vars.mlx, relative_path2, &img_width, &img_height);
	if (!img.img2)
	{
	    printf("mlx_xpm_file_to_image failed\n");
	    return 1;
	}

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.addr)
	{
		printf("mlx_get_data_addr failed\n");
	    return 1;
	}
	vars.img = &img;
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	//mlx_key_hook(vars.win, animation_hook, &vars); the step count doesnt work
	mlx_loop(vars.mlx);
	return 0;
}

/* 
img.img = mlx_new_image(mlx, 1920, 1080);
ft_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
} */


/*
mlx_mouse_hook(vars.win, mouse_hook, &vars);

int mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("Mouse button %d pressed at position %d, %d\n", button, x, y);
	(void)vars;
	return (0);
} */

